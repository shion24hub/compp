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

def q(s, p) :
    if (s * s - 4 * p < 0) :
        return False

    root = math.sqrt(s * s  - 4 * p)
    ans1 = float((s + root) / 2)
    ans2 = float((s - root) / 2)
    # print("ans1 : {}".format(ans1))
    # print("ans2 : {}".format(ans2))
    if (ans1.is_integer() and ans1 != 0) and (ans2.is_integer() and ans2 != 0) :
        return (ans1, ans2)
    elif (ans1.is_integer() and ans1 != 0) :
        return (ans1, -1)
    elif (ans2.is_integer() and ans2 != 0) :
        return (ans2, -1)
    else :
        return False

def solve() : 
    s, p = map(int, input().split())

    if q(s, p) == False :
        print("No")
    else :
        anss = q(s, p)
        if anss[1] == -1 :
            v = anss[0]
            if v + v == s and v * v == p :
                print("Yes")
            else :
                print("No")
        else :
            v1 = anss[0]
            v2 = anss[1]
            if v1 + v2 == s and v1 * v2 == p :
                print("Yes")
            elif v1 + v1 == s and v1 * v1 == p :
                print("Yes")
            elif v2 + v2 == s and v2 * v2 == p :
                print("Yes")
            else :
                print("No")
            

if __name__ == '__main__' :
    solve()