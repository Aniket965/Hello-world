# i --> source node
# n --> number of nodes
# E --> adjacency list in the form of dictionary


def bfs(i, n, E):
    level = [-1] * (n + 1)
    queue = []
    level[i] = 0
    queue.append(i)

    # print(E)
    while len(queue) > 0:
        head = queue[0]
        queue = queue[1:]
        for k in E[head]:
            if level[k] == -1:
                level[k] = 1 + level[head]
                queue.append(k)

    return level
