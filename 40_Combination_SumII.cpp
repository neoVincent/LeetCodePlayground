40_Combination_SumII.cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // back tracking
        sort(candidates.begin(),candidates.end());
        set<vector<int>> res;
        vector<int> comb;
        backTracking(candidates,0,target,comb,res);
        return {res.begin(),res.end()};
    }
    
    void backTracking(const vector<int>& candidates, int start, int target,vector<int> comb, set<vector<int>>& res)
    {
        //base case
        if (target == 0)
        {
            if (comb.size() > 0)
                res.insert(comb);
            
            return;
        }
        
        //try comb
        for(int i = start; i < candidates.size(); i++)
        {
            if (target >= candidates[i])
            {
                comb.push_back(candidates[i]);
                backTracking(candidates,i+1,target - candidates[i],comb,res);
                comb.pop_back();
            }
        }
    }
};



class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // back tracking
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> comb;
        backTracking(candidates,0,target,comb,res);
        return res;
    }
    
    void backTracking(const vector<int>& candidates, int start, int target,vector<int> comb, vector<vector<int>>& res)
    {
        //base case
        if (target == 0)
        {
            if (comb.size() > 0)
                res.push_back(comb);
            
            return;
        }
        
        //try comb
        for(int i = start; i < candidates.size(); i++)
        {
            if (target < candidates[i]) return; // already sorted
            if (i > start && candidates[i] == candidates[i-1]) continue;
            comb.push_back(candidates[i]);
            backTracking(candidates,i+1,target - candidates[i],comb,res);
            comb.pop_back();
        }
    }
};