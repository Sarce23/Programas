

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

typedef struct _talumnos{
	long matricula;
	char appat[30];
	char apmat[30];
	char nombres[30];
	int edad, sexo;
	}Talum;

#define TRUE 1
#define FALSE 0
#define N 100

void menu (void);
Talum llenar ();
void desplegar (Talum vec[], int tam);
int buscar (Talum vec[], int tam, long q);
void ordenar (Talum vec[], int tam);

int main (void)
{
   menu();
   return 0;
}

void menu(void)
{
   srand(time(NULL));
   int i=0,j=0, num, tam=0, pos, x, repe, k, q, vali= FALSE;
   Talum vec[N], t;
   do
   {
      system ("cls");
      printf ("\n M  E   N   U");
	  printf ("\n1.- LLENAR VECTOR CON 10 ALUMNOS");
	  printf ("\n2.- DESPLEGAR VECTOR");
	  printf ("\n3.- BUSCAR");
      printf ("\n4.- ORDENAR");
      printf ("\n5.- SALIR");
	  printf ("\nESCOGE UNA OPCION: ");
      scanf ("%d",&num);
	  switch (num)
	    {
		  case 1:
		  		vali= TRUE;
		  		if (i<N)
				{
					for(j=0; j<10; j++, i++)
					   {
					   		vec[i]= llenar ();					   						       			
						    do{
						        t.matricula= (rand()%499)+349000;
						        k=0; 
						        repe=FALSE;
						        while (k<i && repe==FALSE)
						              {
						                    if (t.matricula== vec[k].matricula)
						                        {
						                            repe= TRUE;
						                        }						                                
						                        k++;
						                                
						              }
						      }while (repe== TRUE);
						      vec[i].matricula= t.matricula;    
						           	        		  	 
							   } 
					   tam= i;					       	        		  	 
				}
			   else
			    {
					printf ("El Vector Esta Lleno");
					system("pause");									 
				}	
               break;
		  case 2: 
		  	   if (vali == FALSE)
		  	   	  {
		  	   	  		printf ("El Vector No Contiene Nada, Porfavor Llenelo Primero");
		  	   	  		system("pause");
		     	  }
		     	 else
		     	  {
		     	  		desplegar(vec,tam);
               			system("pause");
				  }
               break;
		  case 3:
		  	if (vali == FALSE)
		  	   	  {
		  	   	  		printf ("El Vector No Contiene Nada, Porfavor Llenelo Primero");
		  	   	  		system("pause");
		     	  }
		     	 else
		     	  {
		     	  		printf ("Dime el numero de matricula que quieres buscar: ");
		  	   			scanf ("%ld",&q);
		  	   			pos= buscar (vec,tam,q);
		  	   			if (pos == 0)
		  	      		   {
		  	      				printf ("EL numero No Existe");
			      	       }
			    		  else
			      		   {
			      				printf ("EL numero %ld esta en la Posicion numero: %d", q, pos);
				  		   }
				  		system("pause");
				  }
		  	   
               break;
		  case 4:
		  	if (vali == FALSE)
		  	   	  {
		  	   	  		printf ("El Vector No Contiene Nada, Porfavor Llenelo Primero");
		  	   	  		system("pause");
		     	  }
		     	 else
		     	  {
		     	  		ordenar (vec,tam) ;
				  }
               break;
		  default: printf ("Numero No Valido");
		}
   } while(num != 5);
}

Talum llenar ()
{
   Talum reg;
   int j, f, x, y, k, c=1, repe;
   char nomh[15][20]= {"SERGIO","MARK","STEVE","AMADEUS","VLADIMIR","RANDY","JHON","ELVER","ARMANDO","LUCIAN","ALFONSO","GIOVANNI", "JUAN","ELVER","BRUCE"};
   char nomm[15][20]= {"LIZ","SOFIA","DAYANA","MARIA","ALEJANDRA","IDALY","SASHA","DANIELA","VERONICA","YOSELIN","KASANDRA","ROSA","GUADALUPE","VANESSA","GABRIELA"};
   char app[15][20]= {"HERNANDEZ","GARZA","ARCE","SANAY","RUELAS","ZARATE","RODRIGUEZ","DANIELS","GRAY","MCFIELN","VALDOVINOS","ROSAS","GALLARDO","MUSTANG","PACO"};
   x= rand()%1000;
   if (x % 2 == 0)
	  { 
		reg.sexo= 1;
   		strcpy(reg.appat, app[rand()%14]);
  		strcpy(reg.apmat, app[rand()%14]);
		strcpy(reg.nombres, nomh[rand()%14]);
		y= rand()%1000;
		if (y % 2 == 0)
		   {
				strcat(reg.nombres, " ");
				strcat(reg.nombres, nomh[rand()%14]);
		   }
	  }
	 else
	  {
		reg.sexo= 0;
		strcpy(reg.appat, app[rand()%14]);
		strcpy(reg.apmat, app[rand()%14]);
		strcpy(reg.nombres, nomm[rand()%14]); 
		if (y % 2 == 0)
		   {
				strcat(reg.nombres, " ");
				strcat(reg.nombres, nomm[rand()%14]);
		   }      		
	  }
	reg.edad= (rand()%20)+17;
	return reg;
}

void desplegar (Talum vec[], int tam)
{
    int i, c=20;
    char strsexo[15];
    for (i=0 ; i<tam ;i++)
        {
        	if (vec[i].sexo == 1)
        	{
        		strcpy (strsexo,"Masculino");
			}
			else
			{
				strcpy (strsexo,"Femenino");
			}
            printf("%d)Matricula: %ld, Nombre: %s %s %s, Sexo: %s, Edad: %d\n", i, vec[i].matricula, vec[i].appat, vec[i].apmat, vec[i].nombres, strsexo, vec[i].edad );
            if (i==c || i==tam )
               {                             
                    printf ("Presiona una tecla para continuar");
                    system("pause");
                    system("CLS");
                    c=c+20;                                                                                       
               }
        }	  
} 

int buscar (Talum vec[], int tam, long q)
{
	int n, i, pos=0;
	for(int i=0; i<tam ; i++)
	   {
                 if(vec[i].matricula == q)
				   {
                       pos=i ;
					   i=tam; 
					                                            
                   }
                 else
				   {
                        pos=0;
                   }
       }
    return pos;
}

void ordenar (Talum vec[], int tam)
{
	Talum temp;
	int i,j;
	for (i=0 ; i<tam ; i++)
	{
		for (j=0 ; j<tam ; j++)
			{
				
				if (vec[j].matricula > vec [j+1].matricula)
				   {
				   		temp= vec[j];
				   		vec[j]= vec[j+1];
				   		vec[j+1]= temp;
				   }
			}
	}
}

