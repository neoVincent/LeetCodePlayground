75_Sort Colors.cpp

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // count sort since we already know the maximum num
        vector<int> counter(3,0);
        
        for(int n: nums)
        {
            counter[n]++;
        }
        
        int m = 0;
        for(int i = 0; i < counter.size(); i++)
        {
            for(int j = 0; j < counter[i];j++)
            {
                cout << m << endl;
                nums[m++] = i;
            }
                
        }
        
    }
};