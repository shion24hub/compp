def solve() : 
    n = int(input())
    d = pow(10, 9) + 7
    ans = 1
    for i in range(n) :
        ans *= i + 1
        ans %= d
    print(ans)
 
if __name__ == '__main__' :
    solve()