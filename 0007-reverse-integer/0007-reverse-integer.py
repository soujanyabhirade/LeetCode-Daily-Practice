class Solution:
    def reverse(self, x):
        res = 0
        
        while x != 0:
            digit = x % 10
            
            if x < 0 and digit > 0:
                digit -= 10
                
            x = (x - digit) // 10
            
            # overflow check
            if res > 214748364 or res < -214748364:
                return 0
            
            res = res * 10 + digit
        
        return res