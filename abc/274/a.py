a, b = map(int, input().split())

ans = round(b/a, 3)

if len(str(ans)) == 3 :
    print(str(ans) + "0" * 2)
elif len(str(ans)) == 4 :
    print(str(ans) + "0")
else :
    print(str(ans))