/* practica #2*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void menu();
void funcion1();
void funcion2();
void funcion3();

int main ()
{
	
	
	 menu();
	getch();
	return 0;
}

void menu()
{
		int opc;
		printf("ingrese la opcion que desea utilizar: \n 1 mostrar el numero mayor \n 2 mostrar el menor \n 3 mostrar los numeros de forma acendente ");
		scanf("%d",&opc);
		
		switch (opc)
		{
			case 1: funcion1(); break;
			case 2: funcion2(); break;
			case 3: funcion3(); break;
		}
	
}

void funcion1()
{
	int num1,num2,num3;
	system("cls");
	printf("ingrese el primer numero:");
	scanf("%d",&num1);
	printf("ingrese el segundo numero numero:");
	scanf("%d",&num2);
	printf("ingrese el tercer numero numero:");
	scanf("%d",&num3);
	
	if ( num1 > num2 )
     {
     		if( num1 > num3 )
	   	  	{
	   	  			printf("el numero 1 es el mayo: %d",num1);
	   	  	}
	   	  else
	   	    {
	   	   		  printf("el numero 3 es el mayor: %d",num3);
	   	    }
     }
	 else
	 	 {
	 			if ( num2 > num3 )
	 				 {
	 				 		printf("el numero 2 es el mayor: %d",num2);
	 				 }
	 				else
	 				 {
	 				 		printf("el numero 3 es el mayor: %d",num3);
	 				 }
	 	 }
}

void funcion2()
{
	int num1,num2,num3;
	system("cls");
	printf("ingrese el primer numero:");
	scanf("%d",&num1);
	printf("ingrese el segundo numero numero:");
	scanf("%d",&num2);
	printf("ingrese el tercer numero numero:");
	scanf("%d",&num3);
	
	if ( num1 > num2 )
	{
		if ( num1 > num3 )
		{
			if (num3 > num2)
			{
				printf("el valor medio es %d \n",num2);
			}
			else
			{
				printf("el valor medio es %d \n",num3);
			}
		}
		else
		{
			if ( num1 > num2 )
			{
				printf("el valor medio es %d \n",num2);
			}
			else
			{
				printf("el valor medio es %d \n",num1);
			}	
		}
	}
	else
	{
		if ( num2 > num3 )
		{
			if ( num3 > num1 )
			{
				printf("el valor medio es %d \n",num3);
			}
			else
			{
				printf("el valor medio es %d \n",num1);
			}
		}
		else
		{
			if ( num2 > num1 )
			{
				printf("el valor medio es %d \n",num2);
			}
			else
			{
				printf("el valor medio es %d \n",num1);
			}
		}
	}
}

void funcion3()
{
	int num1,num2,num3;
	system ("cls");
	printf("ingrese el primer numero:");
	scanf("%d",&num1);
	printf("ingrese el segundo numero numero:");
	scanf("%d",&num2);
	printf("ingrese el tercer numero numero:");
	scanf("%d",&num3);
	system("cls");
	if ( num1 < num2 )
     {
     		if( num1 < num3 )
	   	  	{
	   	  			if ( num2 < num3 )
	   	  				 {
	   	  				 		printf("la cadena es: %d , %d , %d",num1,num2,num3);
	   	  				 }
	   	  				else
	   	  				 {
	   	  				 		printf("la cadena es: %d , %d , %d",num1,num3,num2);
	   	  				 }
	   	  	}
	   	  else
	   	    {
	   	   		  if ( num2 < num1 )
	   	  				 {
	   	  				 		printf("la cadena es: %d , %d , %d",num3,num2,num1);
	   	  				 }
	   	  				else
	   	  				 {
	   	  				 		printf("la cadena es: %d , %d , %d",num3,num1,num2);
	   	  				 }
	   	    }
     }
	 else
	 	 {
	 			if ( num2 < num3 )
	 				 {
	 				 		if ( num1 < num3 )
	   	  				 {
	   	  				 		printf("la cadena es: %d , %d , %d",num2,num3,num1);
	   	  				 }
	   	  				else
	   	  				 {
	   	  				 		printf("la cadena es: %d , %d , %d",num2,num1,num3);
	   	  				 }
	 				 }
	 				else
	 				 {
	 				 			if ( num1 < num2 )
	   	  				 {
	   	  				 		printf("la cadena es: %d , %d , %d",num3,num1,num2);
	   	  				 }
	   	  				else
	   	  				 {
	   	  				 		printf("la cadena es: %d , %d , %d",num3,num2,num1);
	   	  				 }
	 				 }
	 	 }
}


