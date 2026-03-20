#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main() {
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	char keyPress = 'w';
	char newKeyPress;
	int fruitX = 1;
	int fruitY = 1;
	int playerX = 5;
	int playerY = 5;
	int width = 20;
	int heigth = 10;
	int traces[width][heigth];
	int playerSize = 1;
	int x;
	int y;
	int oldX;
	int oldY; 
	int timer = 0;
	int timerDelay = 5000;
	int loser = 1;

	for (y = 0;y <= heigth;y++) {
	    for (x = 0;x <= width;x++) {
	    	traces[x][y] = 0;
		}
	}
	
    while (loser) {
        if (_kbhit()) {
        	newKeyPress = _getch();
        	if (keyPress == 'w' && newKeyPress != 's') keyPress = newKeyPress;
        	if (keyPress == 's' && newKeyPress != 'w') keyPress = newKeyPress;
        	if (keyPress == 'a' && newKeyPress != 'd') keyPress = newKeyPress;
        	if (keyPress == 'd' && newKeyPress != 'a') keyPress = newKeyPress;
		}
        
        timer += 1;
        if (timer >= timerDelay) {
        	timer = 0;
        	
        	if (keyPress == 'w' && playerY <= 0) playerY = heigth-1;
			else {
				if (keyPress == 'w') playerY = playerY-1;
			}
			
            if (keyPress == 'a' && playerX <= 0) playerX = width-1;
			else {
				if (keyPress == 'a') playerX = playerX-1;
			}
			
            if (keyPress == 's' && playerY > heigth-2) playerY = 0;
			else {
				if (keyPress == 's') playerY = playerY+1;
			}
			
            if (keyPress == 'd' && playerX > width-2) playerX = 0;
			else {
				if (keyPress == 'd') playerX = playerX+1;	
			} 
		}
		
		if (playerX != oldX || playerY != oldY) {
            system("cls");
            
            for (y = 0;y < heigth;y++) {
                for (x = 0;x < width;x++) {
                	if (fruitX == x && fruitY == y) {
                		if (playerX == x && playerY == y || traces[x][y] >= 1 && traces[x][y] <= playerSize) {
                			if (playerX == x && playerY == y) {
                				printf("O");
                				playerSize = playerSize+1;
                			}
		
                			if (traces[x][y] >= 1 && traces[x][y] <= playerSize) printf("*");
                			
                			fruitX = rand() % width;
                			fruitY = rand() % heigth;
						} else printf("x");
					} else {
                    	if (traces[x][y] >= 1 && traces[x][y] <= playerSize) {
                    		if (playerX == x && playerY == y) loser = 0;
                    		printf("*");
                    		traces[x][y] += 1;
						} else {
							if (traces[x][y] >= playerSize) traces[x][y] = 0;
							if (playerX == x && playerY == y) printf("O");
							else printf(".");
						}
					}
                }
                printf("\n");
            }
            
            printf("\nSCORE: %i", playerSize);
            
            if (playerX < width && playerY < heigth) {
	            oldX = playerX;
	            oldY = playerY;
	            traces[playerX][playerY] = 1;
			}
        }
    }
    
    printf("\nFim de jogo\n\n");
}
