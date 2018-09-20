#include <conio.h>
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define MAX 4
#define TRUE 1

void Menu(void);
void Generar_Vector( int Vector[] , int ri , int rs );
void Imprimir( int tam, int M[][MAX] );
void Generar_Vector2( int Vector[] , int ri , int rs );
void Suma_Matriz( int Matriz1[][MAX], int Matriz2[][MAX], int MatrizS[][MAX], int tam );
void Trans( int Matriz4[][MAX], int Matriz3[][MAX], int n );
void Generar_Matriz( int Matriz1[][MAX], int Vector[], int n );
int Validar(int ri,int rs);

int main (void)
{
   	Menu();
   
   	return 0;
}


void Menu(void)
{
	int op;
	srand(time(0));
	int Matriz1[MAX][MAX] ;
	int Matriz2[MAX][MAX] ;
	int Matriz3[MAX][MAX] ;
	int Matriz4[MAX][MAX] ;
	
	int Vector[MAX*MAX] ;
	int Vector2[MAX*MAX] ;
	
	int Ward1 = FALSE;
	int Ward2 = FALSE;
	int Ward3 = FALSE;
	int Ward4 = FALSE;
   
   do{
   	
      system ("cls");
      printf("\t MENU \n");
      puts("1.- Matriz 1. Llenar Aleatoriamente.");
      puts("2.- Matriz 2. Llenar Aleatoriamente.");
      puts("3.- Matriz 3. Suma de Matrices 1 y 2.");
      puts("4.- Matriz 4. Matriz transpuesta de Matriz 3.");
      puts("5.- Imprimir TODAS las Matrices.");
      puts("6.- Salir.");
      
      op = Validar( 1, 6 );
      
	  switch(op)
	    {
	    	case 1:
	    		Generar_Vector( Vector, 1, 20 );
	    		Generar_Matriz( Matriz1, Vector, MAX );
	    		Ward1 = TRUE;
	    		Ward3 = FALSE;
	    		printf("\nDoneso ... \n");
	    		system("pause");
	    		break;
	    		
	    	case 2:	
	    		Generar_Vector2( Vector2, 1, 16 );
		   		Generar_Matriz( Matriz2, Vector2, MAX );
		   		Ward2 = TRUE;
		   		Ward3 = FALSE;
		    	printf("\nDoneso ... \n");
	    		system("pause");
	    		break;
	    		
	    	case 3:
	    		if( Ward1 == TRUE && Ward2 == TRUE )
	    		{
	    			if( Ward3 == FALSE )
	    			{
	    				Suma_Matriz( Matriz1, Matriz2, Matriz3, MAX );
		    			Ward3 = TRUE;
		    			Ward4 = FALSE;
			    		printf("\nDoneso ... \n");
					}
					else
					{
						puts("Ya creado");
					}
				}
				else
				{
					puts("Opcion no habilida");
				}
				
	    		system("pause");
	    		break;
	    		
	    	case 4:
	    		if( Ward3 == TRUE )
	    		{
	    			if( Ward4 == FALSE )
	    			{
	    				Trans( Matriz4, Matriz3, MAX );
		    			Ward4 = TRUE;
			    		printf("\nDoneso ... \n");
					}
					else
					{
						puts("Ya creado.");
					}
	    			
				}
				else
				{
					puts("Opcion no habilida");
				}
	    		
	    		system("pause");
	    		break;
	    		
	    	case 5:
	    		if( Ward1 == TRUE && Ward2 == TRUE && Ward3 == TRUE && Ward4 == TRUE )
	    		{
	    			system("cls");
		    		printf("Matriz 1: \n \n");
		    		Imprimir( MAX, Matriz1 );
		    		printf("Matriz 2: \n \n");
		    		Imprimir( MAX, Matriz2 );
		    		printf("Matriz 3: \n \n");
		    		Suma_Matriz( Matriz1, Matriz2, Matriz3, MAX );
		    		Imprimir( MAX, Matriz3 );
		    		printf("Matriz 4: \n \n");
		    		Trans( Matriz4, Matriz3, MAX );
		    		Imprimir( MAX, Matriz4 );
		    		system("pause");
				}
				else
				{
					puts("Opcion no habilida");
					system("pause");
				}
	    		
	    		break;
		} 
		
   }while( op != 6 );
}

void Generar_Vector( int Vector[] , int ri , int rs )
{
	int i, j, num, repetido ;
	
	for( i = 0 ; i < MAX*MAX ; i++ )
	{
		do{
			
			num = rand() % ( rs - ri ) + ri ;
			j = 0 ;
			repetido = FALSE ;
			
			while( (j < i ) && (repetido == FALSE ) )
			{
				if( Vector[j] == num )
				{
					repetido = TRUE ;
				}
				else
				{
					j++ ;
				}
			}
			
		}while( repetido == TRUE );
		
		Vector[i] = num ;
		
	}
}

void Generar_Matriz( int Matriz1[][MAX], int Vector[], int n )
{
	int i, j ;
	int k = 0 ;
	
	for( i = 0 ; i < n ; i++ )
	{
		for( j = 0 ; j < n ; j++ )
		{
			Matriz1[i][j] = Vector[k];
			k++;
		}
	}
}

void Imprimir( int tam, int M[][MAX] )
{
	int i, j;
	
	for( i = 0 ; i < tam ; i++ )
	{
		for( j = 0 ; j < tam ; j++)
		{
			printf("\t%d",M[i][j] );
		}
		
		printf("\n");
	}
	
	printf("\n \n");
}

void Generar_Vector2( int Vector[] , int ri , int rs )
{
	int i, j, num, repetido ;
	int Ward = 0 ;
	
	for( i = 0 ; i < MAX*MAX ; i++ )
	{	
		do{
			
			num = rand() % ( rs - ri ) + ri ;
			j = 0 ;
			repetido = FALSE ;
			
			while( ( j < i ) && ( repetido == FALSE ) )
			{
				if( Vector[j] == num )
				{
					Ward++;
					
					if( Ward > 1 )
					{
						repetido = TRUE ;
					}
					else
					{
						j++;
					}
				}
				else
				{
					j++ ;
				}
			}
			
		}while( repetido == TRUE );
		
		Vector[i] = num ;
		
		Ward = 0;
		
	}
}

void Suma_Matriz( int Matriz1[][MAX], int Matriz2[][MAX], int MatrizS[][MAX], int n )
{
	int i, j ;
	
	for( i = 0 ; i < n ; i++ )
	{
		for( j = 0 ; j < n ; j++ )
		{
			MatrizS[i][j] = Matriz1[i][j] + Matriz2[i][j] ;
		}
	}
}

void Trans( int Matriz4[][MAX], int Matriz3[][MAX], int n )
{
	int i, j ;
	
	for( i = 0 ; i < n ; i++ )
	{
		for( j = 0 ; j < n ; j++ )
		{
			Matriz4[i][j] = Matriz3[j][i];
		}
	}
}

int Validar(int ri,int rs)
{
	char xnum[10] ;
	int num ;
	
	do{		
	
			fflush(stdin);
			gets(xnum);
			
			num = atoi(xnum);
			
			if( num < ri || num > rs )
			{
				printf("Seleccion invalida...\n");
				system("pause");
			}
	
		}while( num < ri || num > rs );
	
	return num;
	
}

