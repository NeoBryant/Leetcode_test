#include <iostream>
#include <vector>

using namespace std;

//  用一个二维数组vector<vector<int> >

class StackOfPlates {
private:
    vector<vector<int> > stack;
    int size;

public:
    StackOfPlates(int cap) {
        size = cap;
    }
    void push(int val) {
        if (size == 0) {  // 若size为0，则无法压栈
            return;
        }
        // cout << stack.back().size() << endl;
        if (stack.size() == 0 || stack.back().size() == size) { // 最后一个盘子堆满了
            vector<int> newstack; // 新建一个盘子堆
            newstack.push_back(val);
            stack.push_back(newstack);
        } else {
            stack.back().push_back(val);
        }
    }
    
    int pop() {
        int result;
        if (stack.size() == 0) {
            result = -1;
        } else {
            result = stack.back().back();
            stack.back().pop_back();
            if (stack.back().size() == 0) {
                stack.pop_back();
            }
        } 
        return result;
    }
    
    int popAt(int index) {
        int result;
        if (index > stack.size() - 1 || stack.size() == 0) {
            result = -1;
        } else {
            result = stack[index].back();
            stack[index].pop_back();
            if (stack[index].size() == 0) {
                stack.erase(stack.begin()+index);
            }
        }
        return result;
    }
};

/*
["StackOfPlates", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop"]
[[0], [2], [8], [56], [1], [39], [40], [44], [63], [11], [38], [20], [55], [25], [14], [11], [1], [20], [16], [6], [18], [3], [39], [45], [2], [22], [64], [6], [30], [39], [3], [19], [63], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], []]
 */

int main(){
    StackOfPlates a(1);

    a.push(1);
    a.push(2);
    cout << a.popAt(1) << endl;
    cout << a.pop() << endl;
    cout << a.pop() << endl;

    return 0;
}