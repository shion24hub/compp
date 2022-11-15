import math
import itertools
import sys
from copy import deepcopy
from pprint import pprint

sys.setrecursionlimit(10**6)

def base10(n, k) :
    digit = []
    while n >= 1 :
        digit.append(n % 10)
        n //= 10
    
    ret = 0
    for i in range(len(digit)) :
        ret += (k ** i) * digit[i]
    
    return ret

def solve() : 
    k = int(input())
    a, b = map(int, input().split())

    a10 = base10(a, k)
    b10 = base10(b, k)
    
    print(a10 * b10)
    

if __name__ == '__main__' :
    solve()