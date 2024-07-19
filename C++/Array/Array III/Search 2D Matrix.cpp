\\ https://leetcode.com/problems/search-a-2d-matrix/description/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int low = 0, high = matrix.size() * matrix[0].size() - 1;
       int mid, i , j, m = matrix[0].size();
       while(low <= high)
       {
           mid = (low + high) / 2;
           i = mid / m; j = mid % m;
           if(matrix[i][j] == target)
           {
               return true;
           }
           else if(matrix[i][j] > target)
           {
               high = mid - 1;
           }

           else
           {
               low = mid + 1;
           }
       }

       return false; 
    }
};
