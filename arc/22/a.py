def solve() : 
    s = input()
 
    iindex = [i for i in range(len(s)) if s[i].casefold() == "i"]
    cindex = [i for i in range(len(s)) if s[i].casefold() == "c"]
    tindex = [i for i in range(len(s)) if s[i].casefold() == "t"]
    anss = [True for i in iindex for c in cindex for t in tindex if i < c < t]
    if True in anss :
        ans = True
    else :
        ans = False
    return ans
 
if __name__ == '__main__' :
    print("YES") if solve() else print("NO")