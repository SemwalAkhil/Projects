with open("input.txt","r") as f1: # add file name
    toSkip = f1.readlines()
with open("output.txt","w",newline="\n") as f2: # add file name
    for i in toSkip:
        char = {}
        for j in range(len(i)-1):
            try:
                char[i[j:j+2]] += 1
            except:
                char[i[j:j+2]] = 1
        for k in list(char.values()):
            if (k > 1):
                break
        else:
            f2.write(i)
    