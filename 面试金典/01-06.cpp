#include <iostream>
#include <string>
using namespace std; 

// 先顺序统计每个字符出现次数，然后压缩，最后比较长短

class Solution {
public:
    string compressString(string S) {
        string arrChar = "";
        int arrCount[50000] = {0};

        bool isChanged = true; // 记录该字符与上一个字符是否相同
        for (int i = 0; i < S.length(); ++i) {
            if (i == 0 || S[i] != S[i-1]) { // 若不同或首字符
                arrChar += S[i];
                arrCount[arrChar.length()-1] = 1;
            } else { // 若相同
                arrCount[arrChar.length()-1] += 1;
            }
        }
        string result = "";
        for (int i = 0; i < arrChar.length(); ++i) {
            // arrChar.insert(i+1, to_string(arrCount[i]));
            result += arrChar[i] + to_string(arrCount[i]);
        }
        if (result.length() >= S.length()) {
            return S;
        } 

        return result;
    }
};



int main(){
    string s1 = "abbccd";
    // int s2 = 13;
    Solution a;
    string result = a.compressString(s1);
    cout << result << endl;
    return 0;
}