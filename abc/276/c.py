import math
import itertools
import sys
from copy import deepcopy

sys.setrecursionlimit(10**6)

def fact(x) :
    if x == 1 :
        return 1
    else :
        return fact(x-1) * x

def f(l, std) :
    cand = []
    for i in range(1, len(l)) :
        if l[i] == False :
            cand.append(i)
    sorted(cand)
    for i in range(len(cand)) :
        if cand[i] == std :
            index = i-1
    ret = [cand[index]]
    del cand[index]
    ret += reversed(cand)

    return ret

def solve() : 
    n = int(input())
    p = list(map(int, input().split()))

    used = [False for _ in range(n+1)] #使ったらtrue
    chroused = [deepcopy(used)]
    chroadd = []
    for i in range(n-1) :
        add = fact(n-(i+1))
        addc = 0
        for j in range(1, p[i]) :
            if used[j] :
                continue
            else :
                addc += add
        used[p[i]] = True
        chroused.append(deepcopy(used))
        chroadd.append(addc)
    for i, add in enumerate(reversed(chroadd)) :
        if add == 0 :
            continue
        else :
            ans = p[:-(i+2)]
            std = p[-(i+2)]
            ans += f(chroused[-(i+2)], std)
            break
    
    print(*ans)

if __name__ == '__main__' :
    solve()