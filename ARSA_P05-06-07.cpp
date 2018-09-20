#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"arce.h"

#define RI 1
#define RS 4

#define TRUE 1
#define FALSE 0

#define N 100
#define tam 30

#define a 97
#define z 122
#define A 65
#define Z 90

#define ENTER 13
#define ESP 32

typedef struct talum{
		long matri;
		char nom[tam], appat[tam], apmat[tam];
		int edad, sexo;
}Talum;

Talum Auto (void);
Talum Manual (void);
void menu (void);
int AgreArch(Talum vect[], int n, int i, char *nom);
void SalidaArch(Talum vect[], int n, char *nom);
void DespArch(char *nom);
void DespVect(Talum vect[], int n);


int main()
{
    menu();
    srand(time(NULL));
    return 0;
}

void menu (void)
{
int op, op2, i=0;
Talum vect[N];
char nom[tam];

do{
   system("CLS");
   printf("ELIGE UNA OPCION:\n\n");
   
   printf("1. AGREGAR.\n");
   printf("\ta). MANUAL.\n");
   printf("\tb). AUTOMATICO.\n");
   printf("\tc). ARCHIVO.\n");
   printf("2. DESPLEGAR.\n");
   printf("\ta). VECTOR.\n");
   printf("\tb). ARCHIVO.\n");
   printf("3. SALIDA DE ARCHIVO.\n");
   printf("4. SALIR.\n\n");

   op=ValidaNum(RI, RS, "Ingresa una opcion:", "ERROR, por favor ingresa un numero valido.\n", 1);
   
   switch(op)
   {
   case 1:
   		if( i < N)
   		{
   		
 			op2=ValidaNum(RI, 3, "De que manera deseas agregar?", "ERROR, por favor ingresa un numero valido.", 1);
 			switch(op2)
 			{
		 		case 'a':
		 			
		 			vect[i++] = Manual();
		 			
		 		break;
		 		
				case 'b': 
				
					vect[i++] = Auto(); 
					printf("%ld %s %s %s %d %d", vect[i-1].matri, vect[i-1].appat, vect[i-1].apmat, vect[i-1].nom, vect[i-1].sexo, vect[i-1].edad);
					system("pause");
					
				break;
				
				case 'c':
					
					printf("\Ingrese el nombre del archivo: ");
					fflush(stdin);
					gets(nom);
					i = AgreArch(vect, N, i, nom);
					
				break;
						
 			}
 		}
 		else
 		{
 			printf("El Vector Esta Lleno \n");
 			system("pause");
 		}
   break;
   
   case 2:
   	
   		op2=ValidaNum(RI, 2, "Desplegar:", "ERROR, por favor ingresa un numero valido.", 1);
   		switch(op2)
   		{
   			case 'a':
   				
   				if ( i == 0)
   				{
   					system("CLS");
   					printf("\nERROR, primero se debe llenar el vector\n");
   					system ("PAUSE");
   				}
   				else
   				{	
   					DespVect(vect, i);
   				}
   				
   			break;
   			
   			case 'b':
   				
   				system("CLS");
   				printf("\nIngrese el nombre del archivo: ");
   				fflush(stdin);
   				gets(nom);
   				DespArch(nom);
   				
   			break;
   		}
   		
   break;
   
   case 3:
   	
   		system("CLS");
   		printf("\nEscribe el nombre del archivo: ");
		fflush(stdin);
		gets(nom);
		SalidaArch(vect, i, nom);
		
	break;   	
   
   
   }
}while(op != 4); 

system("pause");           
}


Talum Manual (void)
{
	Talum reg;
	system("CLS");
	
	printf("Agregar de Forma Manual:\n\n");	
	
	reg.matri=Validanum(499, 349000, "Matricula: ", "\nERROR, debe ser del 499 al 349000.\n\n");
	strcpy(reg.appat, ValidaChar("Apellido Paterno: ", "\n\nApellido no valido, por favor escribelo de nuevo.\n\n", tam));
	strcpy(reg.apmat, ValidaChar("Apellido Materno: ", "\n\nApellido no valido, por favor escribelo de nuevo.\n\n", tam));
	strcpy(reg.nom, ValidaChar("Nombre(s): ", "\n\nNombre(s) no valido, por favor escribelo de nuevo.\n\n", tam));
	reg.sexo=Validanum(0, 1, "Sexo (Hombre=1, Mujer=0): ", "\nERROR, ingresa un numero valido.\n\n");
	reg.edad=Validanum(17, 37,"Edad (Desde 17 hasta 37 anios):", "\nERROR, ingresa un numero valido.\n\n");
	
	system("pause");
	return reg;
}

