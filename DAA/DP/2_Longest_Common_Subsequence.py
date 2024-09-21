# def lcs(self, n, m, str1, str2): # -------> O(2^n), O(n)
#     if n == 0 or m == 0:
#         return 0
#     if(str1[n-1] == str2[m-1]):
#         return 1+self.lcs(n-1,m-1,str1,str2)
#     return max(self.lcs(n-1,m,str1,str2), self.lcs(n,m-1,str1,str2))

# def lcs(self, n, m, str1, str2): # -------> O(n^2), O(n^2+n)
#     if n == 0 or m == 0:
#         return 0
#     if self.dp[n][m] != -1:
#         return self.dp[n][m]
#     if(str1[n-1] == str2[m-1]):
#         return 1+self.lcs(n-1,m-1,str1,str2)
#     self.dp[n][m] = max(self.lcs(n-1,m,str1,str2), self.lcs(n,m-1,str1,str2))
#     return self.dp[n][m]

# always try to find a recursive soln first then apply tabulation on top of that

def lcs(self, n, m, str1, str2):  #---> O(n^2), O(n^2)
    dp = [[0]*(m+1) for _ in range(n+1)]
    for i in range(n+1):
        for j in range(m+1):
            if i == 0 or j == 0:
                continue
            if(str1[i-1] == str2[j-1]):
                dp[i][j] = 1+dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp[n][m]