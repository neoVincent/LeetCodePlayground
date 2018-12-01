#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int dp(vector<int>& nums, int n, vector<int>& mem)
{
    // top down
    if (n >= 0)
    {
        mem[n] = max(dp(nums,n-1,mem), dp(nums,n-2,mem) + nums[n]);
        return mem[n];
    }
    return 0;
}

int rob(vector<int>& nums) {
    vector<int> mem(nums.size(),-1);
    return dp(nums,nums.size()-1,mem);
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<int> nums{2};
    cout<<"Result: " << rob(nums) <<endl;
    return a.exec();
}


//bottom up
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0 ) return 0;
        vector<int> record(nums.size() + 2);
        record[0] = 0;
        record[1] = 0;
        for(int i = 2 ; i < record.size(); ++i)
        {
            record[i] = max(record[i-1], record[i-2] + nums[i-2]);
        }
        return record[nums.size()+1];
    }


};
