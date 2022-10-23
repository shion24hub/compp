x, y, n = map(int, input().split())
if x <= y / 3 :
    print(x * n)
else :
    quo = n // 3
    rem = n % 3
    print(quo * y + rem * x)