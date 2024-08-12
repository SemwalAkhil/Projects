def arithmetic_arranger(problems, show_answers=False):
    for i in range(len(problems)):
        vals = problems[i].split()
        maxLen = len(max(vals))
        problems[i] = " "*(maxLen-len(vals[0])) + vals[0] + "\n" + vals[1] + " " + vals[2] + "\n" + "-"*(maxLen+2)
    return problems

# print(f'\n{arithmetic_arranger(["32 + 698", "3801 - 2", "45 + 43", "123 + 49"])}')
# print("hello"+"\n"+"world")

name = "Om\n"
age = 22
print(f"Hello, My name is {name} and I'm {age} years old.")