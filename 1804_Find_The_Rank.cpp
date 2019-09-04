1804_Find_The_Rank.cpp
class Solution {
public:
    /**
     * @param scores: two dimensional array
     * @param K: a integer
     * @return: return a integer
     */
    int FindTheRank(vector<vector<int>> &scores, int K) {
        if (K > scores.size()) return -1;
        vector<pair<int,int>> records;
        for(int i = 0 ; i< scores.size(); i++)
        {
            int sum = accumulate(scores[i].begin(),scores[i].end(),0);
            records.push_back({sum,i});
        }
        
        std::sort(records.begin(),records.end(),greater<pair<int,int>>());
        
        return records[K-1].second;
        
    }
};
