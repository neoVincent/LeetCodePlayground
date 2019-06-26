85_MaximaalRec.cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = (m==0)? 0:matrix[0].size();
        
        vector<vector<int>> hist(m,vector<int>(n,0));
        
        for(int col = 0; col < n; col++)
        {
            for(int row = 0 ; row < m; row++)
            {
                if(row == 0)
                {
                    if (matrix[row][col] == '1')
                        hist[row][col] = 1;
                }
                else
                {
                    hist[row][col] = matrix[row][col] == '1'? hist[row-1][col] + 1 : 0;
                }
            }
        }
        
        int maxRec = 0;
        for(int i = 0; i < m; i++)
        {
            maxRec = max(maxRec, largestRecHist(hist[i]));
        }
        return maxRec;
    }
    
    int largestRecHist(vector<int>& hist)
    {
        if (hist.size() == 0) return 0;
        vector<int> myHist = hist;
        myHist.push_back(0);
        stack<int> stk;
        int res = 0;
        for(int i=0; i < myHist.size(); i++)
        {
            if (stk.empty() || myHist[i] >= myHist[stk.top()])
            {
                stk.push(i);
            }
            else 
            {
                while(!stk.empty() && myHist[i] < myHist[stk.top()])
                {
                    int topIdx = stk.top();
                    stk.pop();
                    int width = stk.empty()? i: (i-stk.top() - 1);
                    int height = myHist[topIdx];
                    res = max(res,width*height);
                }
                stk.push(i);
            }
        }
        return res;
    }
};