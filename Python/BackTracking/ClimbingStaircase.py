# You need to climb a staircase that has n steps, and you decide to get some extra exercise by jumping up the steps. 
# You can cover at most k steps in a single jump. 
# Return all the possible sequences of jumps that you could take to climb the staircase, sorted.

#For n = 4 and k = 2, the output should be

#climbingStaircase(n, k) =
#[[1, 1, 1, 1],
# [1, 1, 2],
# [1, 2, 1],
# [2, 1, 1],
# [2, 2]]

#CodeSignal problem can be found at: https://app.codesignal.com/interview-practice/task/cAXEnPyzknC5zgd7x

def climbingStaircase(n, k):
    if n == 0:
        return [[]]
    stair = [1] * n
    return findPossible(stair, k)
def findPossible(stair, k):
    if len(stair) == 0:
        return [[]]
    if len(stair) == 1:
        return [[1]]
    if len(stair) < k:
        return findPossible(stair, len(stair))
    
    solutions = []
    for i in range(1,k+1):
        results = findPossible(stair[i::],k)
        print(results)
        for result in results:
            solutions.append([i]+result)
    return solutions