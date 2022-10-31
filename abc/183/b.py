def solve() : 
    inp = list(map(int, input().split()))
    s = [inp[0], inp[1]]
    g = [inp[2], inp[3]]

    dist = g[0] - s[0]
    comp = dist / (s[1] + g[1])
    print(s[0] + comp * s[1])


if __name__ == '__main__' :
    solve()