#include <iostream>
#include <vector>

using namespace std;

// 设置一个临时栈进行栈元素到倒换

class MyQueue {
private:
    vector<int> stack;  // 栈
    vector<int> temp;   // 临时栈

public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack.push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (empty()) {
            return -1; 
        }
        int result;
        // 将栈中元素依次压栈到临时栈中
        while (stack.size() > 1) {
            temp.push_back(stack.back());
            stack.pop_back();
        }
        result = stack.back();
        stack.pop_back();

        // 将临时栈中元素依次放回栈中
        while (temp.size() > 0) {
            stack.push_back(temp.back());
            temp.pop_back();
        }
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        if (empty()) {
            return -1; 
        }
        int result;
        // 将栈中元素依次压栈到临时栈中
        while (stack.size() > 0) {
            if (stack.size() == 1) {
                result = stack.back();
            }
            temp.push_back(stack.back());
            stack.pop_back();
        }

        // 将临时栈中元素依次放回栈中
        while (temp.size() > 0) {
            stack.push_back(temp.back());
            temp.pop_back();
        }
        return result;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if (stack.size() == 0) {
            return true;
        }
        return false;
    }
};

int main(){
    MyQueue queue;

    queue.push(1);
    queue.push(2);
    cout << queue.peek() << endl;  // 返回 1
    cout << queue.pop() << endl;   // 返回 1
    cout << queue.empty() << endl; // 返回 false

    return 0;
}