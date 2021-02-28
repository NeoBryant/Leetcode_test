#include <iostream>
#include <vector>

using namespace std;

// 每次push一个元素就进行排序，借助一个临时栈来依次存放栈中元素，直到压栈值到合适到位置插入，再将临时栈中元素换回栈中

class SortedStack {
private:
    vector<int> stack;
    vector<int> temp;
public:
    SortedStack() { }
    
    void push(int val) {
        if (isEmpty()) {
            stack.push_back(val);
        } else {
            // 将栈中元素依次压入临时栈中，直到找到val该插入到位置
            while (stack.size() > 0 && val > stack.back()) {
                temp.push_back(stack.back());
                stack.pop_back();
            }
            stack.push_back(val); // 插入栈
            // 将临时栈中元素依次放回栈中
            while (temp.size() > 0) {
                stack.push_back(temp.back());
                temp.pop_back();
            }
        }
    }
    
    void pop() {
        if (!isEmpty()) {
            stack.pop_back();
        }
    }
    
    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return stack.back();
    }
    
    bool isEmpty() {
        if (stack.size() == 0) {
            return true;
        }
        return false;
    }
};

int main() {
    SortedStack a;
    a.push(1);
    a.push(2);
    a.push(3);
    cout  << a.peek() << endl;
    a.pop();
    cout << a.peek() << endl;

    return 0;
}