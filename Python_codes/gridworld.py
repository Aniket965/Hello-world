import numpy as np
WORLD_SIZE = 4
REWARD = -1
GAMMA = 1

world = np.zeros((WORLD_SIZE, WORLD_SIZE))
actions = ['L', 'U', 'R', 'D']

nextState = []
for i in range(0, WORLD_SIZE):
	nextState.append([])
	for j in range(WORLD_SIZE):
		nextS = dict()
		if i == 0:
			nextS['U'] = [i , j]
		else:
			nextS['U'] = [i - 1, j]
		
		if j == 0:
			nextS['L'] = [i , j]
		else:
			nextS['L'] = [i, j - 1]

		if i == WORLD_SIZE - 1:
			nextS['D'] = [i , j]
		else:
			nextS['D'] = [i + 1, j]
		
		if j == WORLD_SIZE - 1:
			nextS['R'] = [i , j]
		else:
			nextS['R'] = [i , j + 1]

		nextState[i].append(nextS)

while True:
	newWorld  = np.zeros((WORLD_SIZE, WORLD_SIZE))
	for i in range(WORLD_SIZE):
		for j in range(WORLD_SIZE):
			if (i == 0 and j == 0) or (i == WORLD_SIZE - 1 and j == WORLD_SIZE - 1):
				continue
			for action in actions:
				newPosition = nextState[i][j][action]
				newWorld[i, j] += 0.25*(REWARD + GAMMA*world[newPosition[0], newPosition[1]])
	print(newWorld)
	if np.sum(np.abs(world - newWorld)) < 1e-4:
		print("Done")
		world = newWorld
		break	 
	world = newWorld

policy = np.zeros((WORLD_SIZE, WORLD_SIZE))

for i in range(WORLD_SIZE):
	for j in range(WORLD_SIZE):
		if (i == 0 and j == 0) or (i == WORLD_SIZE - 1 and j == WORLD_SIZE - 1):
			continue
		max_value = -1000
		max_action = 0
		index = 1
		for action in actions:
			newPosition = nextState[i][j][action]
			value = REWARD + GAMMA*world[newPosition[0], newPosition[1]]
			if value > max_value:
				max_value = value
				max_action = index
			index = index + 1
		policy[i, j] = max_action


print(policy)











