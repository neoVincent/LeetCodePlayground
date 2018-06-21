#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

vector<int> nums = {-2, 0, 3, -5, 2, -1};
unordered_map<string,int> sumMap;

int sumRange(int i, int j)
{
    if (i == j) return nums[i];
    if (j - i == 1) return nums[i] + nums[j];
    string key = to_string(i)+to_string(j);
    if (sumMap.find(key) != sumMap.end()) return sumMap[key];

    int k = (i+j)/2;
    int leftSum = sumRange(i,k);
    int rightSum = sumRange(k,j);
    sumMap[to_string(i)+to_string(k)] = leftSum;
    sumMap[to_string(k)+to_string(j)] = rightSum;

    return leftSum + rightSum -nums[k];
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout <<"Result: "<<endl;
    cout<<sumRange(0,2)<<endl;
    cout<<sumRange(2,5)<<endl;
    cout<<sumRange(0,5)<<endl;
    return a.exec();
}

class NumArray {
public:

    vector<int> sum;
    vector<int> nums;

    NumArray(vector<int> nums) {
    this->nums = nums;
    this->sum = nums;

    for(int i = 1 ; i < sum.size(); i++ )
    {
        sum[i] = sum[i-1] + nums[i];
    }
    }

    int sumRange(int i, int j) {
        return sum[j] - sum[i] + nums[i];
    }
};
