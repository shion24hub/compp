if __name__ == "__main__" :
    f = open("snippets.txt", "r")
    lines = f.readlines()
    f.close()

    for line in lines :
        newline = ""
        for s in line :
            if s == '"' :
                newline += "'"
            else :
                newline += s

        print('"{}",'.format(newline.rstrip("\n")))