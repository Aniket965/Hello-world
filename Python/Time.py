import pygame
import datetime

pygame.init()

#size
display_width=400
display_height=200

#color
black=(0,0,0)
white=(255,255,255)
background=(86,50,45)

gameDisplay=pygame.display.set_mode((display_width,display_height))
gameDisplay.fill(background)
pygame.display.set_caption('Time')

#font_style
font = pygame.font.SysFont("Times New Roman", 24)

gameExit=False 
clock=pygame.time.Clock()

def Timee():
	now=datetime.datetime.now()
	year=now.year
	month=now.month
	hour=now.hour
	minute=now.minute
	second=now.second

	text = font.render("Year  Month  Hour  Min  Sec ",True,white)
	time=font.render(str(year)+"     "+str(month).zfill(2)+"      "+str(hour).zfill(2)+"       "+str(minute).zfill(2)+"     "+str(second).zfill(2),True,white)
	gameDisplay.blit(text,(45,50))
	gameDisplay.blit(time,(45,90))


while not gameExit:
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			pygame.quit()
			quit()
	Timee()
	pygame.display.update()
	gameDisplay.fill(background)
	clock.tick(1)

