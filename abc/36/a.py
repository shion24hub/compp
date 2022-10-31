import math
import itertools

def solve() : 
    a, b = map(int, input().split())
    if b % a == 0 :
        print(int(b / a))
    else :
        print(int((b / a)) + 1)

if __name__ == '__main__' :
    solve()