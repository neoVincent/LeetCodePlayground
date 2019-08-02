45_Jump_Game_II.cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        // greedy
        int steps = 0;
        int near = 0;
        int far = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if (i > near)
            {
                steps++;
                near = far;
            }
            far = max(far, i+ nums[i]);
        }
        return steps;
        
    }
};
