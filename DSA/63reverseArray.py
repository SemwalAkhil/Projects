def reverseArray(arr, m):
    #  Write your code here.
    beg = m+1
    end = len(arr)-1
    while (beg < end):
        arr[beg],arr[end] = arr[end],arr[beg]
        beg += 1
        end -= 1
    return arr


v = [1,2,3,4,5,6]
print("before : ",v)
reverseArray(v,3) 
print("after : ",v)
v = [5]
print("before : ",v)
reverseArray(v,0) 
print("after : ",v)
v = [3,4]
print("before : ",v)
reverseArray(v,0) 
print("after : ",v)