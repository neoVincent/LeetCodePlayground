#include <QCoreApplication>
#include <iostream>
#include <algorithm>

using namespace std;

struct Tries
{
    bool isWord;
    Tries* word[26];

    Tries():isWord(false)
    {
        //[begin,end)
        fill(word,word+26,nullptr);
    }

};


class WordDictionary {
public:
    /** Initialize your data structure here. */

    Tries root;

    WordDictionary()
    {
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
      Tries* cur = &root;
      for(char c : word)
      {
          int index = c-'a';
          if (!cur->word[index])
          {
              cur->word[index] = new Tries();
          }
          cur = cur->word[index];

      }
      cur->isWord = true;
    }

    bool search(string& word, int pos, Tries* node)
    {
      if (pos == word.size() )
      {
          return node->isWord;
      }

      if (word[pos] == '.')
      {
          for(int i = 0; i < 26 ; i++)
          {
              //search function in the conditin, means at least found one !!!
              if (node->word[i] != nullptr && search(word,pos+1,node->word[i]))
              {
                  return true;
              }
          }
          return false;
      }
      return node->word[word[pos]-'a'] != nullptr ? search(word,pos+1,node->word[word[pos]-'a']) : false;
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
      return search(word,0,&root);
    }
};
/*
void addWord(string word) {
        words[word.size()].insert(word);
    }
    bool search(string word) {
        auto it = words.find(word.size());
        if( it == words.end())
            return false;
        if(it->second.find(word) != it->second.end()) {
            return true;
        }
        auto match = [&](auto const & s) {
            for(auto i = 0ul; i < word.size(); ++i) {
                if ( word[i] != '.' && word[i] != s[i])
                    return false;
            }
            return true;
        };
        return find_if(it->second.begin(), it->second.end(), match) != it->second.end();
    }
private:
    unordered_map<int, unordered_set<string>> words; // all words with same length goes to a set!
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
*/
