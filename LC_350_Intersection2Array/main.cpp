#include <QCoreApplication>
#include <QDebug>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
    unordered_map<int,int> unorderMap;
    vector<int> res;
    for(int num : nums1) unorderMap[num] = unorderMap[num] + 1;
    for(int num : nums2)
    {
        if(unorderMap[num] > 0)
        {
            res.push_back(num);
            unorderMap[num]--;
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
