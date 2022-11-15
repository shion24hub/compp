import math
import itertools
import sys
from copy import deepcopy
from pprint import pprint

sys.setrecursionlimit(10**6)


def solve() : 
    x = int(input())
    if x >= 90 :
        print("expert")
    elif x >= 70 :
        print(90 - x)
    elif x >= 40 :
        print(70 - x)
    else :
        print(40 - x)

if __name__ == '__main__' :
    solve()