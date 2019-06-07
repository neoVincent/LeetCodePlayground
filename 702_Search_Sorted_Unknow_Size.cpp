702_Search_Sorted_Unknow_Size.cpp

// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:

    int binSearch(const ArrayReader& reader, int left, int right, int target)
    {
        // find mid
        if (left > right || reader.get(left) == 2147483647) return -1;
        
        int mid = (right - left)/2 + left;
        
        while(reader.get(mid) == 2147483647)
        {
            right = mid;
            mid = (right - left)/2 + left;
        }
        
        if (reader.get(mid) == target) return mid;
        
        if (reader.get(mid) > target) 
            return binSearch(reader,left,mid-1,target);
        else
            return binSearch(reader,mid+1,right,target);
        
        return -1;
       
    }
    
    int search(const ArrayReader& reader, int target) {
        // binary search
        
        // find a way to estimate the length
        int len = 1;
        while(reader.get(len) != 2147483647)
            len *=2;
        
        return binSearch(reader,0,len,target);
        
    }
};