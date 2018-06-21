#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int maxSubArray(vector<int>& nums)
{
    if (nums.size() == 1) return nums[0];
    vector<int> sum(nums.size());
    sum[0] = nums[0];
    int res = sum[0];
    for(int i = 1; i < nums.size(); i++)
    {
        sum[i] = max(sum[i-1] + nums[i],nums[i]);
        if (sum[i] > res) res = sum[i];
    }
    return res;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<int> nums{-1,-2};
    cout << "Result: " << maxSubArray(nums) <<endl;
    return a.exec();
}
