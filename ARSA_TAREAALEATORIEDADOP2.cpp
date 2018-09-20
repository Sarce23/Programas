/**/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define  N 10

void principal1(void);
void llenarvectosn(int vect[],int n);
void imprimirvec(int vect[],int n);
void llenavectceros(int vect[],int n);

int main ()
{
	principal1();
	return 0;
}

void principal1()
{
	int vect[N];
	llenavectceros(vect,N);
	imprimirvec(vect,N);
	llenarvectosn(vect,N);
	imprimirvec(vect,N);
	
}

void llenavectceros(int vect[],int n)
{
	int i;
	for (i=0; i < n; i++ )
	    {
	    	vect[i]=0;
		}
}

void llenarvectosn(int vect[],int n)
{
	srand(time(NULL));
	int i,ind;
	for(i=n; i < n+N; i++)
	{
		ind = rand()%10;
		if( vect[ind] == 0)
		{
			vect[ind] = i;
		}
		else
		{
			i--;
		}
	}
}

void imprimirvec(int vect[],int n)
{
	int i;
	for ( i=0; i < n; i++)
	    {
	    	printf("%d\n",vect[i]);
		}
	system("pause");
}



