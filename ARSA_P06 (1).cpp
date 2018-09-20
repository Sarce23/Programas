#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

#define TRUE 1
#define FALSE 0

void menu(void);
void programa1(int vect[],int tam, int ri, int rs);
void programa2(int vect[], int tam);
void programa3(int vect[], int tam);
int programa4(int vect[], int tam, int busq);

int main ()
{
	menu();
	return 0;
}

void menu (void)
{
	int op,t,r1,r2,b1,p1;
	int vect[100];
	   do{
      system ("cls");
      printf("\n M  E   N   U");
	  printf("\n1.- llenar Vector");
	  printf("\n2.- Desplegar Vector");
	  printf("\n3.- Ordenar");
	  printf("\n4.- Buscar");
	  printf("\n5.- Salir");
	  printf("\nESCOGE UNA OPCION.");
      scanf ("%d",&op);
	  switch(op)
	    {
		  case 1: 
		  		 printf("ingrese el tamanio del vector:\n");
		  		 scanf("%d",&t);
		  		 printf("ingrese el rango inferior:\n");
		  		 scanf("%d",&r1);
		  		 printf("ingrese el rango superior:\n");
		  		 scanf("%d",&r2);
		  		 programa1(vect,t,r1,r2); 
				break;
		  case 2:
		  		 programa2(vect,t);  
				break;
		  case 3: 
		  		 programa3(vect,t);  
				break;
		  case 4: 
		  		 printf("Ingrese el numero que desea buscar:\n");
		  		 scanf("%d",&b1);
		  		 p1=programa4(vect,t,b1);  
		  		 if ( p1 == -1 )
		  		    {
		  		    	printf("No Existe\n");
		  		    	system("pause");
					}
				   else
				    {
				    	printf("El %d Esta en la posicion %d del vector\n",vect[p1],p1);
				    	system("pause");
					}
				break;
		  
		  default: printf("Opcion invalida");
		}
   }while(op != 5);
   
}

void programa1(int vect[],int tam, int ri, int rs)   //llenar vector
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

void programa2(int vect[], int tam) //Desplegar Vector 
{
	int i;
	
	printf("vector:\n");
	for (i=0; i<tam; i++ )
	    {
	    	printf(" %d \n",vect[i]);
		}
		system("pause");

	
}

void programa3(int vect[], int tam) // ordenar vector
{
	int i,j,burb;
	for ( i=0; i < tam; i++ )
	    {
	    	for ( j=i+1; j < tam; j++ )
	    	    {
	    	    	if ( vect[i] > vect [j] )
	    	    	   {
	    	    	   	burb=vect[i];
	    	    	   	vect[i]=vect[j];
	    	    	   	vect[j]=burb;
					   }
				}
		}
	

	
}

int programa4(int vect[], int tam, int busq)
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
