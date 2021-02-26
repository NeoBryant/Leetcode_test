#include <iostream>
#include <string>
using namespace std; 

// 统计字符串中所有字符出现次数，若出现次数为奇数的字符数超过一个，则没有回文

class Solution {
    public:
        bool canPermutePalindrome(string s) {
            int arr[128] = {0};
            for (int i = 0; i < s.length(); ++i) {
                arr[int(s[i])] += 1;
            }
            int numOdd = 0;
            for (int i = 0; i < 128; ++i) {
                if (arr[i]%2 == 1) {
                    ++numOdd;
                }
            }
            if (numOdd > 1) {
                return false;
            }
            
            return true;
        }
};




int main(){
    string s1 = "tactcoa";
    // int s2 = 13;
    Solution a;
    bool result = a.canPermutePalindrome(s1);
    cout << result << endl;
    return 0;
}