42_Trapping_Water.cpp
// Data struct application
// each point, leftmost, rightmost
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        
        int ans = 0;
        int size = height.size();
        
        vector<int> leftMax(size), rightMax(size);
        leftMax[0] = height[0];
        for(int i = 1; i < size; i++)
        {
            leftMax[i] = max(height[i],leftMax[i-1]);
        }
        
        rightMax[size-1] = height[size-1];
        for(int i = size-2; i>=0; i--)
        {
            rightMax[i] = max(height[i],rightMax[i+1]);
        }
        
        for(int i = 1; i < size-1; i++)
        {
            ans+=min(leftMax[i],rightMax[i]) - height[i];
        }
        return ans;
    }
};