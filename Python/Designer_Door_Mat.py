def print_designer_door_mat(hight, width):
    pattern = ".|."
    door_list = []
    pattern_hight = 0

    for i in range(1, hight, 2):
        door_list.append(pattern * i)
        pattern_hight  += 1

    for i in range(pattern_hight):
        print(door_list[i].center(width, "-"))

    print("WELCOME ALLIENS".center(width, "-"))

    for i in range(pattern_hight - 1, -1, -1):
        print(door_list[i].center(width, "-"))


if __name__ == "__main__":
    inp = input()
    data = inp.split(" ")
    print_designer_door_mat(int(data[0]), int(data[1]))
