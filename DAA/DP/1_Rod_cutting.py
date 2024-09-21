# Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. Determine the maximum
#  value obtainable by cutting up the rod and selling the pieces.

# Note: Consider 1-based indexing.

# Example:

# Input: n = 8, price[] = {1, 5, 8, 9, 10, 17, 17, 20}
# Output: 22
# Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5+17=22.

# Input: n = 8, price[] = {3, 5, 8, 9, 10, 17, 17, 20}
# Output: 24
# Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1]= 8*3 = 24.
#------------------------------------------------------------------------------------------------------------------------------------------

# class Solution: -----> O(2^n), O(n)
    
#     def cutRod(self, price, n):
        
#         def helper(index,n):
#             if index == 0:
#                 return n*price[0]
#             if n == 0:
#                 return 0
#             cut = float("-inf")
#             rod_len = index+1
#             if rod_len <= n:
#                 cut = price[index] + helper(index,n-rod_len) # I stand at the same index bcos I can cut the same length rod multiple times.
#             not_cut = helper(index-1, n)
#             return max(cut, not_cut)
        
#         return helper(n-1,n)

class Solution: #-----> O(n^2), O(n)
    
    def cutRod(self, price, n):
        dp = [[-1]*(n+1) for _ in range(n+1)]   

        def helper(index,n):
            if index == 0:
                return n*price[0]
            if n == 0:
                return 0
            if dp[index][n] != -1:
                return dp[index][n]            
            cut = float("-inf")
            rod_len = index+1
            if rod_len <= n:
                cut = price[index] + helper(index,n-rod_len) # I stand at the same index bcos I can cut the same length rod multiple times.
            not_cut = helper(index-1, n)
            dp[index][n] = max(cut, not_cut)
        
        return helper(n-1,n)