import math
import itertools

def solve() : 
    s = input()
    anss = [i for i in range(len(s)) if s[i] == "a"]
    print(anss[-1]+1) if len(anss) > 0 else print(-1)

if __name__ == '__main__' :
    solve()