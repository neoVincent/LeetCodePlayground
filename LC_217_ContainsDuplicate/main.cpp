#include <QCoreApplication>
#include <unordered_map>

using namespace std;

bool containsDuplicate(vector<int>& nums)
{
    unordered_map<int,int> mapper;
    for(int num : nums)
    {
        if (mapper[num] == 0)
        {
            mapper[num] = 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
