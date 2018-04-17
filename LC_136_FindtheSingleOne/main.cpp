#include <QCoreApplication>
#include <unordered_map>
#include <vector>
#include <QDebug>

using namespace std;

int singleNumber(vector<int>& nums)
{
    if (nums.size() == 1) return nums[0];

    sort(nums.begin(),nums.end());
    for(int i == 0 ; i < nums.size();  )
    {
        if (i = nums.size() - 1) return nums[i];

        if (nums[i] == nums[i+1])
        {
            i += 2;
            continue;
        }
        else
        {
            return nums[i];
        }

    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<int> nums{2,2,1};
    qDebug() << singleNumber(nums) << endl;
    return a.exec();
}
