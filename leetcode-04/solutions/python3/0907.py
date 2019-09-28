class Solution:
    def sumSubarrayMins(self, A: List[int]) -> int:
        n = len(A)
        kMod = int(1e9 + 7)
        
        ans = 0
        prev = [0] * n
        next = [0] * n
        stack1 = []
        stack2 = []
        
        for i in range(n):
            prev[i] = i + 1
            next[i] = n - i
        
        for i in range(n):
            while stack1 and A[stack1[-1]] > A[i]:
                stack1.pop()
            prev[i] = i - stack1[-1] if stack1 else i + 1
            stack1.append(i)
            
            while stack2 and A[stack2[-1]] > A[i]:
                next[stack2[-1]] = i - stack2[-1]
                stack2.pop()
            stack2.append(i)
        
        for i in range(n):
            ans = (ans + A[i] * prev[i] * next[i]) % kMod
        
        return ans
        