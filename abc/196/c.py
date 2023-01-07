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

def transpose(l : list) :
    t = list(zip(*l))
    ret = [list(comp) for comp in t]
    return ret

def sort2dListBySpecificRow(l : list, by = 0, reverse=False) :
    ret = transpose(sorted(transpose(l), key=lambda x: x[by], reverse=reverse))
    return ret

def solve() : 
    n = input()

    ans = 0
    digit = len(n)
    if (digit%2 == 0) :
        mid = int(digit/2)
        fi = n[:mid]
        se = n[mid:]
        add = 1
        for i in range(mid) :
            if (i == 0) :
                add *= min(int(fi[i]), int(se[i]))
            else :
                add *= min(int(fi[i]), int(se[i])) + 1
        ans += add
    
    loop = int((digit-1)//2)
    for i in range(loop) :
        ans += 9 * 10 ** i
    
    print(ans)

if __name__ == '__main__' :
    solve()