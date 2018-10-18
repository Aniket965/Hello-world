#Given a string s, find all its potential permutations. 
#The output should be sorted in lexicographical order.

#For s = "CBA", the output should be
# stringPermutations(s) = ["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"];
#For s = "ABA", the output should be
# stringPermutations(s) = ["AAB", "ABA", "BAA"].

#CodeSignal problem can be found at: https://app.codesignal.com/interview-practice/task/gdFsKG9iSnH5JJoei

def stringPermutations(s):
    if len(s) == 0:
        return 0
    elif len(s) == 1 or (len(s) == 2 and s[0] == s[1]):
        return [s]
    elif len(s) == 2 and s[0] != s[1]:
        sortingo = sorted(s)
        sortingo = "".join(sortingo)
        return [sortingo] + [sortingo[::-1]]

    sortedString = sorted(s)
    sortedString = "".join(sortedString)
    print(sortedString)
    result = []
    passed = []
    for i in range(len(sortedString)):
        if sortedString[i] not in passed:
            shortString = list(sortedString)[:]
            shortString.remove(sortedString[i])
            shortString = "".join(shortString)
            print(str(shortString))
            results = stringPermutations(shortString)
            for r in results:
                result += [str(sortedString[i])+r]
            passed.append(sortedString[i])
    return result
    