Talum Auto (void)
{
   system("CLS");
   
   printf("Agregar de Forma Automatica:\n\n");	
   Talum reg, vect[N];
   int i, j, f, x, y, k, repe;
   
   char nomh[15][20]= {"MARCO","ROGGERS","MISSAEL","MATEO","VLADIMIR","SERGIO","PEDRO","GEREMIAS","STEVE","JHON","ALBERTO","FRANK", "LIAN","TAKAO","CARLOS"};
   char nomm[15][20]= {"LIZ","SOFIA","NARUBI","CECILIA","DANIELA","SASHA","DIANA","PAOLA","VERONICA","YOSELIN","KARLA","ELISA","GUADALUPE","VANESSA","GABRIELA"};
   char app[30][20]= {"ARCE", "ZARATE", "HERNANDEZ", "SANAY", "CAMPOS", "MELING", "SOTELO", "CARRILLO", "AMADOR", "JIMENEZ", "GUTIERREZ", "TORRES", "LUGO", "RAMIREZ", "HERRERA", "CASTILLO", "GARCIA", "NAVA", "YAMAMOTO", "MUJICA", "MORALES", "REZA", "GARZA", "DIAZ", "MENDEZ", "CORTEZ", "MURILLO", "SANDOVAL", "ALVIDRES", "CARRILLO"};
   
   for(j=0; j<N; j++, i++)
	  {
		x= rand()%1000;
		
   		if (x % 2 == 0)
	  	   { 
			reg.sexo= 1;
   			strcpy(reg.appat, app[rand()%14]);
  			strcpy(reg.apmat, app[rand()%14]);
			strcpy(reg.nom, nomh[rand()%14]);
			y= rand()%1000;
			if (y % 2 == 0)
		   	   {
					strcat(reg.nom, " ");
					strcat(reg.nom, nomh[rand()%14]);
		   	   }
		   	   
	  	   }
	 	  else
	  	   {
			reg.sexo= 0;
			strcpy(reg.appat, app[rand()%14]);
			strcpy(reg.apmat, app[rand()%14]);
			strcpy(reg.nom, nomm[rand()%14]); 
			if (y % 2 == 0)
		   	   {
					strcat(reg.nom, " ");
					strcat(reg.nom, nomm[rand()%14]);
		   	   }      		
	  	   }
	  	   
	reg.edad= (rand()%20)+17;
					   						       			
		do{
		reg.matri= (rand()%499)+349000;
		k=0; 
		repe=FALSE;
		while (k<i && repe==FALSE)
		      {
				if ( reg.matri == vect[k].matri)
			       {
						repe= TRUE;
			       }
				   						                                
		     	k++;		                                
		      }
		      
		}while ( repe == TRUE);
		
	vect[i].matri= reg.matri;    
						           	        		  	 
	  } 

	return reg;
}

int AgreArch(Talum vect[], int n, int i, char *nom)
{
	FILE *arch;
	Talum reg;
	system("CLS");
	arch = fopen(nom, "r");
	if(arch)
	  {
		while(!feof(arch))
		     {
				fscanf(arch, "%ld %s %s %s %s %d %d", &reg.matri, &reg.appat, &reg.apmat, &reg.nom, &reg.sexo, &reg.edad);
				printf("%ld %s %s %s %s %d %d", reg.matri, reg.appat, reg.apmat, reg.nom, reg.sexo, reg.edad);
				if( i < n)
			      {
					vect[i]=reg;
					i++;
			      }
		     }
	  }
	 else
	  {
		printf("\nERROR.\n");
	  }
	  
	return i;
}

void SalidaArch(Talum vect[], int n, char *nom)
{
	int i;
	FILE *arch;
	arch=fopen(nom, "r+");
	
	if(!(arch))
	  {
		arch=fopen(nom, "w+");
	  }
	system("CLS");
	
	for(i=0; i < n; i++)
	   {
			fprintf(stdout,"%5d %6ld %-30s %-30s %-30s %d %3d \n", i+1, vect[i].matri, vect[i].nom, vect[i].appat, vect[i].apmat,vect[i].sexo, vect[i].edad );
			fprintf(arch,"%5d %6ld %-30s %-30s %-30s %d %3d \n", i+1, vect[i].matri, vect[i].nom, vect[i].appat, vect[i].apmat,vect[i].sexo, vect[i].edad );
	   }
	   
	fclose(arch);
	system("pause");
}

void DespArch(char *nom)
{
	FILE *arch;
	Talum reg;
	
	system("CLS");
	printf("\t%s\n", nom);
	arch = fopen(nom, "r");
	if(arch)
	  {
		while(!feof(arch))
		     {
				fscanf(arch, "%ld %s %s %s %s %d %d", &reg.matri, &reg.appat, &reg.apmat, &reg.nom, &reg.sexo, &reg.edad);
				printf("%ld %s %s %s %s %d %d", reg.matri, reg.appat, reg.apmat, reg.nom, reg.sexo, reg.edad);
		     }
	  }
	 else
	  {
		printf("\nERROR, el archivo no existe.\n");
 	  }
 	  
	system("pause");
	
}

void DespVect(Talum vect[], int n)
{
	int i;
    char strsexo[15];
    system("CLS");
    printf("NO. DE REGISTRO \tMATRICULA \tPATERNO \tMATERNO \tNOMBRE \t\t\t  SEXO \t\tEDAD\n");
    for (i=0 ; i<n ;i++)
        {
        	if (vect[i].sexo == 1)
        	   {
        			strcpy (strsexo,"Masculino");
			   }
			  else
			   {
					strcpy (strsexo,"Femenino");
			   }
            
			printf("%5d\t\t\t %6ld \t%-9s \t%-9s \t%-18s\t %s \t%3d \n", i+1, vect[i].matri, vect[i].appat, vect[i].apmat, vect[i].nom, strsexo, vect[i].edad );
            if (i == n)
               {                             

                    system("pause");
                    system("CLS");
                                                                                         
               }
        }
     system("pause");   
}
