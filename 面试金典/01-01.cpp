#include <iostream>

using namespace std; 

// 创建一个散列表，统计每个字符串出现的次数，然后判断是否有出现次数超过两次的字符

class Solution {
    public:
        bool isUnique(string astr) {
            int arr[128] = {0};

            for (int i = 0; i < astr.length(); ++i) {
                arr[int(astr[i])] += 1;
            }
            
            for (int i = 0; i < 128; ++i) {
                 if (arr[i] > 1) {
                     return false;
                 }
            }

            return true;
        }
};

int main(){
    string s = "leetcode";
    Solution a;
    bool result = a.isUnique(s);
    if (result) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
