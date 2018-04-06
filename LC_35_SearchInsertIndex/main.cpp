#include <QCoreApplication>
#include <QDebug>
#include <vector>

using namespace std;
int searchInsert(vector<int>& nums, int target)
{
    int begin = 0;
    int end = nums.size() - 1;
    int mid = (begin + end ) / 2;
    while(begin < end)
    {
        if (nums[mid] < target)
        {
            begin = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (begin + end ) / 2;
    }

    if(nums[begin] >= target) return begin;
    else return begin + 1;

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
