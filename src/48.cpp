// by watercolor, 2022-08-30

class Solution {
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for(int i = 0; i < n/2; i++) {
            for(int j = 0; j < n-i*2-1; j++) {
                swap(matrix[i][i+j], matrix[n-i-j-1][i]);
                swap(matrix[n-i-j-1][i], matrix[n-i-1][n-i-j-1]);
                swap(matrix[n-i-1][n-i-j-1], matrix[i+j][n-i-1]);
            }
        }

        return;
    }
};
