StarWarsOpeningCrawl = '''A long time ago, in a galaxy far, far away...

It is a period of civil war. Rebel
spaceships, striking from a hidden
base, have won their first victory
against the evil Galactic Empire.

During the battle, Rebel spies managed
to steal secret plans to the Empire's
ultimate weapon, the Death Star, an
armored space station with enough
power to destroy an entire planet.

Pursued by the Empire's sinister agents,
Princess Leia races home aboard her
starship, custodian of the stolen plans
that can save her people and restore
freedom to the galaxy.... 

...and there is no 'j' nor 'z' nor even '!' in this text'''

StarWarsOpeningCrawl = StarWarsOpeningCrawl.lower()
StarWarsOpeningCrawl = list(StarWarsOpeningCrawl)
StarWarsOpeningCrawl.sort()

AtoZ_dict = {}
index = 0
index_2 = 25

for char in StarWarsOpeningCrawl:
    if char.isalpha():
        if char not in AtoZ_dict:
            AtoZ_dict[char] = index
            index += 1
    else:
        if char not in AtoZ_dict:
            AtoZ_dict[char] = index_2
            index_2 += 1

do_it_simple = 'Hello world!!'
like_a_boss = []


for letter in do_it_simple:
    like_a_boss.append(AtoZ_dict[letter.lower()])


space = ' '
for number in like_a_boss:
    if number == 26:
        space = ' '
    for key in AtoZ_dict.keys():
        if AtoZ_dict[key] == number:
            print(space+str(key.upper()))
            space += space
