class Solution:
    # @return an integer
    def reverse(self, x):
        result = 0

        negative = (x < 0)

        x = abs(x)

        while x > 0:
            result = result*10 + x%10
            x = x/10

        if negative:
            return -result
        else:
            return result


print '3/10 =', 3/10
print '-3/10 =', -3/10

a = Solution()
print '123 ->', a.reverse(123)
print '-321 ->', a.reverse(-321)
