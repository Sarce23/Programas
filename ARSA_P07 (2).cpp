/**/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

void menu(void);
void llenavect(int vect1[],int n);
int llenavectsin(int vect1[],int n, int vect2[]);
int buscar(int vect[],int tam, int busq);
void imprimirvec(int vect[],int n);
void llenarvsnG2(int vect[],int tam, int ri, int rs);
void programa2(void);

int main()
{
	menu();
	
	return 0;
}

void menu(void)
{
   int op,vect1[20],vect2[20],j,x,r,vect3[10],i;
   
   do{
      system ("cls");
      printf("\n M  E   N   U");
	  printf("\n1.- programa 1");
	  printf("\n2.- programa 2");
	  printf("\n3.- Salir");
	  printf("\nESCOGE UNA OPCION.");
      scanf ("%d",&op);
	  switch(op)
	    {
		  case 1: llenavect(vect1,20);
		  		  j=llenavectsin(vect1,20,vect2);
				  imprimirvec(vect1,20);
				  imprimirvec(vect2,j);   
		  
		  break;
		  
		  case 2: llenarvsnG2(vect3,10,1,10);
		  		  x= vect3[(rand()%10)+1];
		  		  printf ("ADIVINA LA POSICION (del 1 al 10) EN LA QUE SE ENCUENTRA EL NUMERO *%d* \n",x);
		  		  for (i=0 ; i<3 ; i++)
               	   {
               	   		printf ("OPORTUNIDAD #%d, CUAL ES TU RESPUESTA: ", i+1);
               			scanf ("%d",&r);
               			if (buscar(vect3, 10, x)== r)
                  		   {
                                printf ("!!!GANASTE!!!  LE ATINASTE AL NUMERO\n");
                                imprimirvec(vect3, 10);
                                i=3;
                           }
                 		  else
                  		   {
                                printf ("PERDISTE, TE QUEDAN %d OPORTUNIDADES\n", 2-i);
								if (i==2)
								imprimirvec(vect3, 10);
								                                
                  		   }                 		                    	
				   }  
		  break;
		}
   }while(op != 3);
}

void llenavect(int vect1[],int n)
{
	int i;
	srand(time(NULL));
	
	printf("vector 1:\n");
	for ( i=0; i<n; i++ )
        {
        	vect1[i]=(rand()%20)+1;
		}
	
}

int llenavectsin(int vect1[],int n, int vect2[])
{
	int i,j=0;
	for ( i=0; i < n; i++)
	    {
	    	if ( buscar(vect2,n,vect1[i]) == -1)
	    	   {
	    	   		
	    	   	vect2[j]=vect1[i];	
	    	   	j++;
			   }
		}
	return j;
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

int buscar(int vect[],int tam, int busq)
{
	int pos,i;
	pos=-1;
	for ( i=0; i < tam; i++)
	    {
	    	if ( vect[i] == busq )
	    	   {
	    	   	pos=i;
			   }
		}

	return pos;
}

void llenarvsnG2(int vect[],int tam, int ri, int rs)
{
	int i,num,repetido,j;
	
	for ( i=0;i<tam; i++)
	    {
	    	do
	    	{
	    		num=(rand()%(rs-ri))+ri;
	    		j=0;
	    		repetido=FALSE;
	    		
	    		while ( j<i && repetido==FALSE )
	    		      {
	    		      	if( num == vect[j] )
	    		      	  {
	    		      	  	repetido=TRUE;
						  }
						 else
						  {
						  	j++;
						  }
					  }
			}while( repetido == TRUE );
			vect[i]=num;
		}
}
