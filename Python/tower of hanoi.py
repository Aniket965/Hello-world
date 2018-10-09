def moveTower(height,source, destination, helper):
    if height >= 1:
        moveTower(height-1,source,helper,destination)
        moveDisk(source,destination)
        moveTower(height-1,helper,destination,source)

def moveDisk(s,d):
    print("Moving disk from",s,"to",d)

moveTower(4,"A","B","C")
