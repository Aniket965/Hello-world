class Player:
    def __init__(
            self,
            username: str,
            player_class,
    ):
        self.username = username
        self.invetory = Inventory()
        self.player_class = player_class
        self.skills = None
        self.gender = None
        self._count = 0
        self.directions = {
            'start': {
                'forest':
                    'You are in a forest, look around... the silence, the trees, you are trying'
                    'to figure how you came here, how this even happened to you'
                    ', but the only thing you know, is that you are about to start your path'
                    ', please, just follow your lead here, you are alone now.\n\n Type the command: ',
            },
            'north': [{
                'Palace of Nather': {
                    'Description': 'bla bla bla bla',
                    'Items': {
                        'rope': 1,
                        'gold': 0.2,
                        'arrows': 1
                    },
                    'Options': [],
                    'Enemies': {}
                }
            }, {
                'Wiz Khalifa Santuary': {
                'Description': 'bla bla bla bla',
                'Items': {
                    'rope': 1,
                    'gold': 0.2,
                    'arrows': 1
                },
                'Options': [],
                'Enemies': {
                    'The big Joint': {
                        'hp': 300,
                        'level': 15,
                        'items': {
                            'gold': 150
                        }
                    }
                }
            }}
            ],
            'south': {

            },
            'east': {

            },
            'west': {

            },

        }

        self.CHAR_CLASSES = {
            'WIZARD': {
                'HP': 100,
                'INTELLIGENCE': 60,
                'PHYSICAL': 10,
                'SKILLS': 80,
                'SPEED': 30,
                'HEAVY_WEAPONS': 5
            },
            'FIGHTER': {
                'HP': 100,
                'INTELLIGENCE': 10,
                'PHYSICAL': 70,
                'SKILLS': 30,
                'SPEED': 70,
                'HEAVY_WEAPONS': 40
            },
            'ORC': {
                'HP': 100,
                'INTELLIGENCE': 10,
                'PHYSICAL': 90,
                'SKILLS': 5,
                'SPEED': 20,
                'HEAVY_WEAPONS': 90
            },
        }
        self.actual_location = self.directions['start']['forest']

    def set_username(self, new_username):
        self.username = new_username

    @property
    def show_own_invetory(self):
        return self.invetory.show_attributes()

    def player_class_selection(
            self,
            char_class_picked: str
    ):
        self.player_class = char_class_picked

    def set_skills(self):
        name_of_the_char_class = self.player_class
        self.skills = self.CHAR_CLASSES[name_of_the_char_class]

    def traveling(self, direction):
        possible_directions = self.directions.keys()
        if direction not in possible_directions:
            return 'Not a valid direction'
        else:
            self._change_location(direction)

    def _change_location(self, direction):
        number_of_places_direction_has = len(self.directions[direction])
        if self._count == number_of_places_direction_has:
            return 'you should go back'
        else:
            self._count += 1
            self.actual_location = self.directions[direction][self._count]

    @property
    def catch_actual_location(self):
        return self.actual_location


class Inventory:
    def __init__(
            self,
            rope: int = 0,
            leather: int = 0,
            meat: int = 0,
            gold: int = 0,
            arrows: int = 0
    ):
        self.rope = rope
        self.leather = leather
        self.meat = meat
        self.gold = gold
        self.arrows = arrows

    def add_to_attribute(
            self,
            attr,
            quantity: int = 0
    ):
        if hasattr(self, attr):
            sum_of_old_and_new_quantity = self.__getattribute__(attr) + quantity
            self.__setattr__(attr, sum_of_old_and_new_quantity)
        else:
            raise AttributeError

    @property
    def show_attributes(self):
        return (
            f'Rope: {self.rope} \n' 
            f'Leather: {self.leather}\n'
            f'Meat: {self.meat}\n'
            f'Gold: {self.gold}\n'
            f'Arrows: {self.arrows}\n'
        )


class Journey:
    def __init__(self):
        self.player = None


    def get_player(self, username, char_class):
        self.player = Player(
            username=username,
            player_class=char_class
        )
        return self.player


if __name__ == '__main__':
    from time import sleep
    input_username = input('insert the name of your character: ')
    sleep(2)
    print(
        f'Hello {input_username.capitalize()}, It is now your turn to become '
        f'a legend! Please choose your class: \n'
    )
    setting_player = Journey()
    player = setting_player.get_player(
        username=input_username,
        char_class=None
    )
    list_of_char_classes = list(setting_player.player.CHAR_CLASSES.keys())
    sleep(2)
    for char_classes in list_of_char_classes:
        print(f'{list_of_char_classes.index(char_classes) + 1} - {char_classes}')
        sleep(0.5)
    input_class = int(input('Select now your class warrior! The number please: '))
    player.player_class = list_of_char_classes[input_class - 1]
    player.set_skills()
    print(f'\nYou choose the {player.player_class} class, look at your statuses: \n')
    for status, value in player.CHAR_CLASSES[list_of_char_classes[input_class - 1]].items():
        print(f'{status}: {value}')
    sleep(4)
    print(
          '\nWell done soldier! Now you are able to start the most'
          ' incredible adventures in the world!'
    )

    print('LOADING ...')
    sleep(4)
    print(
        '\nThis is your first world, prepare to find '
        'tones of kinds of creatures on your way. \n'
        'You may think this is insane, but the truth is: '
        'No one ever returned back from this quest. \n'
        'If you think now is the right time for you to ',
        'make something great, this challenge is for you. \n'
    )
    print('*'*40 + '\n')
    sleep(2)
    print(
        'First you need the instructions, here I will show how to play.\n'
        'For every action you may take, questions will be showed for you'
        ', that means you have to choose according to instructions in screen.\n'
        ' For instance: \n'
    )
    command = ''
    print(f'Your actual location is {player.catch_actual_location}')
    while command != 'exit':
        command = input(' >>> ')
        if command == 'look':
            print(location)
        elif command == 'north':
            location = player.catch_actual_location
            player.traveling('north')
            for title in location.keys():
                print(f'Welcome to {title.upper()}:\n'
                      f'{location[title]}')







