#include "test_runner.h"
#include "profile.h"

#include <map>
#include <string>
#include <iterator>
#include <future>
using namespace std;

struct Stats {
  map<string, int> word_frequences;

  void operator += (const Stats& other) {
    for (const auto& [word, freq] : other.word_frequences) {
      word_frequences[word] += freq;
    }
  }
};

vector<string> Split(const string& line) {
  // http://en.cppreference.com/w/cpp/iterator/istream_iterator
  istringstream line_splitter(line);
  return {istream_iterator<string>(line_splitter), istream_iterator<string>()};
}

Stats ExploreLine(const set<string>& key_words, const string& line) {
  Stats stat;
  for (const auto& word : Split(line)) {
    if (key_words.count(word) > 0) {
      stat.word_frequences[word]++;
    }
  }

  return stat;
}

Stats ExploreKeyWordsSingleThread(
  const set<string>& key_words, istream& input
) {
  Stats result;
  for (string line; getline(input, line);) {
    result += ExploreLine(key_words, line);
  }
  return result;
}

Stats ExploreBatch(
  const set<string>& key_words, vector<string> strings
) {
  Stats result;
  for (string line : strings) {
    result += ExploreLine(key_words, line);
  }
  return result;
}

/**
 * Определяем некоторое рахумное количество строк, при к-ром произойдет распараллеливание.
 * Если решили распараллеливать, то перемещаем все что накопилось в функцию обработки и резервируем заново размер.
 * Далее проверяем контейнер строк и дообрабатываем остаток.
 */
Stats ExploreKeyWords(const set<string>& key_words, istream& input) {
  vector<string> batch;
  vector<future<Stats>> futures;
  constexpr size_t LINES_COUNT_FOR_THREAD = 5000;
  batch.reserve(LINES_COUNT_FOR_THREAD);
  
  for (string line; getline(input, line);) {
    batch.push_back(move(line));
    if (batch.size() >= LINES_COUNT_FOR_THREAD) {
      futures.push_back(
        async(ExploreBatch, ref(key_words), move(batch))
      );
      batch.reserve(LINES_COUNT_FOR_THREAD);
    }
  }

  Stats result;
  if (not batch.empty()) {
    result = ExploreBatch(key_words, move(batch));
  }

  for (auto& f : futures) {
    result += f.get();
  }

  return result;
}

void TestBasic() {
  const set<string> key_words = {"yangle", "rocks", "sucks", "all"};

  stringstream ss;
  ss << "this new yangle service really rocks\n";
  ss << "It sucks when yangle isn't available\n";
  ss << "10 reasons why yangle is the best IT company\n";
  ss << "yangle rocks others suck\n";
  ss << "Goondex really sucks, but yangle rocks. Use yangle\n";

  const auto stats = ExploreKeyWords(key_words, ss);
  const map<string, int> expected = {
    {"yangle", 6},
    {"rocks", 2},
    {"sucks", 1}
  };
  ASSERT_EQUAL(stats.word_frequences, expected);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestBasic);
}
