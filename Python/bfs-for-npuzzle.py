def get_children(puzzle):
    output = []
    m = eval(puzzle)
    i = 0
    while 0 not in m[i]:
        i += 1

    j = m[i].index(0)

    if i > 0:  # MOVE UP
        m[i][j], m[i - 1][j] = m[i - 1][j], m[i][j]
        output.append(str(m))
        m[i][j], m[i - 1][j] = m[i - 1][j], m[i][j]

    if i < 3:  # MOVE DOWN
        m[i][j], m[i + 1][j] = m[i + 1][j], m[i][j]
        output.append(str(m))
        m[i][j], m[i + 1][j] = m[i + 1][j], m[i][j]

    if j > 0:  # MOVE LEFT
        m[i][j], m[i][j - 1] = m[i][j - 1], m[i][j]
        output.append(str(m))
        m[i][j], m[i][j - 1] = m[i][j - 1], m[i][j]

    if j < 3:  # MOVE RIGHT
        m[i][j], m[i][j + 1] = m[i][j + 1], m[i][j]
        output.append(str(m))
        m[i][j], m[i][j + 1] = m[i][j + 1], m[i][j]

    return output


def bfs(puzzle, result):
    path = {}
    path[str(puzzle)] = None
    queue = []
    queue.append(str(puzzle))
    visited = {}
    visited[str(puzzle)] = 1
    nodes = 0
    while queue:
        # import pdb; pdb.set_trace()
        path_ = queue.pop(0)
        # import pdb; pdb.set_trace()
        if path_ == str(result):
            print("Solved")
            print(path_)
            break

        child_node = get_children(str(path_))
        for child in child_node:
            if child not in visited:
                queue.append(child)
                visited[child] = 1
                path[child] = path_
        nodes = nodes + 1
        print(nodes)


def main():
    puzzle = [[1, 2, 6, 3], [4, 9, 5, 7], [8, 13, 11, 15], [12, 14, 0, 10]]
    result = [[0, 1, 2, 3], [4, 5, 6, 7], [8, 9, 10, 11], [12, 13, 14, 15]]

    bfs(puzzle, result)
    # dfs(puzzle,result)


main()
