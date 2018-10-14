**************************************************************
* NES Hello World
* Made by Pedro A. Fabri - https://github.com/pedroafabri
* Based on Nerdy Nights Tutorials:
*	http://nintendoage.com/forum/messageview.cfm?catid=22&threadid=7155
**************************************************************

How to see the Hello World:
	It's basically a game, so you just need to open "helloworld.nes" with your NES emulator of choice!

Source Files:
	scr/helloworld.asm - 6502 Assembly file. All the logic is there.
	src/mario.chr - CHR file extracted from Super Mario Bros 1. It contains all the sprites of the game!

How to compile:
	> Download NESASM3.exe. It's the 6502 compiler. Sadly I only have the windows version of it. I don't know anything about linux versions...
	  Link: http://nespowerpak.com/nesasm/
	> Put NESASM3.exe at /src folder
	> cd /src
	> NESASM3 helloworld.asm
	> TaaDaa!