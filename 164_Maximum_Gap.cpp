164_Maximum_Gap.cpp

// Radix sort
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

// Bucket sort
class Solution {
public:
    
    class Bucket {
    public:
        bool used = false;
        int minval = numeric_limits<int>::max();
        int maxval = numeric_limits<int>::min();
        
    };
    
    
    int maximumGap(vector<int>& nums) {
        // initial check
        if (nums.size() == 1 || nums.size() == 0 ) return 0;
        
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        
        int bucketSize = max(1,(maxi - mini)/((int)nums.size()-1));
        int bucketNum = (maxi-mini)/bucketSize + 1;
        vector<Bucket> buckets(bucketNum);
        
        for(auto num: nums)
        {
            int bucketIndex = (num-mini)/bucketSize;
            buckets[bucketIndex].minval = min(num,buckets[bucketIndex].minval);
            buckets[bucketIndex].maxval = max(num,buckets[bucketIndex].maxval);
            buckets[bucketIndex].used = true;
        }
        
        int prevBucketMax = mini, maxGap = 0;
        for(auto bucket: buckets)
        {
            if(!bucket.used)
                continue;
            maxGap = max(maxGap, bucket.minval - prevBucketMax);
            prevBucketMax = bucket.maxval;
        }
        
        return maxGap;
    }
};
