221_Maximal_Square.cpp

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        // calculate sums by dp
        // trick declare the size(m+1,n+1), to avoid initialization
        vector<vector<int>> sums(m+1,vector<int>(n+1,0));
        
        for(int i = 1; i < m+1; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                sums[i][j] = matrix[i-1][j-1] - '0' 
                    + sums[i-1][j] 
                    + sums[i][j-1] 
                    - sums[i-1][j-1];
            }
        }
        
        // find the square
        int res = 0;
        for(int i = 1; i < m+1; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                for(int k = min(m+1-i,n+1-j); k > 0; k--)
                {
                    int sum = sums[i+k-1][j+k-1] 
                        - sums[i+k-1][j-1] 
                        - sums[i-1][j+k-1] 
                        + sums[i-1][j-1];
                    
                    if (sum == k*k)
                    {
                        res = max(res, sum);
                        break;
                    }
                }
            }
        }
        return res;
        
    }
};


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> sizes(m,vector<int>(n,0));
        
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                sizes[i][j] = matrix[i][j] - '0';
                
                if (i!=0 && j!=0)
                {
                    if (sizes[i][j] == 0) continue;
                    
                    sizes[i][j] = min(min(sizes[i-1][j],sizes[i][j-1]),sizes[i-1][j-1]) + 1;
                }
                
                ans = max(ans, sizes[i][j]*sizes[i][j]);
            }
        }
        
        return ans;
    }
};


