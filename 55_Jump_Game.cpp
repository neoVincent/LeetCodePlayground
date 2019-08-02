55_Jump_Game.cpp

class Solution {
public:
    // greedy, find the range 
    // is feasible
    bool canJump(vector<int>& nums) {
        
        if (nums.size() == 0) return false;
        
        int farthest = nums[0];             
        for(int i = 0; i < nums.size(); i++)
        {
            if (i <= farthest && nums[i]+i > farthest)
            {
                farthest = nums[i]+i;
            }
        }
        return farthest >= nums.size()-1;
    }
};


class Solution {
public:
    // backtracking
    bool canJump(vector<int>& nums) {
        return backTracking(nums,0);
    }
    
    bool backTracking(const vector<int>& nums, int start)
    {
        // base case
        if (start >= nums.size()-1)
        {
            return true;
        }
        
        int size = nums.size();
        int furthest = min(start + nums[start], size-1);
        for(int i = start+1; i<= furthest; i++)
        {
            if(backTracking(nums,i))
                return true;
        }
        return false;
    }
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        // const int n = nums.size();
        int farthest = nums[0];
        
        for(int i = 0; i < nums.size(); i++)
        {
            if (i > farthest) break;
            farthest = max(farthest, i + nums[i]);
        }
        return farthest >= nums.size()-1;
    }
};