74_Search2dMatrix.cpp

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        // locate the row
        int row = matrix.size();
        int col = matrix[0].size();
        
        // locate the row
        int left = 0;
        int right = row-1;
        int mid = 0;
        while(left <= right)
        {
            mid = (right-left)/2 + left;
            int midVal = matrix[mid][col-1];
            if (target == midVal)
                return true;
            
            if (target > midVal)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
            
            cout <<"Left " << left << "  Right " << right<<endl;
            
        }
        
        int r = mid;
        if (matrix[mid][col-1] < target && r < row-1)
            r++;
            
        cout << "Row: " << r << endl;
        return binary_search(matrix[r].begin(),matrix[r].end(),target);
    }
};

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int left = 0;        
        int right = row*col-1;
        
        while(left <= right)
        {
            int mid = (right - left)/2 +left;
            int midVal = matrix[mid/col][mid%col];
            
            if ( midVal == target) return true;
            
            if (midVal > target) 
                right = mid-1;
            else
                left = mid+1;
        }
        
        return false;
        
    }
};