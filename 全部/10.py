'''
f[i][j]：表示s的前i个字符与p中的前j个字符是否能够匹配。在进行状态转移时, 我们考虑p的第j个字符的匹配情况。
'''
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)

        def matches(i: int, j: int) -> bool:
            if i == 0:
                return False
            if p[j - 1] == '.':
                return True
            return s[i - 1] == p[j - 1]

        f = [[False] * (n + 1) for _ in range(m + 1)]
        f[0][0] = True
        for i in range(m + 1):
            for j in range(1, n + 1):
                if p[j - 1] == '*':
                    f[i][j] |= f[i][j - 2] # 按位或，等价于f[i][j] = f[i][j] | f[i][j-2]
                    if matches(i, j - 1):
                        f[i][j] |= f[i - 1][j]
                else:
                    if matches(i, j):
                        f[i][j] |= f[i - 1][j - 1]
        return f[m][n]


test = Solution()
s = 'aa'
p = 'a'
print(test.isMatch(s, p))


              