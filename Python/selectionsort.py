numbers = input("Enter a list of numbers seperated by commas: ")
numbers = numbers.replace(' ', '')
numbers = numbers.split(',')

for i in range(len(numbers)):
    min_idx = i
    for j in range(i+1, len(numbers)):
        if numbers[min_idx] > numbers[j]:
            min_idx = j
    
    numbers[i], numbers[min_idx] = numbers[min_idx], numbers[i]

print(numbers)