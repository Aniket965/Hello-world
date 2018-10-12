'''
Title: Temperature Converter Using Arg Parse
Author: Colin and Helena
Description: Convert temperature values from Fahrenheit to Celsius or vice
versa.



Usage:
python temps.py --scale fahrenheit --temp 32
python temps.py --scale fahrenheit --temp 212
python temps.py --scale celsius --temp 0
python temps.py --scale celsius --temp 100
'''
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--scale', type=str, choices = ['fahrenheit', 'celsius'],
                    default='fahrenheit')
parser.add_argument('--temp', type=float, required = True, help = 'Temperature')
args = parser.parse_args()

if args.scale == 'celsius':
    fahrenheit_temp = args.temp * (9/5) + 32
    message = 'Fahrenheit Temperature: {:.1f}'.format(fahrenheit_temp)

else:
    celsius_temp = (args.temp - 32) * (5 / 9)
    message = 'Celsius temperature: {:.1f}'.format(celsius_temp)

print(message)
