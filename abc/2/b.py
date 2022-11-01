import math
import itertools

def solve() : 
    w = input()
    vo = ["a", "i", "u", "e", "o"]

    ans = ""
    for alpha in w :
        if alpha not in vo :
            ans += alpha
    
    print(ans)

if __name__ == '__main__' :
    solve()