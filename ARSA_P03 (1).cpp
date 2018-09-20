/**/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void menu(void);
void verdadero(void); 
void falso(void);
void arbol(void);

int main ()
{
	menu();
	return 0;
	
}

void menu()
{
   int op;
   
   do{
      system ("cls");
      printf("\n M  E   N   U");
	  printf("\n1.- ANIDADO POR EL VERDADERO");
	  printf("\n2.- ANIDADO POR EL FALSO");
	  printf("\n3.- ARBOL(OPTIMIZADO)");
	  printf("\n4.- Salir");
	  printf("\nESCOGE UNA OPCION.\n");
      scanf ("%d",&op);
      
	  switch(op)
	    {
		  case 1: verdadero();   break;
		  case 2: falso();   break;
		  case 3: arbol();   break;
		  default:
		  printf("error, opcion invalida");
		}
   }while(op != 4);
}

void falso()
{
	int cal1,cal2,cal3;
	float prom;
	printf("Ingresa cal 1: ");
	scanf("%d",&cal1);
	printf("Ingresa cal 2: ");
	scanf("%d",&cal2);
	printf("Ingresa cal 3: ");
	scanf("%d",&cal3);
	prom=(cal1+cal2+cal3)/3;
	
if ( prom < 30 )
{
	printf("Repetir, Tu Promedio es %.2f",prom);
}
else
{
	if ( prom < 60 )
	{
		printf("Extraordinario, Tu Promedio es %.2f",prom);
	}
	else
	{
		if ( prom < 70 )
		{
			printf("Suficiente, Tu Promedio es %.2f",prom);
		}
		else
		{
			if ( prom < 80 )
			{
				printf("Regular, Tu Promedio es %.2f",prom);
			}
			else
			{
				if ( prom < 90 )
				{
					printf("Bien, Tu Promedio es %.2f",prom);
				}
				else
				{
					if ( prom < 96 )
					{
						printf("Muy bien, Tu Promedio es %.2f",prom);
					}
					else
					{
						if ( prom <= 100 )
						{
							printf("Excelente, Tu Promedio es %.2f",prom);
						}
						else
							{
								printf("Error, Tu Promedio es %.2f",prom);
							}
					}
				}
			}
		}
	}
}
printf("\n\n");
system ("PAUSE");
}


void verdadero()
{
	int cal1,cal2,cal3;
	float prom;
	printf("ingrese su primera calificacion:");
	scanf("%d",&cal1);
	printf("ingrese su segunda calificacion:");
	scanf("%d",&cal2);
	printf("ingrese su tercera calificacion:");
	scanf("%d",&cal3);
	prom= (cal1+cal2+cal3)/3;
	
	if ( prom <= 100 )
	   {
	   	if ( prom < 96 )
	   	   {
	   	   	if ( prom < 90 )
	   	   	   {
	   	   	   	if ( prom < 80 )
	   	   	   	   {
	   	   	   	   	if ( prom < 70 )
	   	   	   	   	   {
	   	   	   	   	   	if ( prom < 60 )
	   	   	   	   	   	   {
	   	   	   	   	   	   	if ( prom < 30 )
	   	   	   	   	   	   	   {
	   	   	   	   	   	   	   	printf("Repetir, Tu Promedio es %.2f\n",prom);
														}
													  else
													   {
													   	printf("Extraordinario, Tu Promedio es %.2f\n",prom);
														}
												}
											  else
											   {
											   	printf("Suficiente, Tu Promedio es %.2f\n",prom);
												}
										}
									  else
									   {
									   	printf("Regular, Tu Promedio es %.2f\n",prom);
										}
								}
							  else
							   {
							   	printf("Bien, Tu Promedio es %.2f\n",prom);
								}
						}
					  else
					   {
					   	printf("Muy bien, Tu Promedio es %.2f\n",prom);
						}
				}
			  else
			   {
			   	printf("Excelente!!, Tu Promedio es %.2f\n",prom);	
				}
		}
	  else
	   {
	   	printf("Error, Tu Promedio es %.2f\n",prom);
		}
	system("pause");
		
}

void arbol()
{
	int cal1,cal2,cal3;
	float prom;
	printf("Ingresa cal 1: ");
	scanf("%d",&cal1);
	printf("Ingresa cal 2: ");
	scanf("%d",&cal2);
	printf("Ingresa cal 3: ");
	scanf("%d",&cal3);
	prom=(cal1+cal2+cal3)/3;
	
if ( prom < 80 )
{
	if ( prom < 60 )
	{
		if ( prom < 30 )
		{
			printf("Repetir, Tu Promedio es %.2f",prom);
		}
		else
		{
			printf("Extraordinario, Tu Promedio es %.2f",prom);
		}
	}
	else
	{
		if ( prom < 70 )
		{
			printf("Suficiente, Tu Promedio es %.2f",prom);
		}
		else
		{
			printf("Regular, Tu Promedio es %.2f",prom);
		}
	} 
}
else
{
	if ( prom < 96 )
	{
		if ( prom < 90 )
		{
			printf("Bien, Tu Promedio es %.2f",prom);
		}
		else
		{
			printf("Muy bien, Tu Promedio es %.2f",prom);
		}
	}
	else
	{
		if ( prom > 100 )
		{
			printf("Tu Promedio es %.2f, Error!!!!!",prom);
		}
		else
		{
			printf("Excelente!!, Tu Promedio es %.2f",prom);
		}
	} 
}
printf("\n\n");
system ("PAUSE");
}


