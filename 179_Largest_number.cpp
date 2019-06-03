179_Largest_number.cpp
class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
                
        sort(nums.begin(),nums.end(),[](int& lhs, int& rhs){
            string t1 = to_string(lhs)+to_string(rhs);
            string t2 = to_string(rhs)+to_string(lhs);
            return t1>t2;
        });        
        
        // incase all the numbers are zero
        if (nums[0] == 0) return "0";
        
        string res="";
        for(int n :nums)
        {
            res.append(to_string(n));
        }
        
        return res;
    }
};