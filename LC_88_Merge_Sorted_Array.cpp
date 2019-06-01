LC_88_Merge_Sorted_Array.cpp

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        # apply the merge part of merge sort
        
        # initialization check
        if (n == 0) return;
        if (m == 0) 
        {
            nums1 = nums2;
            return;
        }
        
        vector<int> merged(m+n);
        nums1[m] = INT_MAX; // This trick can avoid final element check
        nums2.push_back(INT_MAX);
        int i = 0;
        int j = 0;
        for(int m = 0; m < merged.size(); m++)
        {
            if (nums1[i] <= nums2[j])
            {
                merged[m] = nums1[i];
                i++;
            }
            else
            {
                merged[m] = nums2[j];
                j++;
            }
        }
        
        nums1 = merged;
    }
};