#include <cstdlib>
#include <set>
#include <map>
#include <string>
#include <iostream>

using namespace std;


bool areSynonyms (map <string, set <string>> synonyms,
        const string& first_word, const string& second_word)
{
    return synonyms[first_word].count(second_word) == 1;
}

int main(int argc, char** argv) {
    int kol_req = 0;
    cin >> kol_req;
    
    map <string, set <string>> synonyms;
    
    for (int i = 0; i < kol_req; i++)
    {
        string request;
        cin >> request;
        
        if (request == "ADD")
        {
            string first_word, second_word;
            cin >> first_word >> second_word;
            
            // второе слово добавляем в список синонимов первого...
            synonyms[second_word].insert(first_word);
            // и наоборот
            synonyms[first_word].insert(second_word);
        }
        else if (request == "COUNT")
        {
            string word;
            cin >> word;
            
            cout << synonyms[word].size() << endl;
        }
        else if (request == "CHECK")
        {
            string first_word, second_word;
            cin >> first_word >> second_word;

            /*
             * Для того, чтобы быстро проверить, принадлежит ли элемент множеству,
             * можно использовать метод count/
             * По ключу словаря мы обращаемся к множетву
             */
            if (areSynonyms(synonyms, first_word, second_word))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    

    return 0;
}

