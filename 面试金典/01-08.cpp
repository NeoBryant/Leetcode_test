#include <iostream>
#include <string>
#include <vector>

using namespace std; 

// 先统计0出现的行号和列号，再将对应行和列都清零

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        int rs = matrix.size(); // 行数
        int cs = matrix[0].size(); // 列数
        vector<int> row; // 行
        vector<int> col; // 列
        // 找到所有零的位置, 包括行和列
        for (int i = 0; i < rs; ++i) {
            for (int j = 0; j < cs; ++j){
                if (matrix[i][j] == 0) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        // 行清零
        for (int i = 0; i < row.size(); ++i) {
            for (int j = 0; j < cs; ++j) {
                matrix[row[i]][j] = 0;
            }
        }
        // 列清零
        for (int j = 0; j < col.size(); ++j) {
            for (int i = 0; i < rs; ++i) {
                matrix[i][col[j]] = 0;
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
    matrix[1][1] = 0;
    
    Solution a;

    for (int i = 0; i < 3; ++i) {
       for (int j = 0; j < 3; ++j) {
           cout << matrix[i][j] << " ";
       }
       cout << endl;
    }
    cout << endl;

    a.setZeroes(matrix);
    for (int i = 0; i < 3; ++i) {
       for (int j = 0; j < 3; ++j) {
           cout << matrix[i][j] << " ";
       }
       cout << endl;
    }
    return 0;
}