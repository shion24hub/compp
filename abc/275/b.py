import math
import itertools

def solve() :
    a, b, c, d, e, f = map(int, input().split())
    print(((a * b * c) - (d * e * f)) % 998244353)
    

if __name__ == '__main__' :
    solve()