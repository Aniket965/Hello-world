
import random

text = input("Enter text to find using letters, numbers and space: ")
population = 200
mutation = .01
current = []  # [(fitness, char array),]


def create_selection_pool():
    selection_pool = current[:]
    for i in current:
        for j in range(i[0]):
            selection_pool.append(i)
    return selection_pool


def select(selection_pool):
    first = selection_pool[random.randint(0, len(selection_pool)-1)][1]
    second = selection_pool[random.randint(0, len(selection_pool)-1)][1]
    return first, second


def crossover(parent1, parent2):
    midpoint = int(len(text)/2)
    return parent1[:midpoint] + parent2[midpoint:]


def mutate(starting):
    for i in range(len(starting)):
        if random.random() <= mutation:
            starting[i] = random_character()
    return starting


def evolve():
    global current
    new_population = []
    pool = create_selection_pool()

    for i in range(population):
        first, second = select(pool)
        result = crossover(first, second)
        result = mutate(result)
        new_population.append([fitness(result), result])

    current = new_population


def loop():
    global current
    count = 0
    while True:
        best = max(current)
        print('\r{:7d} : {} : {:3d}%'.format(count, ''.join(best[1]), best[0]), end='')
        if best[0] == 100:
            return
        evolve()
        count += 1


def random_character():
    sign = random.randint(61, 132)
    if sign == 61:
        sign = 32
    elif sign == 62:
        sign = 46
    elif sign > 122:
        sign -= 75
    return chr(sign)


def init():
    global current
    current = []
    for i in range(population):
        unit = []
        for j in range(len(text)):
            unit.append(random_character())
        current.append((fitness(unit), unit))


def fitness(element):
    counter = 0
    n = len(text)
    for i in range(n):
        if element[i] == text[i]:
            counter += 1
    return int(pow((counter/n), 2)*100)


if __name__ == '__main__':
    init()
    loop()
    print('\nFinished')
