#include <iostream>
#include <set>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 顺序遍历列表，用set类型存储出现过的节点值：若未出现过，则该值放入set中；若出现过，则删除该节点

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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == NULL) { // 考虑空链表的情况
            return head;
        }
        ListNode* p = head;
        set<int> iset;
        iset.insert(head->val);
        while (p->next != NULL) {
            if(iset.find(p->next->val) == std::end(iset)) { // 若找不到
                iset.insert(p->next->val);
                p = p->next;
            } else { // 若已存在
                ListNode* temp = p->next;
                p->next = p->next->next;
                delete temp;
            }
        }
        return head;
    }
};

int main(){
    int list[6] = {1, 2, 3, 3, 2, 1};
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
    struct ListNode * b = a.removeDuplicateNodes(head);
    display(head);

    return 0;
}