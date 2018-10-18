# Making Turner Cube Calculations using 2 methods to gather user input then calculate the rest of the parameters

from math import sqrt


class TurnerCube:

    def __init__(self, largest_cube=0.0, layers=0):
        self.largest_cube = largest_cube
        self.layers = layers

    def layer_count(self, total_layers):
        self.layers += total_layers
        return self.layers


# Input largest cube size
# let ci represent 'cube instance' meaning the cube being defined by the user

ci = TurnerCube(float(input('What size do you want the largest cube to be:')))

# Input the total number of layers
ci.layer_count(int(input('How many total layers do you want:')))

# Storing size diff = largest cube/ smallest cube with 3 decimal place rounding float
size_diff = float(("%.3f" % (ci.largest_cube / ci.layers)))
print('The size difference between each cube will be:', size_diff, 'inches')

# defining equations relying on once the  largest_cube, layers  and size_diff have been defined
middle_cube = float(("%.3f" % (ci.largest_cube - size_diff)))
smallest_cube = float(("%.3f" % (middle_cube - size_diff)))
print('Cube sizes in descending order:', ci.largest_cube, middle_cube, smallest_cube)

# Defining the Corner to Corner Cube Distances

ccd_middle = float("%.3f" % (sqrt(middle_cube ** 2 + middle_cube ** 2)))
ccd_smallest = float("%.3f" % (sqrt(smallest_cube ** 2 + smallest_cube ** 2)))
print("The corner to corner distance has to have the following relationship\n")
print("undercut > corner to corner distance > bore diameter")
print(ccd_middle, ccd_smallest)

# Defining Bore depth

print("To find the Depth of the bores take:\n ")
print("((largest cube - (size of cube you are boring to) / 2)")
middlecube_bd = ("%.3f" % ((ci.largest_cube - middle_cube) / 2))
smallestcube_bd = ("%.3f" % ((ci.largest_cube - smallest_cube) / 2))

print(middlecube_bd, smallestcube_bd)
