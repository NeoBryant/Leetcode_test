#include <iostream>
#include <string>
#include <vector>

using namespace std; 

// 顺时针旋转45度 = 先沿主对角线对折，再左右对折

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int size = matrix.size();
        // 主对角线对折
        for (int i = 1; i < size; ++i){
            for (int j = 0; j < i; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        // 左右对折
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < ceil((float)size/2); ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][size-j-1];
                matrix[i][size-j-1] = temp;
            }
        }
    }
};




int main(){
    vector<int> row1(3, 1);
    vector<int> row2(3, 2);
    vector<int> row3(3, 3);
    vector<vector<int> > matrix;
    
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    // int s2 = 13;

    Solution a;

    // for (int i = 0; i < 3; ++i) {
    //    for (int j = 0; j < 3; ++j) {
    //        cout << matrix[i][j] << " ";
    //    }
    //    cout << endl;
    // }
    // cout << endl;

    a.rotate(matrix);
    for (int i = 0; i < 3; ++i) {
       for (int j = 0; j < 3; ++j) {
           cout << matrix[i][j] << " ";
       }
       cout << endl;
    }
    return 0;
}