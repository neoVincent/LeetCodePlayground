#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int rob(vector<int>& nums)
{
    //bottom up
    if (nums.size() < 2 ) return nums[0];

    vector<int> sums(nums.size());


    sums[0] = nums[0];
    sums[1] = max(sums[0],nums[1]);
    for(int i = 2 ; i< nums.size() ; i++)
    {
        sums[i] = max(sums[i-1],sums[i-2]+nums[i]);
    }
    return sums[nums.size()-1];
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<int> nums{2};
    cout<<"Result: " << rob(nums) <<endl;
    return a.exec();
}
