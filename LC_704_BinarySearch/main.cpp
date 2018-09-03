#include <QCoreApplication>
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int start, int end, vector<int>& nums, int target)
{
    if (start > end) return -1;
    int mid = (start + end)/2;
    if (target < nums[mid])
    {
        return binarySearch(start, mid-1, nums,target);
    }

    if (target > nums[mid])
    {
        return binarySearch(mid+1, end,nums,target);
    }

    if (target == nums[mid]) return mid;
}

int search1(vector<int>& nums, int target)
{
    return binarySearch(0,nums.size()-1,nums,target);
}

int search(vector<int>& nums, int target)
{
    int low = 0;
    int high = nums.size()-1;
    int mid = low+(high - low) /2;

    while(low <= high)
    {
        if (nums[mid] < target)
        {
            low = mid + 1;
        }
        if (nums[mid] > target)
        {
            high = mid - 1;
        }

        if (nums[mid] == target) return mid;

        mid = low+(high - low) /2;
    }

/*
 * fastest way
int low = 0;
int high = nums.size()-1;
int mid ;

while(low <= high)
{
   mid = low+(high - low) /2;
    if (nums[mid] == target)
    {
        return mid;

    }else
    if (nums[mid] > target)
    {
        high = mid - 1;
    }
    else
        low = mid + 1;

}
*/
    return -1;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 2;
    cout << "Binary search result: " << search(nums,target) << endl;
    return a.exec();
}
