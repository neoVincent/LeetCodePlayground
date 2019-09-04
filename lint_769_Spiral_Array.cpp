lint_769_Spiral_Array.cpp
class Solution {
public:
    int dir[5]={0,1,0,-1,0};
    
    /**
     * @param n: a Integer
     * @return: a spiral array
     */
    vector<vector<int>> spiralArray(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        pair<int,int> cur{0,0};
        matrix[0][0] = 1;
        
        for(int i = 2 ; i <= n*n; i++)
        {
            cur = nextPos(cur,matrix);
            if (cur.first == -1 && cur.second == -1)
                break;
            matrix[cur.first][cur.second] = i;
        }
        
        return matrix;
    }
    
    
    int d = 0;
    pair<int,int> nextPos(pair<int,int>& cur, const vector<vector<int>>& matrix)
    {
        if (valid(cur.first + dir[d], cur.second + dir[d+1], matrix))
        {
            return {cur.first + dir[d], cur.second + dir[d+1]};
        }
        else
        {
            d++;
            d %= 4;
            if (valid(cur.first + dir[d], cur.second + dir[d+1], matrix))
                return {cur.first + dir[d], cur.second + dir[d+1]};
            else 
                return {-1,-1};
        }
    }
    
    bool valid(int i, int j, const vector<vector<int>>& matrix)
    {
        if (i < matrix.size() && i >=0 && j < matrix.size() && j >= 0 && matrix[i][j] == 0)
            return true;
        return false;
    }
};