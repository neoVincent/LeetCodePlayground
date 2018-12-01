#include <QCoreApplication>

#include <algorithm>

using namespace  std;

vector<int> cutTheSticks(vector<int> arr) {
    vector<int> res;
    sort(arr.begin(),arr.end(),greater<int>());
    while(arr.size() > 0)
    {
        res.push_back(arr.size());
        int minLen = arr[arr.size() - 1];
        int i = 0;
        for (; i < arr.size(); i++)
        {
            if (arr[i] == minLen) break;
            else
            {
                arr[i] -= minLen;
            }
        }
        arr.erase(arr.begin()+i, arr.end());
    }
    return res;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
