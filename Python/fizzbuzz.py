def fizzBuzz(self, n):
    """
    :type n: int
    :rtype: List[str]
    """
    ans = []
    fizz_buzz_dict = {3 : "Fizz", 5 : "Buzz"}

    for num in range(1,n+1):
        num_ans_str = ""
        for key in fizz_buzz_dict.keys():
            if num % key == 0:
                num_ans_str += fizz_buzz_dict[key]
        if not num_ans_str:
            num_ans_str = str(num)
        ans.append(num_ans_str)  
    return ans
