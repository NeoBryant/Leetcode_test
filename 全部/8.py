class Solution:
    def char2int(self, c:str) -> int:
        result = 0
        if c == '0': result = 0
        elif c == '1': result = 1
        elif c == '2': result = 2
        elif c == '3': result = 3
        elif c == '4': result = 4
        elif c == '5': result = 5
        elif c == '6': result = 6
        elif c == '7': result = 7
        elif c == '8': result = 8
        elif c == '9': result = 9
        return result

    def myAtoi(self, s: str) -> int:
        sign = 1 # 1为正，-1为负
        result = 0  
        # 转化为数字
        isstartcount = False
        for c in s:
            if not isstartcount:
                if (c == ' '):
                    continue
                if c <= '9' and c >= '0':
                    result = self.char2int(c)
                    isstartcount = True
                elif c == '+':
                    isstartcount = True
                elif c == '-':
                    sign = -1
                    isstartcount = True
                else: return 0 # 字母开头
            else:
                if c <= '9' and c >= '0':

                    result *= 10
                    result += self.char2int(c)
                else: break
        
        # 截断
        result = sign * result
        if result < -2147483648:
            result = -2147483648
        elif result > 2147483647:
            result = 2147483647
        return result


test = Solution()
s = "   4193 with words"
print(test.myAtoi(s))


