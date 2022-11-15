import math
import itertools
import sys
from copy import deepcopy
from pprint import pprint

sys.setrecursionlimit(10**6)

UPPERCASE = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
LOWERCASE = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
ASCII_UPPERCASE_BEGIN = 65
ASCII_UPPERCASE_END = 90
ASCII_LOWERCASE_BEGIN = 97
ASCII_LOWERCASE_END = 122

MOD = 998244353

def to_base10 (n : int, k : int) -> int:
    digits = []
    while n >= 1 :
        digits.append(n % 10)
        n //= 10
    ret = 0
    for i in range(len(digits)) :
        ret += (k ** i) * digits[i]

    return ret

def to_baseK (n : int, k : int) -> list:
    ret = []
    while True :
        if n < k :
            ret.append(n)
            break
        ret.append(n % k)
        n //= k
    ret.reverse()

    return ret


def solve() : 
    """
    MAIN PROCESS.
    """
    n = int(input())
    a = []
    b = []
    for _ in range(n) :
        ia, ib = map(int, input().split())
        a.append(ia)
        b.append(ib)
    
    if n == 1 :
        print(a[0] / 2)
        return 
    
    cmcum = [a[0]]
    for i in range(1, n) :
        cmcum.append(cmcum[i-1] + a[i])

    scum = [a[0] / b[0]]
    for i in range(1, n) :
        scum.append(scum[i-1] + (a[i] / b[i]))
    
    center = scum[-1] / 2
    
    for i in range(1, n) :
        if scum[i-1] < center <= scum[i] :
            pos = i
            break
    
    rem = center - scum[pos-1]
    ans = rem * b[pos] + cmcum[pos-1]

    print(ans)

if __name__ == '__main__' :
    solve()