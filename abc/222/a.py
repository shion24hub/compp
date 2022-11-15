import math
import itertools
import sys
from copy import deepcopy
from pprint import pprint

sys.setrecursionlimit(10**6)


def solve() : 
    n = list(input())
    missing = 4 - len(n)
    pans = ["0"] * missing + n
    ans = ""
    for alpha in pans :
        ans += alpha
    print(ans)        
    

if __name__ == '__main__' :
    solve()