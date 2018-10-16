def insertion_sort(a)
    for i in 1...(a.length)
        j=i
        while j>0
            if a[j-1]>a[j]
                temp=a[j]
                a[j]=a[j-1]
                a[j-1]=temp
            else
              break
            end
            j=j-1
        end
    end
    return a
end

a=[1,12,3,2,3]
puts 'Before Sorting :' + a.join(' ') 
a = insertion_sort(a)
puts 'After Sorting :' +a.join(' ')