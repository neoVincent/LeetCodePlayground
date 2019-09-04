289_Game_of_Life.cpp

class Solution {
public:
    int neighbors[3] = {0,1,-1};
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> copy(board);
        
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i < copy.size(); i++)
        {
            for(int j = 0; j < copy[0].size(); j++)
            {
                int liveNeighbors = 0;
                for(int m = 0; m < 3; m++)
                {
                    for(int n = 0; n < 3; n++)
                    {
                        if (!(neighbors[m] == 0 && neighbors[n] == 0))
                        {
                            int r = i + neighbors[m];
                            int c = j + neighbors[n];
                            if (r >= 0 && r < row && c >= 0 && c < col && copy[r][c] == 1)
                            {
                                liveNeighbors++;
                            }
                        }
                    }
                }
                
                if (copy[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3))
                    board[i][j] = 0;
                if (copy[i][j] == 0 && (liveNeighbors == 3))
                    board[i][j] = 1;
            }
        }
    }
};