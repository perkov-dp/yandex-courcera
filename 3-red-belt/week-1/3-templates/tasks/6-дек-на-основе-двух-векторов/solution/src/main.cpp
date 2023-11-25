#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Deque {
public:
  explicit Deque() = default;
  
  const bool Empty() const {
    return tail_.empty() && head_.empty();
  }

  const size_t Size() const {
    return tail_.size() + head_.size();
  }

  T& operator[](size_t index) {
    if (index > head_.size()) {
      return tail_[index - head_.size()];
    }
    return head_[head_.size() - index - 1];
  }

  const T& operator[](size_t index) const {
    if (index > head_.size()) {
      return tail_[index - head_.size()];
    }
    return head_[head_.size() - index - 1];
  }

  T& at(size_t index) {
    if (index >= Size()) {
      throw out_of_range("Index is out of range");
    }
    if (index > head_.size()) {
      return tail_[index - head_.size()];
    }
    return head_[head_.size() - index - 1];
  }

  const T& at(size_t index) const {
    if (index > head_.size()) {
      return tail_[index - head_.size()];
    }
    return head_[head_.size() - index - 1];
  }

  T& Front() {
    return head_.empty() ? tail_.front() : head_.back();
  }

  const T& Front() const {
    return head_.empty() ? tail_.front() : head_.back();
  }

  T& Back() {
    return tail_.empty() ? head_.front() : tail_.back();
  }

  const T& Back() const {
    return tail_.empty() ? head_.front() : tail_.back();
  }

  void PushFront(const T& el) {
    head_.push_back(el);
  }

  void PushBack(const T& el) {
    tail_.push_back(el);
  }

private:
  vector<T> head_;
  vector<T> tail_;
};

int main() {
  return 0;
}
