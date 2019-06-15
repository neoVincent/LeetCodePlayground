378_Kth_Smallest_Elem_Sorted_Matrix.cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.size() == 0 || k == 0) 
            return -1;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        typedef pair<int,int> Pos;
        typedef pair<int,Pos> ElemType;
        
        priority_queue<ElemType,vector<ElemType>,greater<ElemType>> heap;
        
        heap.push({matrix[0][0],{0,0}});
        visited[0][0] = true;
        
        for(int i = 1; i < k; i++)
        {
            ElemType t = heap.top();
            heap.pop();
            
            int x = t.second.first;
            int y = t.second.second;
            
            if(x+1 < m && !visited[x+1][y])
            {
                heap.push(ElemType(matrix[x+1][y],Pos(x+1,y)));
                visited[x+1][y] = true;
            }
            
            if (y + 1 < n && !visited[x][y+1])
            {
                heap.push(ElemType(matrix[x][y+1],Pos(x,y+1)));
                visited[x][y+1] = true;
            }
        }
        
        return heap.top().first;   
    }
};
