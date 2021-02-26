#include <iostream>

using namespace std; 

// 统计两个字符串各字符出现次数，然后比较每个字符出现次数是否相同，若都相同则可以

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.length() != s2.length()){
            return false;
        }
        int arr1[128] = {0};
        int arr2[128] = {0};

        for (int i = 0; i < s1.length(); ++i) {
            arr1[int(s1[i])] += 1;
            arr2[int(s2[i])] += 1;
        }

        for (int i = 0; i < 128; ++i){
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }
};


int main(){
    string s1 = "abc";
    string s2 = "bad";
    Solution a;
    bool result = a.CheckPermutation(s1,  s2);
    if (result) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}