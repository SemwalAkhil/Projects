# Q. Perform sorting in single loop
arr = [5,4,6,2,1]
right = True
swapped = False
index = 1
def swap(ind1,ind2):
    arr[ind1],arr[ind2] = arr[ind2],arr[ind1]
while True:
    print(arr,index,swapped,right)
    if (arr[index] < arr[index-1]):
        swap(index,index-1)
        swapped = True
    if right:
        index += 1
        if (index == (len(arr) - 1)):
            if not swapped:
                break
            right = False
            swapped = False
    else:
        index -= 1
        if (index == 1):
            if not swapped:
                break
            right = True
            swapped = False 
print(arr)