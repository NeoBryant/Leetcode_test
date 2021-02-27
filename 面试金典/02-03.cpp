#include <iostream>

using namespace std;

// 这道题题目描述有点迷惑性，所求函数参数为链表中的某一节点的指针（不是第一或最后一个节点），要求删除该节点
// 将下个节点的值复制到当前节点上，再删除下个节点即可

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
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }
};

int main(){
    int list[6] = {1, 2, 3, 4, 5, 6};
    ListNode *head;
    ListNode *p;
    for (int i = 0; i < 6; ++i) {
        ListNode* temp = new ListNode(list[i]);
        if (i == 0) {
            head = temp;
            p = head;
        } else {
            p->next = temp;
            p = temp;
        }
    }

    display(head);
    Solution a;
    a.deleteNode(head->next->next);
    display(head);


    return 0;
}
