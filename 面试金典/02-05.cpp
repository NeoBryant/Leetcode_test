#include <iostream>

using namespace std;

// 从个位开始依次进行加分运算，并进位

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* p1 = l1, *p2 = l2, *head = NULL, *q;
        int i1, i2, result, count = 0;

        while (p1 != NULL || p2 != NULL) {
            i1 = (p1 == NULL ? 0 : p1->val);
            i2 = (p2 == NULL ? 0 : p2->val);
            result = i1 + i2 + count;
            count = (result >= 10 ? 1 : 0);
            result = result % 10;
            ListNode* temp = new ListNode(result);
            if (head == NULL) {
                head = temp;
                q = head;
            } else {
                q->next = temp;
                q = temp;
            }

            p1 = (p1 == NULL ? NULL : p1->next);
            p2 = (p2 == NULL ? NULL : p2->next);
        }
        if (count > 0) { // 若最后还有进位
            ListNode* temp = new ListNode(count);
            q->next = temp;
        } 

        return head;
    }
};

int main(){

    int list1[3] = {7, 1, 6}, list2[3] = {5,9,2};
    ListNode *head1, *head2;
    ListNode *p;
    for (int i = 0; i < 3; ++i) {
        ListNode* temp = new ListNode(list1[i]);
        if (i == 0) {
            head1 = temp;
            p = head1;
        } else {
            p->next = temp;
            p = temp;
        }
    }
    for (int i = 0; i < 3; ++i) {
        ListNode* temp = new ListNode(list2[i]);
        if (i == 0) {
            head2 = temp;
            p = head2;
        } else {
            p->next = temp;
            p = temp;
        }
    }

    Solution a;

    display(head1);
    display(head2);
    ListNode* b = a.addTwoNumbers(head1, head2);
    display(b);


    return 0;
}