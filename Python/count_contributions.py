import os

cpt = sum([len(files) for r, d, files in os.walk(".")])
print('\n' + str(cpt) + ' new files were created by the community!')
print('Happy Hacktoberfest 2018!')