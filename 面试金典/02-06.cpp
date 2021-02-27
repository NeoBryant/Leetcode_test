#include <iostream>
#include <vector>

using namespace std;

// 用递归的方法，将最后一个节点与第一个节点比较，然后倒数第二个与第二个比较，依次比较

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


void display(ListNode* head){
    ListNode* p = head;
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode *root;
    bool flag = true;
    void dfs(ListNode *p){
        if(p == NULL){ // 从后往前
            return ;
        }
        dfs(p->next); // 找到最后一个节点
        if(p->val != root->val){
            flag = false;
        }
        root = root->next; // 从前往后
    }
    bool isPalindrome(ListNode* head) {
        root = head;
        dfs(head);
        return flag;
    }
};

int main(){

    int list[7] = {1, 2, 3, 4, 3, 2, 1};
    ListNode *head;
    ListNode *p;
    for (int i = 0; i < 7; ++i) {
        ListNode* temp = new ListNode(list[i]);
        if (i == 0) {
            head = temp;
            p = head;
        } else {
            p->next = temp;
            p = temp;
        }
    }

    Solution a;

    display(head);
    bool b = a.isPalindrome(head);
    cout << b << endl;


    return 0;
}