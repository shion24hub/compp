import math
import itertools
import sys
from copy import deepcopy

sys.setrecursionlimit(10**6)


def solve() : 
    n = int(input())
    ans = format(n, "b")
    if len(ans) != 10 :
        miss = 10 - len(ans)
        ans = "0" * miss + ans
    print(ans)


if __name__ == '__main__' :
    solve()