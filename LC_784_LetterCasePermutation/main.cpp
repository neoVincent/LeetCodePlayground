#include <QCoreApplication>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

void findPermutation(string& S, int start, int end, string prefix, vector<string>& res)
{
    if (start >= end && !prefix.empty())
    {
        res.push_back(prefix);
    }
    else
    {
        if (isalpha(S[start]))
            {
                string prefixlower = prefix + string(1,tolower(S[start]));
                string prefixUpper = prefix + string(1,toupper(S[start]));
                cout << "Prefix lower " << prefixlower << endl;
                cout << "Prefix Upper " << prefixUpper << endl;
                findPermutation(S, start+1,end,prefixlower, res);
                findPermutation(S, start+1,end,prefixUpper, res);
            }
            else
            {
                string prefixDigital = prefix + string(1,S[start]);
                cout << "Prefix Digital  " << prefixDigital << endl;
                findPermutation(S,start+1,end,prefixDigital,res);
            }
        }
    }
}
vector<string> letterCasePermutation(string S)
{
    vector<string> res;
    findPermutation(S,0,S.length(),"",res);
    return res;
}

class Solution {
    vector<string> getVariants(char ch) {
        vector<string> variants;
        variants.push_back(string(1, ch));

        if(isdigit(ch)) {
            return variants;
        } else if(islower(ch)) {
            char upperCased = char(toupper(ch));
            variants.push_back(string(1, upperCased));

        } else {
            char lowerCased = char(tolower(ch));
            variants.push_back(string(1, lowerCased));
        }
        return variants;
    }

    void permuteCase(string str,  vector<string>& perms) {
        // base case
        vector<string> variants = getVariants(str[0]);
        //cout << "Variant sizer is "  << variants.size() << endl;
        if(str.length() == 1) {
            // write to perms a string with str[0]
            for(int i = 0; i < variants.size(); ++i) {
                //cout << "variant is" << variants[i] << endl;
                perms.push_back(variants[i]);
            }
        }

         else {
             permuteCase(str.substr(1), perms);
             vector<string> prepended_perms;
             const int num = perms.size();
             for(int i = 0 ; i < num ; ++i) {
                 for(const auto& variant : variants) {
                     prepended_perms.push_back(variant + perms[i]);
                 }
             }

            perms = prepended_perms;
        }
    }


public:
    vector<string> letterCasePermutation(string S) {
         vector<string> perms;

        if(S.empty()) {
            string str = "";
            perms.push_back(str);
            return perms;
        }

        permuteCase(S, perms);
        return perms;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
