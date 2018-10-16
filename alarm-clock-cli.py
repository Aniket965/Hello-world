'''
Alarm Clock CLI Client

Requirements:
vlc:            pip install vlc
mutagen:        pip install mutagen
python-crontab: pip install python-crontab
'''

import sys
import string
import vlc
import os
import getpass
from time import sleep
from mutagen.mp3 import MP3
from crontab import CronTab
import datetime


if len(sys.argv) < 2 or len(sys.argv) > 4:
    print("\nUsage: [ python ] alarm-clock-cli.py [option] h m")
    print("Example: [ python ] alarm-clock-cli.py 1 10 25")
    print("Example: [ python ] alarm-clock-cli.py 1 0 4")
    print("Example: [ python ] alarm-clock-cli.py 2")
    print("Use a value of 0 for testing the alarm immediately.")
    print("Example: [ python ] alarm-clock-cli.py 0")
    print("Plays mp3(only) file stored in cwd named as 'alarm.mp3'")
    print("Press Ctrl-C to terminate the alarm clock early.")
    sys.exit(1)

username = getpass.getuser()
script_path = os.path.abspath(sys.argv[0])

if int(sys.argv[1]) == 0:
    #print(os.path.dirname(script_path))
    alarm_file = vlc.MediaPlayer(os.path.join(os.path.dirname(script_path), "alarm.mp3"))
    alarm_file_length = MP3(os.path.join(os.path.dirname(script_path), "alarm.mp3")).info.length
    alarm_file.play()
    sleep(alarm_file_length)

elif int(sys.argv[1]) == 1:
    hours= int(sys.argv[2])
    minutes = int(sys.argv[3])
    
    print("Do yo want to schedule the alarm to ring daily/weekly? ('d' for daily, 'w' for weekly, skip for once): ")
    schedule_period = input()
    
    if schedule_period == 'd' or schedule_period == 'D':
        cron_task = CronTab(user=username)
        for job in cron_task:
        	if job.comment.startswith('alarm-clock-'):
        		last_idno = int(job.comment[12])
        next_idno=str(last_idno+1)
        job = cron_task.new(command='python ' + script_path + ' 0', comment='alarm-clock-' + next_idno)
        job.hour.on(hours)
        job.minute.on(minutes)
        job.day.every(1)
        #print(job.is_valid())
        cron_task.write()
        
    elif schedule_period == 'w' or schedule_period == 'W':
        print("Which day of the week? (0-6): ")
        dow = int(input())
        cron_task = CronTab(user=username)
        for job in cron_task:
        	if job.comment.startswith('alarm-clock-'):
        		last_idno = int(job.comment[12])
        next_idno=str(last_idno+1)
        job = cron_task.new(command='python ' + script_path + ' 0', comment='alarm-clock-' + next_idno)
        job.hour.on(hours)
        job.minute.on(minutes)
        job.dow.on(dow)
        cron_task.write()

    else:
        hours= int(sys.argv[2])
        minutes = int(sys.argv[3])
        now = datetime.datetime.now()
        total_seconds_left= (hours*60*60 + minutes*60) - (now.hour*60*60 + now.minute*60)
        alarm_file = vlc.MediaPlayer(os.path.join(os.path.dirname(script_path), "alarm.mp3"))
        alarm_file_length = MP3(os.path.join(os.path.dirname(script_path), "alarm.mp3")).info.length
        sleep(total_seconds_left)
        alarm_file.play()
        #print(os.path.dirname(script_path))
        sleep(alarm_file_length)

elif int(sys.argv[1]) == 2:
    cron_task = CronTab(user=username)
    flag = 0
    for job in cron_task:
        if job.comment.startswith('alarm-clock-'):
        	flag = 1
            print (job)
    if flag:
	    idno = input("Enter the id for the alarm to be deleted: ")
	    for job in cron_task:
	        if job.comment=='alarm-clock-'+idno:
	            cron_task.remove(job)
	            cron_task.write()
	else:
		print("No alarm set.")