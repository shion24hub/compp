d = 1
n = 10000

counter = 0
i = 1
while True :
    if (i * n) % 100 == 0 and (i * n / 100) % 100 == 0 and (i * n / 100 / 100) % 100 != 0 :
        counter += 1
        print("{}個目は{}".format(counter, i * n))
    i += 1

    if counter == 100 :
        break