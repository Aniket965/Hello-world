# Quick Sort
#Time-complexity::
# Worst case (array already sorted/reverse sorted or too many duplicates): O(n^2),
# Average case : O(nlogn), Best case(when partition always results middle element as pivot):O(nlogn)
#Auxiliary Space: O(1), not Stable
#preferred for sorting arrays over merge sort


#Algorithm
# quicksort(A, lo, hi) is
#   if lo < hi then
#        p := partition(A, lo, hi)
#       quicksort(A, lo, p)
#      quicksort(A, p + 1, hi)

# partition(A, lo, hi) is
#   pivot := A[lo]
#  i := lo – 1
# j := hi + 1
#loop forever
#   do
#      i := i + 1
# while A[i] < pivot
#do
#   j := j – 1
#while A[j] > pivot
#if i >= j then
#   return j
#swap A[i] with A[j]


def quick_sort(a,lo,hi)
    if lo<hi
        p=partition(a,lo,hi)
        quick_sort(a,lo,p-1)
        quick_sort(a,p+1,hi)
    end
    return a
end

def partition(a,lo,hi)
    i=lo
    j=hi+1
    pivot= a[lo]
    while true
    #Loop to increment i
        begin
            i+=1
            break if i==hi
        end while a[i]<pivot
    #Loop to increment j
        begin
            j-=1
            break if j==lo
        end while a[j]>pivot
    # break the loop if pointers cross
        break if i>=j
    #Swap arr[i] and arr[j]
        temp=a[i]
        a[i]=a[j]
        a[j]=temp
    end
    # Swap arr[lo] with arr[j]
    temp=a[lo]
    a[lo]=a[j]
    a[j]=temp
    return j
end

quick_sort([12,3,1,2,4,70,89,3,3],0,8)
