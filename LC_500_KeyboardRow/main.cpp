#include <QCoreApplication>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;



vector<string> findWords(vector<string>& words)
{
    //build dictory
    unordered_map<char,int> keyMap;
    keyMap['q'] = 1;
    keyMap['w'] = 1;
    keyMap['e'] = 1;
    keyMap['r'] = 1;
    keyMap['t'] = 1;
    keyMap['y'] = 1;
    keyMap['u'] = 1;
    keyMap['i'] = 1;
    keyMap['o'] = 1;
    keyMap['p'] = 1;
    keyMap['a'] = 2;
    keyMap['s'] = 2;
    keyMap['d'] = 2;
    keyMap['f'] = 2;
    keyMap['g'] = 2;
    keyMap['h'] = 2;
    keyMap['j'] = 2;
    keyMap['k'] = 2;
    keyMap['l'] = 2;
    keyMap['z'] = 3;
    keyMap['x'] = 3;
    keyMap['c'] = 3;
    keyMap['v'] = 3;
    keyMap['b'] = 3;
    keyMap['n'] = 3;
    keyMap['m'] = 3;

    int row;
    vector<string> res;
    for(string word : words)
    {
        row = -1;
        string tmp = word;
        std::transform(tmp.begin(), tmp.end(), tmp.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c);});
        for (char c: tmp)
        {
            if (row == -1)
            {
                row = keyMap[c];
            }
            else if ( row != keyMap[c])
            {
                row = -1;
                break;
            }
        }

        if (row != -1)
        {
            res.push_back(word);
        }
    }
    return res;


//    vector<string> str = {"QWERTYUIOPqwertyuiop", "ASDFGHJKLasdfghjkl", "ZXCVBNMzxcvbnm"};
//            vector<string> res;

//            for(int i = 0; i < words.size(); i++)
//            {
//                string s;
//                if(str[0].find(words[i][0]) != -1)
//                    s = str[0];
//                else if(str[1].find(words[i][0]) != -1)
//                    s = str[1];
//                else if(str[2].find(words[i][0]) != -1)
//                    s = str[2];

//                int j = 0;
//                for( j = 0; j < words[i].length(); j++)
//                    if(s.find(words[i][j]) == string::npos)
//                        break;

//                if(j == words[i].length())
//                    res.push_back(words[i]);

//            }

//            return res;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<string> words{"Hello","Alaska","Dad","Peace"};
    auto res = findWords(words);
    for (auto ele : res)
    {
        cout << ele << " ";
    }
    return a.exec();
}
