import math


class PrimeGenerator:
    def __init__(self):
        pass

    @staticmethod
    def generator_prime(n):
        result = []
        for i in range(2, n + 1):
            is_prime = True
            print ("ddd", int(math.sqrt(i)) + 1)
            for j in range(2, int(math.sqrt(i)) + 1):
                if i % j == 0:
                    is_prime = False
            if is_prime:
                result.append(i)
        return result


if __name__ == "__main__":
    num = int(input("Please enter the number till which you want to generate prime numbers\n"))
    print (PrimeGenerator.generator_prime(num))
