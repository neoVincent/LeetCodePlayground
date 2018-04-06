#include <QCoreApplication>
#include <QDebug>
#include <vector>
#include <iterator>

using namespace std;

vector<int>::iterator bSearch(vector<int>::iterator begin, vector<int>::iterator end, int target, bool fromleft)
{
    auto res = find(begin,end,target);

    if(res != end)
    {
        if (fromleft)
        {
            auto lbound = bSearch(begin, res, target, fromleft);
            if (lbound != res) return lbound;
        }
        else
        {
            //the range for find function is [begin,end)
            auto rbound = bSearch(res + 1, end, target, fromleft);
            if (rbound != end ) return rbound;
        }
    }

    return res;
}


vector<int> searchRange(vector<int>& nums, int target)
{
    auto res = find(nums.begin(),nums.end(),target);

    if (res != nums.end())
    {
        auto lbound = bSearch(nums.begin(),res,target,true);

        //if lbound = res indicate res is the left most bound;
        //Since the index is from zero, no need to plus after index substraction
        int left = lbound < res ? (lbound - nums.begin()) : (res - nums.begin());

        auto rbound = bSearch(res + 1, nums.end(),target, false);


        int right = -1;
        if (rbound == nums.end())
        {
            right = (res - nums.begin());
        }
        else
        {
            right =rbound - nums.begin();
        }

        return {left,right};
    }
    return {-1,-1};
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<int> nums{5,7,7,8,8,10};
    auto res = searchRange(nums,8);
    return a.exec();
}
