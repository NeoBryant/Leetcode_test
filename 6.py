
"""
先创建存储Z字字符串的矩阵，然后根据字符串顺序依次将字符放入对应位置，最后遍历矩阵
"""


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        l = len(s) # 字符串长度
        # a为每行长度
        a = (int(l / (numRows * 2 - 2)) * (numRows - 1)) 
        if l % (numRows * 2 - 2) >= 1 and l % (numRows * 2 - 2) <= numRows:
            a += 1
        elif l % (numRows * 2 - 2) > numRows:
            a += l % (numRows * 2 - 2) - numRows + 1

        result = ""
        matrix = [[" " for i in range(0,a)] for j in range(0, numRows)]

        i = 0
        j = 0
        down = True # 先下降后上升依次反复
        for c in range(0, len(s)):
            matrix[i][j] = s[c]
            # print(c % (2 * numRows - 2))
            if c % (2 * numRows - 2) < (numRows-1):
                down = True
            else:
                down = False
            # print(down)
            if down:
                i += 1
            else:
                i -= 1
                j += 1
        for i in range(0,numRows):
            for j in range(0, a):
                if matrix[i][j] != " ":
                    result += matrix[i][j]
        # print(matrix)
        return result


test = Solution()
# a = "PAYPALISHIRING"
# b = 4
a = "A"
b = 1
print(test.convert(a,b))


