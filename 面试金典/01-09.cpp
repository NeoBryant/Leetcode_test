#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
如果一个字符串是另一个字符串的旋转，那么它就是在某个特定点上的旋转。例如，字符串waterbottle在3处的旋转意味着在第三个字符处切割waterbottle，并在左半部分（wat）之前放置右半部分（erbottle）
 本质上，我们是在寻找是否有一种方式可以把第一个字符串分成两部分，即x和y，如此一来，第一个字符串就是xy，第二个字符串就是yx。例如，x = wat，y = erbottle。那么，第一个字符串xy = waterbottle，第二个字符串yx = erbottlewat。
 想想前面的提示。再想想当你将erbottlewat与它本身连接会发生什么。你得到了erbottlewaterbottlewat。
 */
// 将s1与s1连接，判断s2是否为其子串

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        string ns = s1 + s1;
        int n = ns.find(s2);
        
        if (n != string::npos) { // 若能找到
            return true;
        }

        return false;
    }
};


int main(){
    string s1 = "waterbottle";
    string s2 = "erbottlewaa";
    Solution a;
    bool result = a.isFlipedString(s1, s2);
    cout << result << endl;
    return 0;
}