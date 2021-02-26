#include <iostream>
#include <string>
using namespace std; 

// 创建一个新的string，遍历所给string，逐个插入到新string中

class Solution {
public:
    string replaceSpaces(string S, int length) {
        S = S.substr(0, length);
        // 修改字符串
        string nS = "";
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] != ' ') {
                nS += S[i];
            } else {
                nS += "%20";
            }
        }

        return nS;
    }
};

int main(){
    string s1 = "Mr John Smith    ";
    int s2 = 13;
    Solution a;
    string result = a.replaceSpaces(s1,  s2);
    cout << result << endl;
    return 0;
}