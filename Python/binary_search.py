class BinarySearch(list):
    def __init__(self, a, b):
        self.a = a      # length of the list to be created
        self.b = b      # the step or difference between consecutive values
        self.length = list()

        for item in range(b, (a*b)+1, b):
            self.append(item) # self is our list because we inherited list class

        self.length = len(self) # returns the number of elements in the array

    def search(self, c): # c is the value you are to find
        dict_result = {}
        count = 0  # count is 0 until we split the list
        index = -1 # if c is not found, we set the index to -1

        first_index = 0
        last_index = self.length - 1
        item_found = False

        # check if c is not in the self list
        if c not in self:
            item_found = True
            index = -1

        # please note that whenever item_found is true, we don't increment the count
        if c == self[first_index]:
            item_found = True
            index = first_index

        if c == self[last_index]:
            item_found = True
            index = last_index

        # implement the binary search algorithm, where search first compares c to the middle_item
        while first_index <= last_index and not item_found:
            middle_index = (first_index+last_index)//2
            middle_item = self[middle_index]

            if c == middle_item:
                item_found = True
                index = middle_index

            else:
                count += 1
                if middle_item > c:
                    last_index = middle_index-1
                else:
                    first_index = middle_index+1

        # count is the number of times your search iterated to find c
        # the index of the number in question
        dict_result['count'] = count
        dict_result['index'] = index

        return dict_result # {'count': count, 'index': index}

# x = BinarySearch(100, 10)
# x = BinarySearch(20, 2)
# print(x)
# print(x.search(1000))