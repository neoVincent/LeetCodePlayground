496_Next_Greater_ElementI.cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // monotonic queue
        if (nums1.size() == 0 || nums2.size() == 0) return {};
        unordered_map<int,int> dict;
        deque<int> q;
        
        for(int i = 0; i < nums2.size(); i++)
        {
            if (q.empty() || q.back() >= nums2[i])
            {
                q.push_back(nums2[i]);
                dict[nums2[i]] = -1;
            }
            else 
            {
                while(!q.empty() && q.back() < nums2[i])
                {
                    dict[q.back()] = nums2[i];
                    q.pop_back();
                }
                q.push_back(nums2[i]);
                dict[nums2[i]] = -1;
            }
        }
        
        vector<int> res;
        for(auto& n : nums1)
        {
            res.push_back(dict[n]);
        }
        return res;
    }
};