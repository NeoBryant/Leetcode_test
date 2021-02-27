#include <iostream>

using namespace std;

// 遍历列表：若遇到小于x的节点，就移到头节点前面，并更新头节点；否则继续遍历下一个节点


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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) {
            return head;
        }
        ListNode* p = head;

        while (p->next != NULL) {
            if (p->next->val < x) {
                ListNode* temp = p->next;
                p->next = temp->next;
                temp->next = head;
                head = temp;
            } else {
                p = p->next;
            }
        }
        return head;
    }
};

int main(){

    int list[7] = {3, 5, 8, 5, 10, 2, 1};
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
    ListNode* b = a.partition(head, 5);
    display(b);


    return 0;
}