# Uses python3 with pygame installed:
import pygame

pygame.init()

def text(screen, text, x, y, size = 50, color = (200, 200, 200)):
    text = str(text)
    fontobject = pygame.font.Font(None, size)
    text = fontobject.render(text, True, color)
    screen.blit(text, (x, y))
    
screen = pygame.display.set_mode((620, 140))
pygame.font.init()

while True:
    text(screen, "Hello, Pygame!", 10, 10, 100)
    pygame.display.flip()
    for event in pygame.event.get():
        if (event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE) or (event.type == pygame.QUIT):
            pygame.quit()
            break 
