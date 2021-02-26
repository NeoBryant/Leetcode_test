#include <iostream>
#include <string>
using namespace std; 

// 首先对字符串长度差进行筛选，然后对两种条件进行判断：插入/删除，替换，

class Solution {
public:
    bool oneEditAway(string first, string second) {
        //判断字符串长度是否相差大于一
        string longS, shortS;
        if (first.length() > second.length()) {
            longS = first;
            shortS = second;
        } else {
            longS = second;
            shortS = first;
        }
        if (longS.length() - shortS.length() > 1){
            return false;
        }

        
        int pass = 0;
        if (longS.length() != shortS.length()) {
            //判断是否插入/删除字符
            for (int i = 0, j = 0; i < longS.length() && j < shortS.length(); ++i, ++j) {
                if (longS[i] != shortS[j]) {
                    ++i;                
                    ++pass;
                }
                if (longS[i] != shortS[j]) {
                    return false;
                }
                if (pass > 1) {
                    return false;
                }
            }
        } else {
            //判断是否替换字符
            for (int i = 0, j = 0; i < longS.length() && j < shortS.length(); ++i, ++j) {
                if (longS[i] != shortS[j]) {             
                    ++pass;
                }
                if (pass > 1) {
                    return false;
                }
            }
        }

        return true;
    }
};




int main(){
    string s1 = "teacher";
    string s2 = "bleacher";
    Solution a;
    bool result = a.oneEditAway(s1, s2);
    cout << result << endl;
    return 0;
}