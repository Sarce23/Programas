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
	char sexo[8];
	int edad;
	}Talum;

void RANDOM1(void);

int main (void)
{
   RANDOM1();
   return 0;
}

void RANDOM1 (void)
{
	Talum datos;
   int i, x, y, k, c=1;
   
   srand(time(NULL));
   
   char nomh[15][20]= {"SERGIO","MARK","STEVE","AMADEUS","VLADIMIR","RANDY","JHON","ELVER","ARMANDO","LUCIAN","ALFONSO","GIOVANNI", "JUAN","ELVER","BRUCE"};
   char nomm[15][20]= {"LIZ","SOFIA","DAYANA","MARIA","ALEJANDRA","IDALY","SASHA","DANIELA","VERONICA","YOSELIN","KASANDRA","ROSA","GUADALUPE","VANESSA","GABRIELA"};
   char app[15][20]= {"HERNANDEZ","GARZA","ARCE","SANAY","RUELAS","ZARATE","RODRIGUEZ","DANIELS","GRAY","MCFIELN","VALDOVINOS","ROSAS","GALLARDO","MUSTANG","PACO"};
   
   for (k=1; k<=10; k++)
   {
	   for (i=1; i<=10; i++)
	   	{
	   		x= rand()%1000;
	   		
	   		if (x % 2 == 0)
		       { 
		       		strcpy(datos.sexo, "Hombre");
		       		strcpy(datos.appat, app[rand()%14]);
		       		strcpy(datos.apmat, app[rand()%14]);
		       		strcpy(datos.nombres, nomh[rand()%14]);
		       		y= rand()%1000;
					if (y % 2 == 0)
					   {
					   		strcat(datos.nombres, " ");
					   		strcat(datos.nombres, nomh[rand()%14]);
					   }
			   }
		      else
		       {
		       		strcpy(datos.sexo, "Mujer");
		       		strcpy(datos.appat, app[rand()%14]);
		       		strcpy(datos.apmat, app[rand()%14]);
		       		strcpy(datos.nombres, nomm[rand()%14]);	 
					if (y % 2 == 0)
					   {
					   		strcat(datos.nombres, nomm[rand()%14]);
					   }      		
		       }
		       datos.edad=(rand()%7)+18;
		       datos.matricula= (rand()%10000)+340000;
	           printf("%d)Nombre: %s %s %s, Matricula: %d, Sexo: %s, Edad: %d\n", c, datos.appat, datos.apmat, datos.nombres, datos.matricula, datos.sexo, datos.edad );
			   c++;
	    }
	    getch();
   }
}



