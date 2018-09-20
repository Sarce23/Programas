#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Validanumi(int ri, int rf);
long Validanuml(int ri, int rf);
void menu(void);
void FibonacciFor(void);
void FibonacciDoWhile(void);
void FibonacciWhile(void);
void FactorialFor(void);
void FactorialDoWhile(void);
void FactorialWhile(void);
void DigitosFor(void);
void DigitosDoWhile(void);
void DigitosWhile(void);


int main()
{
	menu();
	return 0;
}

void menu(void)
{
     int op;   
     do{
         system("CLS");
         printf("\n\t  M  E  N  U \n");
         printf("\n   1. Fibonacci (FOR)");
         printf("\n   2. Fibonacci (DO WHILE)");
         printf("\n   3. Fibonacci (WHILE)");
         printf("\n   4. Factorial (FOR)");
         printf("\n   5. Factorial (DO WHILE)");
         printf("\n   6. Factorial (WHILE)");
         printf("\n   7. Digitos (FOR)");
         printf("\n   8. Digitos (DO WHILE)");
         printf("\n   9. Digitos (WHILE)");
	     printf("\n   10. Salir \n");
         printf("\n Elige: \n");
         op=Validanumi(1,10);
	     switch(op)
           {
		     case 1:
			 		FibonacciFor();
					break;
		     case 2:
		   			FibonacciDoWhile();
					break;
		     case 3:
		     		FibonacciWhile();
					break;
			 case 4:
			 		FactorialFor();
					break;
			 case 5:
			 		FactorialDoWhile();
					break;
			 case 6:
			 		FactorialWhile();
					break;
			 case 7:
			 		DigitosFor();
					break;
			 case 8:
			 		DigitosDoWhile();
			 		break;
			 case 9:
			 		DigitosWhile();
			 		break;
	       }
     }while(op != 10);
}

void FibonacciFor(void)
{
	int num, i, r, a=-1, s=1;
	system("CLS");
	printf("Ingrese un numero del 1 al 30 \n");
	num=Validanumi(1,30);
	printf("\n");
    for ( i=0; i<num; i++ )
        {
       	  r=a+s;
       	  printf("%d - ", r);
       	  a=s;
       	  s=r;
        }
	printf("\n\n");
	system("PAUSE");
}

void FibonacciDoWhile(void)
{
	int num, i, r, a=-1, s=1;
	system("CLS");
	printf("Ingrese un numero del 1 al 30 \n");
	num=Validanumi(1,30);
	printf("\n");
    i=0;
    do{
	    r=a+s;
      	printf("%d - ", r);
      	a=s;
      	s=r;
      	i++;
    }while(i<num);
    printf("\n\n");
	system("PAUSE");
}

void FibonacciWhile(void)
{
	int num, i, r, a=-1, s=1;
	system("CLS");
	printf("Ingrese un numero del 1 al 30 \n");
	num=Validanumi(1,30);
	printf("\n");
    i=0;
    while(i<num)
      {
	    r=a+s;
       	printf("%d - ", r);
       	a=s;
       	s=r;
       	i++;
      }
    printf("\n\n");
	system("PAUSE");
}

void FactorialFor(void)
{
	int num, i, r, a=-1, s=1;
	long int fact=1;
	system("CLS");
	printf("Ingrese un numero del 1 al 30 \n");
	num=Validanumi(1,30);
	printf("\n");
    for ( i=2; i<=num; i++ )
        {
       	  fact=fact*i;
        }
    printf("Factorial de %d: %ld \n\n", num, fact);
	system("PAUSE");
}

void FactorialDoWhile(void)
{
	int num, i, r, a=-1, s=1;
	long int fact=1;
	system("CLS");
	printf("Ingrese un numero del 1 al 30 \n");
	num=Validanumi(1,30);
	printf("\n");
	i=1;
    do{
	    fact=fact*i;
	    i++;
    }while(i<=num);
    printf("Factorial de %d: %ld \n\n", num, fact);
	system("PAUSE");
}

void FactorialWhile(void)
{
	int num, i, r, a=-1, s=1;
	long int fact=1;
	system("CLS");
	printf("Ingrese un numero del 1 al 30 \n");
	num=Validanumi(1,30);
	printf("\n");
	i=2;
    while(i<=num)
	     {
	       fact=fact*i;
	       i++;
         }
    printf("Factorial de %d: %ld \n\n", num, fact);
	system("PAUSE");
}

void DigitosFor(void)
{
	int dig;
	long int num, num2;
	system("CLS");
	printf("Ingrese un numero del 1 al 2147483647 \n");
	num=Validanuml(1,2147483647);
	for ( dig=0, num2=num; num2>=1; dig++, num2=num2/10 );
	printf("\n%ld tiene %d digitos \n\n", num, dig);
	system("PAUSE");	
}

void DigitosDoWhile(void)
{
	int dig;
	long int num, num2;
	system("CLS");
	printf("Ingrese un numero del 1 al 2147483647 \n");
	num=Validanuml(1,2147483647);
	dig=0;
	num2=num;
	do{
	    num2=num2/10;
	    dig++;
	}while(num2>=1);
	printf("\n%ld tiene %d digitos \n\n", num, dig);
	system("PAUSE");
}

void DigitosWhile(void)
{
	int dig;
	long int num, num2;
	system("CLS");
	printf("Ingrese un numero del 1 al 2147483647 \n");
	num=Validanuml(1,2147483647);
	dig=0;
	num2=num;
	while(num2>=1)
	     {
	       num2=num2/10;
	       dig++;
		 }
	printf("\n%ld tiene %d digitos \n\n", num, dig);
	system("PAUSE");
}

int Validanumi(int ri,int rf)
{
	char cad1[30];
	int num;
	do{
		fflush(stdin);
		gets(cad1);
		num=atoi(cad1);
	}while(num<ri || num>rf);
	return num;
}

long Validanuml(int ri,int rf)
{
	char cad1[30];
	long num;
	do{
		fflush(stdin);
		gets(cad1);
		num=atol(cad1);
	}while(num<ri || num>rf);
	return num;
}

