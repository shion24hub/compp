import math
import itertools

def solve() : 
    x, y = map(int, input().split())
    if x > y :
        print(x)
    else :
        print(y)

if __name__ == '__main__' :
    solve()