# from typing import str


# 遍历字符串，中心扩散法
# O(N^2)

class Solution:
    def longestPalindrome(self, s: str) -> str:
        result = ""
        for i in range(0, len(s)):
            ns = self.getSingleStr(s, i)
            if len(ns) > len(result):
                result = ns
        for i in range(0, len(s)-1):
            if s[i] == s[i+1]:
                ns = self.getDoubleStr(s, i)
                if len(ns) > len(result):
                    result = ns

        return result
        
    def getSingleStr(self, s, i): # 得到对应奇数点的最长中心扩散回文串
        ns = s[i]
        j = 1
        while (i-j >= 0 and i+j < len(s)):
            if s[i-j] == s[i+j]:
                ns = s[i-j] + ns + s[i+j]
                j += 1
            else:
                break
        return ns
    
    def getDoubleStr(self, s, i):  # 得到对应偶数点的最长中心扩散回文串
        ns = s[i]+s[i+1]
        j = 1
        while (i - j >= 0 and i + 1 + j < len(s)):
            if s[i - j] == s[i + 1 + j]:
                ns = s[i - j] + ns + s[i + 1 + j]
                j += 1
            else:
                break
        return ns

test = Solution()
a = "cbbd"
print(test.longestPalindrome(a))
