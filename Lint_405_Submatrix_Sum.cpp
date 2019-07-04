Lint_405_Submatrix_Sum.cpp
class Solution {
public:
    /*
     * @param matrix: an integer matrix
     * @return: the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = m == 0 ? 0:matrix[0].size();
        
        // up
        for(int i = 0; i < m ; i++)
        {
            // bottom
            for(int k = i; k < m; k++)
            {
                int layerSum = 0;
                unordered_map<int,int> hash;
                hash[0] = -1;
                for(int y = 0; y < n; y++)
                {
                    for(int x = i; x <= k; x++)
                    {
                        layerSum +=matrix[x][y];                        
                    }
                    if (hash.find(layerSum) != hash.end())
                    {
                        return {{i,hash[layerSum]+1},{k,y}};
                    }
                    hash[layerSum] = y;
                }
            }
        }
        return {{0,0},{0,0}};
    }
};