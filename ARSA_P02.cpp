#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu ();
void juego ();

int main()
{
    menu();
    srand (time(NULL));
    return 0;
}

void menu ()
{
	int op;
	
    do{
		system("CLS");
   		printf("Eligue una opcion:\n");
   		printf("presione 1 para jugar de piedra, papel o tijera (contra la IA)\n");
   		printf("presione 2 para salir\n");
   		scanf("%d",&op);
	  }while(op != 2); 
       system("PAUSE");           
}

void juego ()
{
	int j1, j2;
	system("CLS");
	printf("Elije una opcion::\n");
	printf("1. piedra\n2.papel\n3.tijera\n");
	scanf("%d",&j1);
	j2=(rand()%2-0);
	printf("\njugador 2 escoji la opcion: %d\n",j2);
	
	if ( j1 == j2 )
	{
		printf("\nEmpate, opciones identicas\n"); 
	}
	else
	{
		if ( j1 == 1)
		{
			if ( j2 == 2)
			{
				printf("\nplayer 2 (IA) win, papel le gana a piedra.\n");
			}
			else
			{
				printf("\nplayer 1 win, piedra le gana a tijera.\n");
			}
		}
		else
		{
			if ( j1 == 2 )
			{
				if ( j2 == 1)
				{
					printf("\nplayer 1 win, papel le gana a piedra.\n");
				}
				else 
				{
					printf("\nplayer 2 (IA) win, tijera le gana a papel.\n");
				}
			}
			else
			{
				if (j2 == 1)
				{
					printf("\nplayer 2 (IA) win, piedra le gana a tijera.\n");
				}
				else
				{
					printf("\nplayer 1 win, tijera le gana a papel.\n");
				}
			}
			
		}
	}
	system("PAUSE");   
}
