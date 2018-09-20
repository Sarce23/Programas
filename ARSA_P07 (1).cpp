
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void strnom(void);

int main (void)
{
   strnom();
   return 0;
}


void strnom(void)
{
    int x, y,num,anio;
    srand(time(NULL));
    char nomC[30];
    char sexo[6];
	char nomh[16][20]={"SERGIO","MARK","STEVE","AMADEUS","VLADIMIR","RANDY","JHON","ELVER","ARMANDO","LUCIAN","ALFONSO","GIOVANNI", "JUAN","ELVER","ARMANDO"};
    char nomf[16][20]={"LIZ","SOFIA","DAYANA","MARIA","ALEJANDRA","IDALY","SASHA","DANIELA","VERONICA","YOSELIN","KASANDRA","ROSA","GUADALUPE","VANESSA","GLORIA"};
    char app[24][20]= {"LOPEZ","HERNANDEZ","GARZA","ARCE","SANAY","RUELAS","ZARATE","RODRIGUEZ","DANIELS","GRAY","MCFIELN","VALDOVINOS","ROSAS","GALLARDO","FERRARI","MUSTANG","PACO","GARCOA","PEREZ","STARK","WILSON","ROGERS","PUTIN"};
    char mes[30][20]= {"ENERO","FEBRERO","MARZO","ABRIL","MAYO","JUNIO","JULIO","AGOSTO","SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"}; 
    char dia[32][3]= {"01","02","03","04","05","06","07","08","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"};
    char edad[100][5]= {"01","02","03","04","05","06","07","08","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40","41","42","43","44","45","45","46","47","48","49","50","51","52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68","69","70","71","72","73","74","75","76","77","78","79","80"};
    
    x= rand()%100;
    y= rand()%100;
    num= rand()%80;
    anio= 2016 -(atoi(edad[num]));
    
    if (x % 2 == 0)
       {
            strcpy (sexo, "HOMBRE");  
            strcpy (nomC, app[rand()%15]);
            strcat (nomC, " ");
            strcat (nomC, app[rand()%15]);
            strcat (nomC, " ");
            if (y % 2 == 0)
               {
                    strcat (nomC, nomh[rand()%15]);  
               }
              else
               {
                    strcat (nomC, nomh[rand()%15]);
                    strcat (nomC, " "); 
                    strcat (nomC, nomh[rand()%15]);
               }   
       }
      else
       {
           strcpy (sexo, "MUJER");  
            strcpy (nomC, app[rand()%15]);
            strcat (nomC, " ");
            strcat (nomC, app[rand()%15]);
            strcat (nomC, " ");
            if (y % 2 == 0)
               {
                    strcat (nomC, nomf[rand()%15]);  
               }
              else
               {
                    strcat (nomC, nomf[rand()%15]);
                    strcat (nomC, " "); 
                    strcat (nomC, nomf[rand()%15]);
               }   
       }
    num= rand()%80;
    anio= 2016 -(atoi(edad[num]));	
	printf ("\nNOMBRE: %s \n",nomC);
	printf ("\nSEXO: %s \n",sexo);
	printf ("\nEDAD: %s \n",edad[num]);
	printf ("\nFECHA DE NACIMIENTO: %s-%s-%d \n\n", dia[rand()%31], mes[rand()%12], anio);  	
	system("pause");
	
}



