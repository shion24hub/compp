n = int(input())
h = list(map(int, input().split()))
max = 0
ans = 0
for ind, num in enumerate(h) :
    if max < num :
        max = num
        ans = ind
print(ans + 1)