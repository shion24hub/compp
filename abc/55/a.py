import math
import itertools

def solve() : 
    n = int(input())
    getcount = int(n / 15)
    x = n * 800
    y = getcount * 200
    print(x - y)

if __name__ == '__main__' :
    solve()