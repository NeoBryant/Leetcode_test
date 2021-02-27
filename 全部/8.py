class Solution:
    def myAtoi(self, s: str) -> int:
        result = 0
        # 判断首字符是不是数字或正负号
        if s[0] < '9' and s[0] > '0':
            pass
        elif s[0] == '+':
            pass
        elif s[0] == '-':
            pass
        else: 
            result = 0


        return result


test = Solution()
s = "4193 with words"
print(test.myAtoi(s))

