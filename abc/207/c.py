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
    n = int(input())
    ls = []
    rs = []
    for _ in range(n) :
        t, l, r = map(int, input().split())
        if t == 1 :
            ls.append(l)
            rs.append(r)
        if t == 2 :
            ls.append(l)
            rs.append(r - 0.5)
        if t == 3 :
            ls.append(l + 0.5)
            rs.append(r)
        if t == 4 :
            ls.append(l + 0.5)
            rs.append(r - 0.5)

    ans = 0
    for i in range(n) :
        for j in range(n) :
            if i == j :
                continue
            if ls[j] <= rs[i] and ls[i] <= rs[j] :
                ans += 1
    
    print(int(ans / 2))

if __name__ == '__main__' :
    solve()