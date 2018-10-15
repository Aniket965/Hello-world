@ECHO OFF
SET /a _rand=(%RANDOM%*6/32768)+1 
ECHO Dice rolled: %_rand%
@PAUSE