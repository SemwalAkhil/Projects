with open("input.txt","r") as f1: # add file name
    toSkip = f1.readlines()
minRange = "0x0000000000" # min range 0x(hex)
maxRange = "0xFF"         # max range 0x(hex)
with open("output.txt","w",newline="\n") as f2: # add file name
    for i in range(int(minRange,16),int(maxRange,16)):
        for j in toSkip:
            if (hex(i).find(j.lower().rstrip()) != -1):
                # print("skipping ",hex(i)) # uncomment to verify skip
                break
        else:
            f2.write(hex(i)+"\n")