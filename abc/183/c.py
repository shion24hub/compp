import math
import itertools

def solve() : 
    n, k = map(int, input().split())
    t = [list(map(int, input().split()))for _ in range(n)]

    var_city = [i for i in range(n)][1:]
    ps = list(itertools.permutations(var_city))
    times = []
    for p in ps:
        routes = [0] + list(p) + [0]
        sum = 0
        for i in range(len(routes)-1) :
            sum += t[routes[i]][routes[i+1]]
        times.append(sum)
    
    ans = 0
    for time in times :
        if time == k :
            ans += 1
    
    print(ans)

if __name__ == '__main__' :
    solve()