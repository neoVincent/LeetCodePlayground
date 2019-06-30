91_Decode_Ways.cpp

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') return 0;
        
        vector<double> res(s.size(),0);
        res[0] = 1;
        
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] != '0')
                res[i] += res[i-1];
            if (s[i-1] != '0' && stoi(s.substr(i-1,2)) <=26)
                res[i] += (i==1)? 1 : res[i-2]; // nice trick
            if (!res[i]) // unable to decode
                return 0;
        }
        
        return res[s.size()-1];
    }
};


