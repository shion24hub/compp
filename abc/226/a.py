import math
import itertools
import sys
from copy import deepcopy

sys.setrecursionlimit(10**6)


def solve() : 
    n = float(input())
    print(int(round(n+0.00005, 0))) #round関数のarg1=0.5のときの挙動は未定義。

if __name__ == '__main__' :
    solve()