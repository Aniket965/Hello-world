'''
Let us consider polynomials in a single variable x with integer coefficients: for instance, 3x4 - 17x2 - 3x + 5. Each term of the polynomial can be represented as a pair of integers (coefficient,exponent). The polynomial itself is then a list of such pairs.

We have the following constraints to guarantee that each polynomial has a unique representation:

    Terms are sorted in descending order of exponent
    No term has a zero cofficient
    No two terms have the same exponent
    Exponents are always nonnegative

For example, the polynomial introduced earlier is represented as

  [(3,4),(-17,2),(-3,1),(5,0)]

The zero polynomial, 0, is represented as the empty list [], since it has no terms with nonzero coefficients.

Write Python functions for the following operations:

  
  addpoly(p1,p2)
  multpoly(p1,p2)

that add and multiply two polynomials, respectively.

You may assume that the inputs to these functions follow the representation given above. Correspondingly, the outputs from these functions should also obey the same constraints.

Hint: You are not restricted to writing just the two functions asked for. You can write auxiliary functions to "clean up" polynomials – e.g., remove zero coefficient terms, combine like terms, sort by exponent etc. Build a library of functions that can be combined to achieve the desired format.

You may also want to convert the list representation to a dictionary representation and manipulate the dictionary representation, and then convert back.

Some examples:

  >>> addpoly([(4,3),(3,0)],[(-4,3),(2,1)])
  [(2, 1),(3, 0)]

Explanation: (4x3 + 3) + (-4x3 + 2x) = 2x + 3

  >>> addpoly([(2,1)],[(-2,1)])
  []

Explanation: 2x + (-2x) = 0

  >>> multpoly([(1,1),(-1,0)],[(1,2),(1,1),(1,0)])
  [(1, 3),(-1, 0)]

Explanation: (x - 1) * (x2 + x + 1) = x3 - 1
'''

def addpoly(e1, e2):
    new_list = list()
    for i in range(len(e1)):
        swap = False
        for j in range(len(e2)):
            if e1[i][1] == e2[j][1]:
                swap = True
                if e1[i][0] + e2[j][0] != 0:
                    new_list.append((e1[i][0] + e2[j][0], e1[i][1]))
                e2.pop(j)
                break
        if swap == False:
            new_list.append((e1[i][0], e1[i][1]))
    new_list = new_list + e2
    new_list = sorted(new_list, key=lambda tup: tup[1], reverse=True)
    return new_list


def multpoly(e1, e2):
    new_list = list()
    new_list1  = list()
    new_list2 = list()
    new_list.append(new_list1)
    new_list.append(new_list2)
    for i in range(len(e1)):
        for j in range(len(e2)):
            new_list[i].append((e1[i][0] * e2[j][0], e1[i][1] + e2[j][1]))
    return addpoly(new_list[0], new_list[1])