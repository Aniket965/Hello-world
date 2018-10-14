import random

students = ['Sazida',
           'Salma',
           'Alaa',
           'Hessah',
           'Mariam',
           'Shorook',
           'Sammy',
           'Mohammad',
           'Fawaz',
           'Khaled',
           'May',
           ]

def get_random(names):
   rand = random.randint(0, len(names)-1)
   rando = names[rand]
   names.remove(rando)
   return rando


def pairs(names):
   pairs = []
   while len(names) >= 2:
       pairs.append([get_random(names), get_random(names)])
   if names:
       pairs.append([get_random(names)])
   
   for group in pairs:
       print (group)

pairs(students)
