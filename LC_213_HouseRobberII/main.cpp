#include <QCoreApplication>

int rob(vector<int>& nums) {
    if (nums.size() == 0 ) return 0;
    if (nums.size() == 1) return nums[0];
    vector<int> nums1(nums.begin(),nums.end()-1);
    vector<int> nums2(nums.begin()+1,nums.end());
    return max(robUtil(nums1),robUtil(nums2));
}
int robUtil(vector<int>& nums)
{
    if (nums.size() == 0 ) return 0;
    vector<int> record(nums.size() + 2);
    record[0] = 0;
    record[1] = 0;
    for(int i = 2 ; i < record.size(); ++i)
    {
        record[i] = max(record[i-1], record[i-2] + nums[i-2]);
    }
    return record[nums.size()+1];
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
