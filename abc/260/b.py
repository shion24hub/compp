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

    #input
    n, x, y, z = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    scores = [[i+1 for i in range(n)], [], [], []]
    scores[1] += a
    scores[2] += b
    scores[3] = [scores[1][i] + scores[2][i] for i in range(n)]

    #process
    passed = []
    by_math = sort2dListBySpecificRow(scores, 1, True)
    by_eng = sort2dListBySpecificRow(scores, 2, True)
    by_matheng = sort2dListBySpecificRow(scores, 3, True)

    def f(l, std) :
        counter = 0
        i = 0
        while counter < std :
            if l[0][i] not in passed :
                passed.append(l[0][i])
                counter += 1
            i += 1
    
    f(by_math, x)
    f(by_eng, y)
    f(by_matheng, z)

    #output
    passed.sort()
    for passer in passed :
        print(passer)

if __name__ == '__main__' :
    solve()