import math
import itertools
import sys
from copy import deepcopy

sys.setrecursionlimit(10**6)

def f(x) :
    return x * x * x + x

def solve() : 
    n = int(input())

    left = 0.0
    right = 100.0
    for _ in range(50) :
        mid = (left + right) / 2
        print("mid = {}".format(mid))
        ret = f(mid)
        if ret < n :
            left = mid
        elif ret > n :
            right = mid

    print(mid)

if __name__ == '__main__' :
    solve()