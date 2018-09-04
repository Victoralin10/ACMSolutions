import sys
import math

t = int(input())

def fast_pow(a, b):
    ans = 1
    p = a
    while b > 0:
        if b%2 != 0:
            ans *= p
        p = p * p
        b = b//2
    return ans

for i in range(t):
    n,r,p = (int(x) for x in input().split())
    if n >= p:
        ans = 0
    else:
        hi = 500
        lo = 0
        while hi != lo + 1:
            mid = math.ceil(lo + hi)//2
            vmid = fast_pow((100 + r)/100, mid) * n
            if vmid < p:
                lo = mid
            else:
                hi = mid
        ans = hi
    print("Case {0}: {1}".format(str(i+1), ans))