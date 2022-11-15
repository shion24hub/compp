import math
import itertools
import sys
from copy import deepcopy
from pprint import pprint

sys.setrecursionlimit(10**6)

def solve() : 
    s = list(input())
    
    length = len(s)
    anss = []
    for _ in range(length) :
        comp = s[1:]
        begin = [s[0]]
        anss.append(comp + begin)
        s = comp + begin
    
    anss.sort()
    minans = ""
    maxans = ""
    for alpha in anss[0] :
        minans += alpha
    for alpha in anss[-1] :
        maxans += alpha
    
    print(minans)
    print(maxans)

if __name__ == '__main__' :
    solve()