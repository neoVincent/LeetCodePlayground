164_Maximum_Gap.cpp
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // initial check
        if (nums.size() == 1 || nums.size() == 0 ) return 0;
        
        // radix sort
        int maxVal = *max_element(nums.begin(), nums.end());
        int exp = 1; // 1,10
        int radix = 10; // base 10 system
        
        vector<int> aux(nums.size());
        
        while(maxVal / exp > 0)
        {
            // count sort
            vector<int> count(radix,0);
            
            // account 
            for(int n : nums)
            {
                // pay attention to the index 
                count[(n/exp)%10]++;
            }
            
            // accumulate the index
            for(int i = 1; i < count.size(); i++)
            {
                count[i] += count[i-1];
            }
            
            // sort
            // Must keep the sort stalbe
            // Interate from the back
            for(int i = nums.size()-1; i>=0; i--)
            {
                count[(nums[i]/exp)%10]--; // pay attention to the index
                aux[count[(nums[i]/exp)%10]] = nums[i];
            }
            
            // update the nums
            for(int i = 0 ; i < aux.size(); i++)
            {
                nums[i] = aux[i];
            }
            
            exp*=10;
        }
            
            
        int res = 0;
        for(int i = 0; i < nums.size()-1;i++)
        {
            res = max(res, abs(nums[i] - nums[i+1]));
        }
        return res;
    }
};