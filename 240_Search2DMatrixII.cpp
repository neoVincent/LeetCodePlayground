240_Search2DMatrixII.cpp

class Solution {
public:
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search
        // initial check
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int r = row-1;
        int c = 0;
        while ( c < col && r >=0)
        {
            if (matrix[r][c] == target) return true;
            
            if (matrix[r][c] > target)
            {
                r--;
            }
            else
            {
                c++;
            }
        }
        
        return false;
    }
};

class Solution {
public:
    
    bool searchRec(vector<vector<int>>& matrix, int left, int up, int right, int down, int target)
    {
        if (left > right || up > down)
            return false;
        else if (target < matrix[up][left] || target > matrix[down][right])
            return false;
        
        int mid = (right-left)/2 +left;
        
        int row = up;
        
        // find the split location
        while(row <= down && matrix[row][mid] <= target)
        {
            if (matrix[row][mid] == target)
                return true;
            else
                row++;
        }
        
        return searchRec(matrix,left,row,mid-1,down,target) || searchRec(matrix,mid+1,up,right,row-1,target);
        
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Divide and conquer
        // initial check
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        return searchRec(matrix,0,0,matrix[0].size()-1,matrix.size()-1,target);
        
    }
};

class Solution {
public:
    
    bool binarySearch(vector<vector<int>>& matrix, int start,bool vertical, int target)
    {
        int left = start;
        int right = vertical?matrix[0].size()-1 : matrix.size()-1;
        
        while(left <= right)
        {
            int mid = (right-left)/2 + left;
            if (vertical)
            {
                if (matrix[start][mid] < target)
                {
                    left = mid + 1;
                }else if (matrix[start][mid] > target)
                {
                    right = mid -1;
                }else
                    return true;
            }else
            {
                if (matrix[mid][start] < target)
                {
                    left = mid + 1;
                }
                else if (matrix[mid][start] > target)
                {
                    right = mid - 1;
                }
                else 
                    return true;
            }
        }
        
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search
        // initial check
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        int shorterDim = min(matrix.size(), matrix[0].size());
        for(int i = 0; i < shorterDim; i++)
        {
            bool verticalFound = binarySearch(matrix,i,true,target);
            bool horizaontalFound = binarySearch(matrix,i,false,target);
            if (verticalFound || horizaontalFound)
                return true;
        }
        return false;
        
    }
};

