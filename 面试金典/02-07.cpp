#include <iostream>
#include <vector>

using namespace std;

// 首先判断是否有相交节点（若有相交节点，则两列表相交节点及其后点节点都相同），直接判断最后一个节点是否相同
// 通过两链表都长度差来找相交节点

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 判断是否为空节点
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        // 先确定是否相交
        ListNode *p1 = headA, *p2 = headB;
        int len1 = 0, len2 = 0;
        while (p1->next != NULL) {
            p1 = p1->next;
            ++len1;
        }
        while (p2->next != NULL) {
            p2 = p2->next;
            ++len2;
        }
        if (p1 != p2) {
            return NULL; // 没有相交节点
        }

        // 找到相交节点
        if (len1 >= len2) {
            p1 = headA;
            p2 = headB;
            for (int i = 0; i < len1-len2; ++i) {
                p1 = p1->next;
            }
        } else {
            p1 = headB;
            p2 = headA;
            for (int i = 0; i < len2-len1; ++i) {
                p1 = p1->next;
            }
        } 
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
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
    ListNode* b = a.getIntersectionNode(head1, head2);
    display(b);


    return 0;
}