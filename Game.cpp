#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<conio.h>
#include<time.h>
#include<ctype.h>
void classic();
void countdown();


/*char grid[20][40]={
    {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' '},
    {'|', 'O', ' ', ' ', 'o', 'X', 'o', ' ', ' ', ' ', ' ', ' ', 'X', 'o', ' ', ' ', '|'},
    {'|', 'X', 'X', 'X', ' ', 'X', 'X', ' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', ' ', '|'},
    {'|', 'o', ' ', ' ', ' ', ' ', 'o', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', '|'},
    {'|', 'X', 'X', 'X', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X', ' ', 'o', ' ', '|'},
    {'|', 'X', 'o', ' ', ' ', ' ', ' ', 'X', 'o', 'X', ' ', ' ', ' ', ' ', 'X', 'X', '|'},
    {'|', ' ', ' ', 'X', 'X', 'o', 'X', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'o', '|'},
    {'|', ' ', 'X', 'o', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'o', 'X', ' ', '|'},
    {'|', ' ', 'X', 'X', ' ', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', 'X', 'X', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', ' ', 'X', ' ', '|'},
    {'|', 'o', 'X', 'X', 'X', 'X', 'X', 'o', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'o', '|'},
    {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' '}};*/

int main()
{
    char choice;
    system("cls");
    printf("Note: You can exit to this menu screen at any time by pressing Shift + 'E'\n\nPlease choose a gamemode:\n[1] Classic\n[2] Move countdown\n\n");
    choice = getch();
    system("cls");
    if(choice=='1')
    {
        classic();
    }
    else if(choice=='2')
    {
        countdown();
    }
    else
    {
        main();
    }
}

void classic()
{
    int x, y, xpos=1, ypos=1, xmovement, ymovement, score=0, random, random2, moves=0;
    char move, playagain, grid[20][40];
    srand(time(NULL));
    for(x=0;x<40;x++)
    {
        for(y=0;y<20;y++)
        {
        	if(y==0||y==19)
        	{
        		grid[y][x]='_';
        	}
        	else if(x==0||x==39)
        	{
        		grid[y][x]='|';
        	}
        	else
        	{
	        	random = rand() % 10;
	            if(random==1||random==3)
	            {
	                grid[y][x]=177;
	            }
	            else
	            {
	                grid[y][x]=' ';
            	}
        	}
        }
    }
    for(x=0;x<25;x++)
    {
		random = rand() % 18;
		random2 = rand() % 38;
		random+=1, random2+=1;
		grid[random][random2]='o';
	}
	//printf("**YOU START IN THE TOP LEFT CORNER**\n");
    grid[1][1]=219;
    while(true)
    {
    	int xmovement=0, ymovement=0;
    	printf("Gather 20 Rings\nUse WASD to Move\nPress the X Key to Regenerate Arena\n");
        for(x=0;x<20;x++)
        {
                         for(y=0;y<40;y++)
                         {
                                          printf("%c", grid[x][y]);
                         }
                         printf("\n");
        }
        if(score==20)
        {
                     break;
        }
        printf("Collected: %d\nMoves: %d ", score, moves);
        fflush(stdin);
        move=getch();
        system("cls");
        if(move=='E')
        {
                     main();
                     break;
        }
        move=tolower(move);
        if(move=='w')
	    {
	        ymovement=-1;
	    }
	    else if(move=='s')
	    {
	        ymovement=1;
	    }
	    else if(move=='a')
	    {
	        xmovement=-1;
	    }
	    else if(move=='d')
	    {
	    	xmovement=1;
	    }
	    else if(move=='x')
	    {
	        classic();
	    }

		if(grid[ypos+ymovement][xpos+xmovement]==' '||grid[ypos+ymovement][xpos+xmovement]=='o')
        {
            if(grid[ypos+ymovement][xpos+xmovement]=='o')
            {
                                                         score+=1;
            }
	        grid[ypos][xpos]=' ';
	        if(move=='w')
	        {
	                     ypos-=1;
	        }
	        else if(move=='s')
	        {
	                     ypos+=1;
	        }
	        else if(move=='a')
	        {
	                     xpos-=1;
	        }
	        else if(move=='d')
	        {
	                     xpos+=1;
	        }
	        grid[ypos][xpos]=219;
	        moves += 1;
         }
    }
    system("cls");
    printf("You won! Congratulations!\n\n\n\nWould you like to play again? Y/N: ");
    do
    {
        system("cls");
        printf("You won! Congratulations!\n\n\n\nWould you like to play again? Y/N: ");
        playagain = getch();
    }while(playagain!='y'&&playagain!='n'&&playagain!='E'&&playagain!='y'&&playagain!='n');
    if(tolower(playagain)=='y')
    {
        main();
    }
    else if(playagain=='E')
    {
        main();
    }
    system("cls");
    exit(0);
}

