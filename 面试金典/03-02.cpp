#include <iostream>
#include <vector>

using namespace std;


// 设置栈和一个记录栈中每个元素及其栈下元素的最小值的栈

class MinStack {
private:
    vector<int> stack; // 栈
    vector<int> min_stack; // 记录每个栈元素及其下面元素的最小值
public:
    /** initialize your data structure here. */
    MinStack() { }
    
    void push(int x) {
        stack.push_back(x);
        if (min_stack.size() == 0) {
            min_stack.push_back(x);
        } else {
            if (min_stack.back() < x) {
                min_stack.push_back(min_stack.back());
            } else {
                min_stack.push_back(x);
            }
        }
    }
    
    void pop() {
        stack.pop_back();
        min_stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min_stack.back();
    }
};

int main(){


    return 0;
}