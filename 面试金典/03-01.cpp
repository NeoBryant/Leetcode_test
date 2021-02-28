#include <iostream>

using namespace std;

// 用一个一维数组等分成三个部分分别存储三个栈

class TripleInOne {
private:
    int index[3]; // 记录每个栈栈顶元素的下标
    int *stack; // 用一个数组来存储三个栈，每个栈分别占数组到三分之一
    int size; // 记录每个栈的大小
public:
    TripleInOne(int stackSize) {
        this->size = stackSize;
        this->stack = new int [3 * stackSize];
        this->index[0] = -1;
        this->index[1] = size - 1;
        this->index[2] = 2 * size - 1;
    }
    
    void push(int stackNum, int value) {
        if (this->index[stackNum] < (stackNum + 1) * this->size - 1) { // 若栈未满，则压入元素
            this->stack[++this->index[stackNum]] =  value;
        }
    }
    
    int pop(int stackNum) {
        if (!isEmpty(stackNum)) {
            return this->stack[this->index[stackNum]--];
        } 
        return -1;
    }
    
    int peek(int stackNum) {
        if (!isEmpty(stackNum)) {
            return this->stack[this->index[stackNum]];
        }
        return -1;
    }
    
    bool isEmpty(int stackNum) {
        if (this->index[stackNum] < stackNum * this->size) {
            return true;
        } 
        return false;
    }
};


int main(){
    TripleInOne a(18);

    // a.push(0, 1);
    // a.push(0, 2);
    // a.push(0, 3);
    // cout << a.pop(0) << endl;
    // cout << a.pop(0) << endl;
    // cout << a.pop(0) << endl;
    // cout << a.peek(0) << endl;
    // vector<string> str {"peek", "pop", "isEmpty", "push", "pop", "push", "push", "pop", "push", "push", "isEmpty", "pop", "peek", "push", "peek", "isEmpty", "peek", "pop", "push", "isEmpty", "pop", "peek", "peek", "pop", "peek", "isEmpty", "pop", "push", "isEmpty", "peek", "push", "peek", "isEmpty", "isEmpty", "isEmpty", "isEmpty", "peek", "push", "push", "peek", "isEmpty", "peek", "isEmpty", "push", "push", "push", "peek", "peek", "pop", "push", "push", "isEmpty", "peek", "pop", "push", "peek", "peek", "pop", "isEmpty", "pop", "peek", "peek", "push", "push"};
    // [1], [2], [1], [2, 40], [2], [0, 44], [1, 40], [0], [1, 54], [0, 42], [0], [1], [1], [0, 56], [2], [0], [2], [2], [1, 15], [1], [1], [0], [2], [0], [0], [1], [0], [0, 32], [0], [0], [0, 30], [2], [1], [1], [0], [0], [0], [0, 56], [1, 40], [2], [0], [0], [0], [2, 11], [0, 16], [0, 3], [2], [0], [2], [0, 39], [0, 63], [1], [2], [0], [2, 36], [1], [0], [2], [1], [0], [1], [2], [0, 8], [0, 38]]

    cout << a.peek(1) << endl;
    cout << a.pop(2) << endl;
    cout << a.isEmpty(1) << endl;
    a.push(2, 44);


    return 0;
}