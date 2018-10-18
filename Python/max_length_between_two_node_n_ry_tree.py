"""
Program to find length of max path between two nodes (not neccesserry leave) and these two nodes in an n-ary tree
"""

class Node:
    val = None
    childs = []
    
    def __init__(self, v):
        self.val = v

    def __repr__(self):
        return str(self.val)
    
def get_max_nodes(root, result_array=[0, None, None]):
    print root
    global max_length, n_1, n_2
    if not root.childs:
        return 1, root, result_array
    
    l = []
    for c in root.childs:
        h, h_n, _ = get_max_nodes(c)
        l.append((h, h_n))
    l.sort(key=lambda x: x[0], reverse = True)
    if len(l) > 1:
        if l[0][0] + l[1][0] + 1 > result_array[0]:
            result_array[1], result_array[2] = l[0][1], l[1][1]
            result_array[0] = l[0][0] + l[1][0] + 1
    else:
        if l[0][0] + 1 > result_array[0]:
            result_array[1], result_array[2] = l[0][1], None
            result_array[0] = l[0][0] + 0 + 1
    return l[0][0]+1, l[0][1], result_array

n = Node(1)
n.childs = [Node(2), Node(3), Node(4)]
n.childs[0].childs = [Node(5), Node(6)]
n.childs[1].childs = [Node(7)]
n.childs[2].childs = [Node(8), Node(9), Node(10)]
n.childs[0].childs[1].childs = [Node(11)] 
print get_max_nodes(n)[2]