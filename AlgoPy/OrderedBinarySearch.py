def Ordered_binary_Search(olist, item):
    
    if len(olist) == 0:
        return False
    else:
        midpoint = len(olist) // 2
        if olist[midpoint] == item:
            return True
        else:
            if item < olist[midpoint]:
                return binarySearch(olist[:midpoint], item)
            else:
                return binarySearch(olist[midpoint+1:], item)

def binarySearch(alist, item):

    first = 0
    last = len(alist) - 1
    found = False

    while first <= last and not found:
        midpoint = (first + last) // 2
        if alist[midpoint] == item:
            found = True
        else:
            if item < alist[midpoint]:
                last = midpoint - 1
            else:
                first = midpoint + 1

    return found

print(Ordered_binary_Search([0, 1, 3, 8, 14, 18, 19, 34, 52], 3))
print(Ordered_binary_Search([0, 1, 3, 8, 14, 18, 19, 34, 52], 17))
