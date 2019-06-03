220_Contains_Duplicate_III.cpp
class Solution {
public:
    
    int getIndex(long num, long w)
    {
        return num < 0? num/w-1 : num/w;
    }
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // bucket sort
        // k: the index distance
        // t: the value difference
        
        if( t < 0 ) return false;
        
        unordered_map<long,long> bucket;
        int w = (long)t+1; // domian -1-[-t,-1],0-[0,t],1-[t+1,2t+1]...
        int idx = 0;
        for(long n : nums)
        {
            int i = getIndex(n,w);
            cout << i << endl;
            if (bucket.find(i) != bucket.end())
            {
                // cout <<"find i"<<endl;
                // cout << "Bucket i :" << bucket[i] << endl;
                // cout << "Search number: " << n<<endl;
                return true;
            }
            
            
            if(bucket.find(i-1) != bucket.end() && abs(bucket[i-1] - n) <= t)
            {
                // cout <<"find i-1"<<endl;
                // cout << "Bucket i-1 :" << bucket[i-1] << endl;
                // cout << "Search number: " << n<<endl;
                return true;
            }
            
            if(bucket.find(i+1) != bucket.end() && abs(bucket[i+1]-n) <=t )
            {
                // cout <<"find i+1"<<endl;
                // cout << "Bucket i+1 :" << bucket[i+1] << endl;
                // cout << "Search number: " << n<<endl;
                return true;
            }
            
            bucket[i] = n;
            
            // maintain the sliding window
            if (idx >= k ) 
            {
                // cout << "Erase i-k" << (idx-k) << endl;
                bucket.erase(getIndex(nums[idx-k],w));
                
            }
            idx++;
        }
        
        return false;
    }
};