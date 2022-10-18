n = int(input())

sbinn = str(bin(n))[2:]

bit = []
zbit = []
for ind, b in enumerate(sbinn) :
    if b == "1" :
        bit.append(ind)
    else :
        zbit.append(ind)

length = len(bit)
mask = []
for i in range(2 ** length) :
    comb = str(bin(i)[2:])
    if len(comb) != length :
        add = "0" * (length - len(comb))
        comb = add + comb
    mask.append(comb)

for m in mask :
    for z in zbit :
        m = str(m[:z]) + "0" + str(m[z:])
    ans = int(m, 2)
    print(ans)