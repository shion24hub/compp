import math
import itertools
import sys
from copy import deepcopy

sys.setrecursionlimit(10**6)


def solve() : 
    x = int(input())
    if x == 0 :
        print("No")
        return
    if x % 100 == 0 :
        print("Yes")
    else :
        print("No")

if __name__ == '__main__' :
    solve()