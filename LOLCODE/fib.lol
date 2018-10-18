HAI 1.2                                                     BTW Opens LOLCODE program

HOW IZ I fib YR numbr                                       BTW This is a Function
  I HAS A a ITZ A NUMBR                                     BTW Initialize some useful variables
  I HAS A b ITZ A NUMBR
  I HAS A c ITZ A NUMBR

  a R 0                                                     BTW assign a value to a
  b R 1                                                     BTW assign a value to b

  BOTH SAEM numbr AN 0, O RLY?                              BTW If user entered 0
    YA RLY, FOUND YR a                                      BTW Return 0
  OIC                                                       BTW End if

  I HAS A end ITZ SUM OF numbr AN 1
  IM IN YR loop UPPIN YR var TIL BOTH SAEM var AN end       BTW Begin for loop
    BOTH SAEM var AN BIGGR OF var AN 2, O RLY?              BTW Skips when var < 2
      YA RLY,
        c R SUM OF a AN b
        a R b
        b R c
    OIC
  IM OUTTA YR loop                                          BTW Closes the loop

  FOUND YR b                                                BTW Returns final number in sequence
IF U SAY SO                                                 BTW Closes function

I HAS A numbr                                               BTW Initialize var 'numbr'
VISIBLE "GIMMEH NUMBR"                                      BTW Requests input from user
GIMMEH numbr                                                BTW Sets var 'numbr' from input
numbr R MAEK numbr NUMBR                                    BTW Casts var 'numbr' to NUMBR (int)

DIFFRINT numbr AN BIGGR OF numbr AN 0, O RLY?               BTW Checks for negative input
  YA RLY,
    VISIBLE "NO U! NEGATIV NUMBRZ NOT OK!"                  BTW Tell off the user
    GTFO                                                    BTW Exit
OIC

VISIBLE I IZ fib YR numbr MKAY                              BTW Calls fib, passing in 'numbr'

KTHXBYE                                                     BTW Closes LOLCODE program
