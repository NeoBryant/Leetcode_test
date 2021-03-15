#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 用邻接表存储，深度优先遍历
// 邻接矩阵比较耗时

class Solution {
private:
    set<int> visited; // 记录遍历过的节点
    vector<int> wait; // 待访问队列
    vector<vector<int> > matrix; // 邻接表
    int size;

public:
    bool getNext(int v) { // 取得下一个节点，若不能则返回false
        for (int i = 0; i < matrix[v].size(); ++i) {
            if (visited.find(matrix[v][i]) == std::end(visited)) {
                // 若有路径，且未访问过
                wait.push_back(matrix[v][i]); 
                visited.insert(matrix[v][i]);
                // 删除这条边，节约时间
                matrix[v].erase(matrix[v].begin() + i);
                return true;
            }
        }
        return false;
    }

    bool findWhetherExistsPath(int n, vector<vector<int> >& graph, int start, int target) {
        // 生成邻接表
        size = n; // 节点大小
        for (int i = 0; i < n; ++i) {
            vector <int> row;
            matrix.push_back(row);
        }
        for (int i = 0; i < graph.size(); ++i) {
            if (std::find(matrix[graph[i][0]].begin(), matrix[graph[i][0]].end(), graph[i][1]) == matrix[graph[i][0]].end()) {
                // 若未出现过
                matrix[graph[i][0]].push_back(graph[i][1]);
            }
        }
        // 深度优先搜索
        wait.push_back(start);
        visited.insert(start);

        while (wait.size() > 0) {
            if (wait.back() == target) { // 若成功
                return true;
            }
            if (!getNext(wait.back())) { // 若没有下个元素
                wait.pop_back(); 
            }
        }
        return false;
    }
};

int main() {
    Solution a;
    int graph[26][2] = {{0, 1}, {0, 3}, {0, 10}, {0, 18}, {1, 2}, {1, 7}, {1, 11}, {1, 12}, {2, 4}, {2, 5}, {2, 13}, {2, 16}, {3, 6}, {3, 8}, {4, 9}, {5, 17}, {7, 20}, {7, 22}, {8, 10}, {10, 19}, {11, 15}, {13, 14}, {14, 21}, {15, 23}, {19, 24}, {20, 22}};
    vector<vector<int> > b;
    for (int i = 0; i < 26; ++i) {
        vector <int> temp;
        temp.push_back(graph[i][0]);
        temp.push_back(graph[i][1]);
        b.push_back(temp);
    }

    bool d = a.findWhetherExistsPath(25, b, 0, 12);
    cout << d << endl;
    return 0;
}