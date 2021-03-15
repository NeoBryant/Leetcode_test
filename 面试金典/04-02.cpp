#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 递归，二分查找逻辑，将数组的中点创建根节点，然后用数组的左部分和右部分分别调用函数进行递归。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {   // 将数组中点作为当前树的根
        if(nums.size() == 0){ 
            return NULL;
        }
        int mid = nums.size() / 2;
        TreeNode *root = new TreeNode(nums[mid]);  // 创建根节点
        
        vector<int> left(nums.begin(), nums.end()-(nums.size()-mid)); // 左部分数组
        vector<int> right(nums.begin()+mid+1, nums.end());            // 右部分数组

        root->left = sortedArrayToBST(left); // 递归创建左部分数组的二叉树
        root->right = sortedArrayToBST(right); //递归创建右部分数组的二叉树
        
        return root;
    }
};



int main() {
    Solution s;
    vector<int> a;
    int b[5] = {-10, -3, 0, 5, 9};
    for (int i = 0; i < 5; ++i) {
        a.push_back(b[i]);
    }

    TreeNode* root = s.sortedArrayToBST(a);
    // 层次遍历
    vector<TreeNode*> queue;
    queue.push_back(root);
    while (queue.size() > 0) {
        if (queue[0]->left != NULL) {
            queue.push_back(queue[0]->left);
        } 
        if (queue[0]->right != NULL) {
            queue.push_back(queue[0]->right);
        }
        cout << queue[0]->val << " ";
        queue.erase(queue.begin());
    }
    cout << endl;

    return 0;
}