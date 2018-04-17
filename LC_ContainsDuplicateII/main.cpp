#include <QCoreApplication>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    unordered_map<int,int> mapper;
    int index = 0;
    for(int elem : nums)
    {
        if (mapper.find(elem) == mapper.end())
        {
            mapper[elem] = index;
        }
        else if (index - mapper[elem] <= k)
        {
            return true;
        }
        else
        {
            mapper[elem] = index;
        }
        index++;
    }
    return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
