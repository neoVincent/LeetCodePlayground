39_Combination_Sum.cpp
class Solution {
public:
    void backTracking(int sum, int target, vector<int> ans, vector<vector<int>>& res, const vector<int>& candidates, int index)
    {
        if (sum == target)
        {
            res.push_back(ans);
            return ;
        }
        
        for( int i = index; i < candidates.size(); i++)
        {
            int num = candidates[i];
            if (sum + num <= target)
            {
                ans.push_back(num);
                backTracking(sum+num, target, ans,res,candidates, i);
                ans.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        if (candidates.size() == 0) return {};
        
        vector<vector<int>> res;
        backTracking(0,target,{},res,candidates,0);        
        
        return res;
    }
};