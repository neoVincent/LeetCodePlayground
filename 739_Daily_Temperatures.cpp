739_Daily_Temperatures.cpp

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        // monotonic queue
        deque<pair<int,int>> q;
        vector<int> res(T.size(),0);
        
        for(int i = 0 ; i < T.size(); i++)
        {
            if (q.empty() || q.back().first >= T[i])
            {
                q.push_back({T[i],i});
            }
            else
            {
                while(!q.empty() && q.back().first < T[i])
                {
                    auto node = q.back();
                    res[node.second] = i - node.second;
                    q.pop_back();
                }
                q.push_back({T[i],i});
            }
        }
        return res;
    }
};