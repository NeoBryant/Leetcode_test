#include <iostream>
#include <vector>
using namespace std;

// 设置快慢指针，快指针步频为2，慢指针步频为1
// 若有回路，则快慢指针一定会相遇于某节点
// 该相遇节点到回路开始节点的距离 与 头节点到回路开始节点到距离相等 ，该距离值即为回路外节点个数

/*
快慢指针方法证明：

设环外节点个数为x，环内节点个数为y，慢指针经过m步，到达的节点索引为：(m-x)%y+x，
快指针即为：(2m-x)%y+x，相遇满足： (m-x)%y+x = (2m-x)%y+x => m = (k1-k2)*y 
---------------------------------------------------------- 
(1) 再假设慢指针再经过n步到达环入口，有： (m+n-x)%y+x = x =>(m+n-x)%y = 0 
由(1)得 (n-x)%y = 0 =>即相遇后慢指针最快经过x步到达环入口，即为所求
 */

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
    ListNode *detectCycle(ListNode *head) {
        // 设置快慢指针
        ListNode *fast = head, *slow = head;
        // 判断是否有循环
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                fast = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
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