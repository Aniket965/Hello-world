#!/usr/bin/python
import subprocess

from telegram import Bot

def execute(cmd):
    popen = subprocess.Popen(cmd, stdout=subprocess.PIPE, universal_newlines=True)

    for stdout_line in iter(popen.stdout.readline, ''):
        yield stdout_line.strip().split()

    popen.stdout.close()
    return_code = popen.wait()

    if return_code:
        raise subprocess.CalledProcessError(return_code, cmd)

def filter_and_send(line):
    bot.sendMessage(chat_id='<chat id>', text=line)
        
    
def main():
    print('Starting watcher ...')
    bot = Bot(token='<token>')
    bot.sendMessage(chat_id='<chat id>', text='Starting watcher ...')
    
    for line in execute(['minecraftd', 'console']):
        if "<name 1>" in line:
            filter_and_send(line)
        elif "<name 2>" in line:
            filter_and_send(line)
        elif "<name 3>" in line:
            filter_and_send(line)
        elif "<name 4>" in line:
            filter_and_send(line)
        elif "<name 5>" in line:
            filter_and_send(line)
            
if __name__ == '__main__':
    main()
