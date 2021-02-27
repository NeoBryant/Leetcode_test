#include <iostream>

using namespace std;

// 设指针p、q，q在p的后第k-1个节点，p和q都以1的步频向后遍历，当q指向最后一个节点时，p指向倒数第k个节点


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
    int kthToLast(ListNode* head, int k) {
        ListNode* p = head, *q = head;
        for (int i = 0; i < k-1; ++i) {
            if (q->next != NULL) {
                q = q->next;
            }
        }
        while (q->next != NULL) {
            q = q-> next;
            p = p->next;
        }
        return p->val;
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

    Solution a;
    int b = a.kthToLast(head, 2);
    cout << b << endl;

    return 0;
}