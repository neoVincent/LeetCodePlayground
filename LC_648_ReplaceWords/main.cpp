#include <QCoreApplication>
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>

using namespace std;

class MyDict
{
public:
    unordered_map<char,MyDict*> child;
    string word;
};


MyDict* buildDictionary(vector<string>& dict)
{
   MyDict* myDict = new MyDict();
   MyDict* preDict = nullptr;
   for(string word : dict)
   {
       for(char chara : word)
       {
           MyDict* charaDic = new MyDict();
           if (preDict == nullptr)
           {
               if(myDict->child[chara] == nullptr)
                   myDict->child[chara] = charaDic;
               else
               {
                   preDict = myDict->child[chara];
                   delete charaDic;
                   continue;
               }
           }
           else
           {
               preDict->child[chara] = charaDic;
           }
           preDict = charaDic;
       }
       preDict->word = word;
       preDict = nullptr;

   }
   return myDict;
}

string replaceWords(vector<string>& dict, string sentence)
{
    MyDict* myDict = buildDictionary(dict);
    MyDict* curDict = myDict;
    string res;

    istringstream ss(sentence);
    string s;
    vector<string> words;
    while (ss >> s) { words.push_back(s); }

    bool matched;
    for(string word : words)
    {

        for(char chara : word)
        {
            if (curDict->child[chara] != nullptr)
            {
                curDict = curDict->child[chara];
                if (curDict->word != "")
                {
                    res.append(curDict->word+" ");
                    matched = true;
                    break;
                }
            }
            else
            {
                res.append(curDict->word !="" ? curDict->word+" " : word+" ");
                matched = true;
                break;
            }
        }
        if (!matched)
        {
            res.append(word+" ");
        }
        curDict = myDict;
        matched = false;
    }

    return res.substr(0,res.size() - 1);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    vector<string> dic = {"a", "aa", "aaa", "aaaa"};
    vector<string> dic = {"ikkbp", "i","rf"};
//    vector<string> dic ={"cat", "bat", "rat"};
//    string sentence = "the cattle was rattled by the battery";
//    string sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
    string sentence = "r";
    cout << replaceWords(dic,sentence) << endl;
    return a.exec();
}

struct TrieNode
{
    bool isRoot;
    TrieNode * children[26];
    TrieNode()
    {
        isRoot = false;
        for(int i=0; i<26; i++)
            children[i] = NULL;
    }
};

//class Trie
//{
//public:
//    Trie()
//    {
//        root=new TrieNode();
//    }

//    void add(string word)
//    {
//        TrieNode * p =root;
//        for(int i=0; i<word.size(); i++)
//        {
//            int index  = word[i]-'a';
//            if(p->children[index]==NULL) p->children[index] = new TrieNode();
//            p = p->children[index];
//        }

//        p->isRoot = true;

//    }

//    string find(string word)
//    {
//        string res;
//        TrieNode * p = root;
//        for(int i=0; i<word.size(); i++)
//        {
//            int index = word[i]-'a';
//            if(p->children[index]==NULL) return "";
//            if(p->children[index])
//            {
//                res.push_back('a'+index);
//                p = p->children[index];
//                if(p->isRoot) return res;
//            }
//        }

//        return "";
//    }
//private:
//    TrieNode * root;
//};

//class Solution {
//public:
//    string replaceWords(vector<string>& dict, string sentence) {
//        string res;
//        Trie tree;
//        for(auto word: dict)
//            tree.add(word);
//        stringstream is(sentence);
//        string token;
//        while(getline(is, token, ' '))
//        {
//            string cand = tree.find(token);
//            if(cand=="") res+=token;
//            else res+=cand;
//            res+=" ";
//        }

//        return res.substr(0, res.size()-1);
//    }
//};
