#include <QCoreApplication>
#include <vector>
#include <map>
#include <QDebug>
using namespace std;

vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums)
{
    map<int, int> index;
    vector<int> res;
    int i = 0;
    for(int num : nums)
    {
        index[num] = i;
        i++;
    }
    for(int num: findNums)
    {
        auto iter = find_if(nums.begin()+index[num],nums.end(),[num](const int& a){ return a>num;});
        if(iter != nums.end())
        {
            res.push_back(*iter);
        }
        else
        {
            res.push_back(-1);
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<int> findNums{4,1,2};
    vector<int> nums{1,3,4,2};
    vector<int> res = nextGreaterElement(findNums,nums);
    for(int num:res) qDebug() << num;
    return a.exec();
}
