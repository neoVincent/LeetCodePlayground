#include <QCoreApplication>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
  unordered_map<int,int> udMap;
  for(int i = 0 ; i < nums.size(); i++)
  {
      int complement = target - nums[i];
      if (udMap[complement] > 0)
      {
          return {udMap[complement]-1, i};
      }
      else
      {
          udMap[nums[i]] = i + 1;
      }
  }
  return {-1,-1};
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
