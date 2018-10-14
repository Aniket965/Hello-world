conversionRate = [1.13, 0.86, 0.86, 0.68]
bills = [20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1]


def read_input():
    print('Please select one of the following:')
    print('1: GBP to EUR\n2: USD to EUR\n3: CHF to EUR\n4: CAD to EUR')
    return int(input('Enter your choice: '))


def suggest_bills(amount):
    amount = int(100 * amount)
    print('Recommended bills and coins:')
    for value in bills:
        change = amount // value
        if change != 0:
            print('€{:5.1f}: {:d}'.format(value / 100, change))
        amount %= value


print('Currency to Euro Converter')
while True:
    selection = read_input()
    while selection > 4 or selection < -1:
        print('Invalid value.')
        selection = read_input()
    amt = int(input('\nPlease enter the amount for conversion: '))
    currency = ''
    if selection == 1:
        currency = 'Pound Sterlings (GBP)'
    elif selection == 2:
        currency = 'Dollars (USD)'
    elif selection == 3:
        currency = 'Swiss Franc (CHF)'
    else:
        currency = 'Canadian Dollars (CAD)'
    conversion = amt * conversionRate[selection - 1]
    print('You have chosen to convert {:s} to Euros (EUR)'.format(currency))
    print('The amount is equal to {:.2f} Euros'.format(conversion))
    suggest_bills(conversion)
    if input('\nWould you like to calculate another conversion? Y/N: ').lower() == 'n':
        break
    print('\n')
