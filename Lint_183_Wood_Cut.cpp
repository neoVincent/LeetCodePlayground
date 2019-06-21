Lint_183_Wood_Cut.cpp
// while left <= right
class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    bool  ok(vector<int> L, int mid, int k) {
        if (!mid) { 
            return false;
        }
        int cnt = 0;
        int n = L.size();
        for (int i = 0; i < n; ++i){
            cnt += L[i] / mid;
        }
        return cnt >= k;
    }
    int woodCut(vector<int> L, int k) {
        // write your code here
        int l =1, r = 0;
        int n = L.size();
        for (int i = 0; i < n; ++i){
            r = max(r, L[i]);
        }
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (ok(L, mid, k)) { // cnt >= k 保证left取的是在满足条件下的最大值
                l = mid + 1; 
                ans = mid;
            } else{
                r = mid - 1;
            }
        }
        return ans;
    }
};

// while left < right

class Solution {
public:
    int cut(int len, vector<int>& L)
    {
        int res = 0;
        for(int l :L)
        {
            res += l/len;
        }
        return res;
    }
    /**
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &L, int k) {
        if (L.size() == 0) return 0;
        
        int left = 1;
        int right = *max_element(L.begin(),L.end());
        int res = 0;
        while(left < right)
        {
            int mid = (right-left)/2 + left;
            int count = cut(mid,L);
            if (count < k)
                right = mid;
            else
            {
                res = mid;
                left = mid + 1;
            }
        }
        return res;
    }
};
