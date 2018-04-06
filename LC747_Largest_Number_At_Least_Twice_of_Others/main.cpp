#include <QCoreApplication>
#include <QDebug>
/*
 * In a given integer array nums, there is always exactly one largest element.
 * Find whether the largest element in the array is at least twice as much as every other number in the array.
 * If it is, return the index of the largest element, otherwise return -1.
*/


int dominantIndex(int* nums, int numsSize);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int nums1[] = {3,6,1,0};
    int nums2[] = {1,0};
    int nums3[] = {0,0,2,3};
    qDebug() << "a: " << dominantIndex(nums1,4);
    qDebug() << "b: " <<dominantIndex(nums2,2);
    qDebug() << "c: "<< dominantIndex(nums3,4);
    return a.exec();
}


int dominantIndex(int* nums, int numsSize)
{
    int p = -1;
    int q = -1;
    int index = 0;
    for (int i = 0 ; i < numsSize ; i++)
    {
        if (nums[i] > p)
        {
            p = nums[i];
            index = i;
        }
        else if (nums[i] > q)
        {
            q = nums[i];
        }

    }

    qDebug() << "q: " << q;
    qDebug() << "p: " << p;
    if (q*2 <= p) return index;
    else return -1;

}