void countdown()
{
    int x, y, xpos=1, ypos=1, xmovement, ymovement, score=0, random, random2, moves;
    char move, choice, playagain, grid[20][40];
    printf("Select number of moves:\n[1] 25\n[2] 50\n[3] 75\n[4] 100\n[5] 125\n[6] 150\n[7] 200\n[8] Custom\n\n");
    choice = getch();
    system("cls");
    switch(choice)
    {
                           case '1':
                                moves = 25;
                                break;
                           case '2':
                                moves = 50;
                                break;
                           case '3':
                                moves = 75;
                                break;
                           case '4':
                                moves = 100;
                                break;
                           case '5':
                                moves = 125;
                                break;
                           case '6':
                                moves = 150;
                                break;
                           case '7':
                                moves = 200;
                                break;
                           case '8':
                                do{
                                printf("Enter the number of moves you would like: ");
                                scanf("%d", &moves);
                                fflush(stdin);
                                }while(moves<5||moves>1000);
                                break;
                           case 'E':
                                main();
                           default:
                                system("cls");
                                printf("Invalid, moves set to 100. ");
                                system("pause");
                                moves=100;
                                break;
    }
                           
    srand(time(NULL));
    for(x=0;x<40;x++)
    {
        for(y=0;y<20;y++)
        {
        	if(y==0||y==19)
        	{
        		grid[y][x]='_';
        	}
        	else if(x==0||x==39)
        	{
        		grid[y][x]='|';
        	}
        	else
        	{
	        	random = rand() % 10;
	            if(random==1||random==3)
	            {
	                grid[y][x]=177;
	            }
	            else
	            {
	                grid[y][x]=' ';
            	}
        	}
        }
    }
    for(x=0;x<25;x++)
    {
		random = rand() % 18;
		random2 = rand() % 38;
		random+=1, random2+=1;
		grid[random][random2]='o';
	}
	//printf("**YOU START IN THE TOP LEFT CORNER**\n");
    grid[1][1]=219;
    while(true)
    {
    	int xmovement=0, ymovement=0;
    	printf("Gather as many rings as you can\nUse WASD to Move\nPress the X Key to Regenerate Arena\n");
        for(x=0;x<20;x++)
        {
                         for(y=0;y<40;y++)
                         {
                                          printf("%c", grid[x][y]);
                         }
                         printf("\n");
        }
        printf("Collected: %d\nMoves left: %d ", score, moves);
        fflush(stdin);
        move=getch();
        system("cls");
        if(move=='E')
        {
            main();
            break;
        }
        else if(moves==0)
        {
             break;
        }
        move=tolower(move);
        if(move=='w')
	    {
	        ymovement=-1;
	    }
	    else if(move=='s')
	    {
	        ymovement=1;
	    }
	    else if(move=='a')
	    {
	        xmovement=-1;
	    }
	    else if(move=='d')
	    {
	    	xmovement=1;
	    }
	    else if(move=='x')
	    {
	        countdown();
	    }

		if(grid[ypos+ymovement][xpos+xmovement]==' '||grid[ypos+ymovement][xpos+xmovement]=='o')
        {
            if(grid[ypos+ymovement][xpos+xmovement]=='o')
            {
                                                         score+=1;
            }
	        grid[ypos][xpos]=' ';
	        if(move=='w')
	        {
	                     ypos-=1;
	        }
	        else if(move=='s')
	        {
	                     ypos+=1;
	        }
	        else if(move=='a')
	        {
	                     xpos-=1;
	        }
	        else if(move=='d')
	        {
	                     xpos+=1;
	        }
	        grid[ypos][xpos]=219;
	        moves -= 1;
         }
    }
    do
    {
        system("cls");
        printf("Game over! Final score: %d!\n\n\n\nWould you like to play again? Y/N: ", score);
        playagain = getch();
    }while(playagain!='y'&&playagain!='n');
    if(tolower(playagain)=='y')
    {
                               main();
    }
    system("cls");
    exit(0);
}
