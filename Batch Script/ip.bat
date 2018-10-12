@ECHO OFF
ipconfig | findstr IPv4 > .\ip.txt
start .\ip.txt