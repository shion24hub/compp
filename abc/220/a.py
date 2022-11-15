import math
import itertools
import sys
from copy import deepcopy
from pprint import pprint

sys.setrecursionlimit(10**6)


def solve() : 
    a, b, c = map(int, input().split())
    for i in range(a, b + 1) :
        if i % c == 0 :
            print(i)
            return 
    print(-1)

if __name__ == '__main__' :
    solve()