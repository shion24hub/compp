import math
import itertools

def solve() : 
    x = int(input())
    a = int(input())
    b = int(input())

    print(x - a - (((x - a) // b) * b))

if __name__ == '__main__' :
    solve()