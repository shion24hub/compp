import math
import itertools
import sys
from copy import deepcopy

sys.setrecursionlimit(10**6)


def solve() : 
    n, k, a = map(int, input().split())
    p = [i+1 for i in range(n)]
    l = p[a-1:] + p[:a-1]
    if k <= len(l) :
        print(l[k-1])
    else :
        pos = k % n
        if pos == 0 :
            print(l[-1])
        else :
            print(l[pos-1])



if __name__ == '__main__' :
    solve()