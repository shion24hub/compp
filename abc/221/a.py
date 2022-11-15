import math
import itertools
import sys
from copy import deepcopy
from pprint import pprint

sys.setrecursionlimit(10**6)


def solve() : 
    a, b = map(int, input().split())
    diff = a - b
    print(32 ** diff)

if __name__ == '__main__' :
    solve()