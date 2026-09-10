class Solution(object):
    def isPowerOfTwo(self, n):
        base = 1
        while(n > base):
            base = base * 2
        if(base == n):
            return True
        return False
