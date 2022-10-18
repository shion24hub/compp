a, b = map(int, input().split())

def f(num) :
    ret = []
    if num == 0 :
        ret += [False, False, False]
    elif num == 1 :
        ret += [True, False, False]
    elif num == 2 :
        ret += [False, True, False]
    elif num == 3 :
        ret += [True, True, False]
    elif num == 4 :
        ret += [False, False, True]
    elif num == 5 :
        ret += [True, False, True]
    elif num == 6 :
        ret += [False, True, True]
    elif num == 7 :
        ret += [True, True, True]
    return ret

taka = f(a)
ao = f(b)

sunu = []
for t, a in zip(taka, ao) :
    if t or a :
        sunu.append(True)
    else :
        sunu.append(False)

ans = 0
if sunu[0] :
    ans += 1
if sunu[1] :
    ans += 2
if sunu[2] :
    ans += 4

print(ans)
