n = int(input())

alpha = ["A", "B", "C", "D", "E", "F"]

def f(num) :
    if num < 10 :
        return str(num)
    else :
        return alpha[num - 10]

quo = n // 16
rem = n % 16
if quo == 0 :
    print("0" + f(n))
else :
    if quo < 10 :
        print(str(quo) + f(rem))
    else :
        print(f(quo) + f(rem))