#include <QCoreApplication>
#include <vector>
#include <QDebug>

/**
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * Note:
 * You may assume that nums1 has enough space
 * (size that is greater or equal to m + n) to hold additional elements from nums2.
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 */

using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<int> nums1 { 1,2,4,6,7 };
    vector<int> nums2 { 3,4,8,9 };
    merge(nums1,5,nums2,4);
    for(int t: nums1)
        qDebug() << t << ", ";

    return a.exec();
}

 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
 {
     vector<int> temp;
     int i = 0;
     int j =0;
     while(i < m && j < n)
     {
         if (nums1[i] < nums2[j])
         {
             temp.push_back(nums1[i++]);
         }
         else
         {
             temp.push_back(nums2[j++]);
         }
     }

     while(i < m)
     {
         temp.push_back(nums1[i++]);
     }

     while(j < n)
     {
         temp.push_back(nums2[j++]);
     }

     nums1.swap(temp);

     //other solutions
     //hint What if you fill the longer array from the end instead of start ?
#if 0
    int i = m - 1, j = n - 1, tar = m + n - 1;
    while (j >= 0)
    {
        nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }
#endif
 }
