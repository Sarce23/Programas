/**/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

void strnom (void);

int main (void)
{
   strnom();
   return 0;
}

void strnom (void)
{
	char *nomC;
	char *Fnaci;
	srand(time(NULL));
	int edad,sexo,anio,segundon;
	
	char nomf[10][20]={"LIZ","SOFIA","DAYANA","MARIA","ALEJANDRA","IDALY","SASHA","DANIELA","VERONICA","YOSELIN"};
	char nomh[10][20]={"SERGIO","MARK","STEVE","AMADEUS","VLADIMIR","RANDY","JHON","ELVER","ARMANDO","LUCIAN"};
	char apell[30][20]={"LOPEZ","HERNANDEZ","GARZA","ARCE","SANAY","RUELAS","ZARATE","RODRIGUEZ","DANIELS","GRAY","MCFIELN","VALDOVINOS","ROSAS","GALLARDO","FERRARI","MUSTANG","PACO","GARCOA","PEREZ","STARK","WILSON","ROGERS","PUTIN",};
	char mes[12][20]={"ENERO","FEBRERO","MARZO","ABRIL","MAYO","JUNIO","JULIO","AGOSTO","SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"};
	
	strcpy(nomC,apell[rand()%30]);
	strcat(nomC," ");
	strcat(nomC,apell[rand()%30]);
	strcat(nomC," ");

	sexo=rand()%100;
	if ( sexo%2 == 0 )
	   {
	   		strcat(nomC,nomh[rand()%10]);
	   		segundon=rand()%100;
	   		if ( segundon%2 == 0 );
	   	   	   {
	   	   		strcat(nomC," ");
	   	   		strcat(nomC,nomh[rand()%10]);
		       }
	   		puts(nomC);
	   		puts("HOMBRE"); 	
	   }
	  else
	   {
	   		strcat(nomC,nomf[rand()%10]);
	   		segundon=rand()%100;
	   		if ( segundon%2 == 0 );
	   	       {
	   	   			strcat(nomC," ");
	   	   			strcat(nomC,nomf[rand()%10]);
		       }
	   		puts(nomC);
	   		puts("MUJER");
	   }
	
		
	edad=rand()%60;
	anio=2016-edad;
	
	printf("%d",edad);
	strcat(Fnaci," ");
	strcat(Fnaci,mes[rand()%12]);
	strcat(Fnaci," ");
	puts(Fnaci);
	printf("%d",anio);
	
	
	puts(nomC);
}
