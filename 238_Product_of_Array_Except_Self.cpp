238_Product_of_Array_Except_Self.cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> forward(nums.size(),1);
        vector<int> backward(nums.size(),1);
        
        for(int i = 1; i < nums.size(); i++)
        {
            backward[i] = backward[i-1]*nums[i-1];
        }
        
        for(int i = nums.size()-2; i>=0; i--)
        {
            forward[i] = forward[i+1]*nums[i+1];
        }
        
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            res.push_back(forward[i]*backward[i]);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l = 1;
        int r = 1;
        const int n = nums.size();
        vector<int> res(n,1);
        for(int i = 0; i < n; i++)
        {
            res[i] *= l;
            res[n-i-1] *= r;
            l*= nums[i];
            r*= nums[n-i-1];
        }
        return res;
    }
};

