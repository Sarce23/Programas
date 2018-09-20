#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>

#define NHOMBRE 100
#define NMUJER 100 
#define APELLIDO 100
#define TRUE 1
#define FALSE 0

typedef struct _tdato{
	long matri;
	char apPat[30];
	char apMat[30];
	char nombre[30];
	int edad;
	char sexo[2];
	int statu;
}Talumno;

void menu (void);
void GenerarRegistro();
void ImprimirRegistro();
Talumno genDatos();
char* appat();
char* apmat();
char* nombre(int op, int op2);
char *sexo(int op);
int buscar(long Matri);
void burbuja(Talumno A[], int n);
void salida();
void nombreAlea(void);
char* leecadena(char*msge); 
int validanum (long r1, long r2, char *msge, char *merror);
void delay(int);

int main (void)
{
   srand(time(NULL));
   menu();
   return 0;
}

void menu(void)
{
   int op,i=0,band=FALSE,pos,r;
   long matric;
   Talumno A[100]={0};
   
   Talumno vect[100];
   
   do{
      system ("cls");
      printf("\n M  E   N   U");
	  printf("\n1.-Generar registros de alumnos ");
	  printf("\n2.-Desplegar Registros ");
      printf("\n3.-Buscar alumno ");
	  printf("\n4.-Ordenar");
	  printf("\n5.-Salida de texto ");
	  printf("\n0.- Salir");
	  printf("\nESCOGE UNA OPCION.");
      scanf("%d",&op);
	  switch(op)
	    {
		  case 1:
		              GenerarRegistro();
		             band=FALSE;
		             break;
		  case 2: ImprimirRegistro();  
		  			break;
		  			
		  case 3:
		              system("cls");
		              matric=validanum(100000,500000,"Ingrese La Matricula","Ingrese Numero Validos");
	                buscar(matric); 
		            break;
		  case 4: 
					burbuja(vect,100);
		           break;   	 
			case 5: salida();       
		}
   }while(op !=0);
}

void GenerarRegistro()
{
   int i;
   FILE *arch;
   system("cls");
    Talumno registro;
   for(i=0;i<10;i++)
   {
   	 
   	  arch=fopen("datos.dat","a+b");
   	  registro=genDatos();
   	  fwrite(&registro,sizeof(struct _tdato),1,arch);
   	  fclose(arch);
   }
    
    printf("SE AGREGARON 10 REGISTROS\n");
    delay(200);  
}

void ImprimirRegistro()
{
  FILE *arch;
  int i=0,j=0;
  Talumno registro;
  
    arch=fopen("datos.dat","rb");
    system("cls");
  
  if(!arch)
    {
       printf("EL ARCHIVO NO EXISTE\n");
      
    }
        printf("ALUMNOS\n");
        printf("MATRICULA    APPATERNO   APMATERNO     NOMBRE               EDAD   SEXO   ESTADO\n");
   
        while(fread(&registro,sizeof(struct _tdato),1,arch))
             {
                printf("%-3d %-12ld %-12s %-12s %-21s %-5d %3s %5d\n",i+1,registro.matri, registro.apPat,registro.apMat,registro.nombre,registro.edad,registro.sexo,registro.statu);
   	            printf("-------------------------------------------------------------------------------\n");
                i++;
            }
      fclose(arch);
   system("pause");
}

Talumno genDatos()
{
	Talumno reg;
	int sex=0,nombres=0;
	sex=((rand()%2))+1;
	nombres=((rand()%2))+1;
	reg.matri=300000+((rand()%25000)+(rand()%25000));
	strcpy(reg.apPat,appat());
	strcpy(reg.apMat,apmat());
	strcpy(reg.nombre,nombre(nombres,sex));
	reg.edad=(rand()%(30-18))+18;
	strcpy(reg.sexo,sexo(sex));
	reg.statu=rand()%2;
	return reg;
}

char* appat()
{
		char ap[150][20]={"GARCIA ","LOPEZ ","PEREZ ","GONZALEZ ","SANCHEZ ","MARTINEZ ","RODRIGUEZ ","FERNANDEZ ","GOMEZ ","MARTIN ","HERNANDEZ ","RUIZ ","DIAZ ","ALVAREZ ","JIMENEZ ","MORENO ","MUNOZ ","ALONSO ","GUITIERREZ ","ROMERO ","SANZ ","TORRES ","SUAREZ ","RAMIREZ ","VAZQUEZ ","NAVARRO ","DOMINGUEZ ","RAMOS ","CASTRO ","GIL ","FLORES ","MORALES ","BLANCO ","SERRANO ","MOLINA ","ORTIZ ","SANTOS ","MORRELL ","DELGADO ","MENDEZ ","CASTILLO ","MARQUEZ ","CRUZ ","MEDINA ","HERRERA ","MARIN ","NUNEZ ","VEGA ","IGLESIAS ","ROJAS ","REYES ","LUNA ","CAMPOS ","RUBIO ","PENA ","FERRER ","LOZANO ","GARRIDO ","LEON ","AGUILAR ","CANO ","ARIAS ","HERRERO ","HERRERA ","GIMENEZ ","FUENTES ","CIFUENTES ","DIEZ ","VIDAL ","PRIETO ","GUERRERO ","MONTERO ","CORTEZ ","RUIZ ","SANTANA ","SOTO ","VARGAS ","MENDOZA ","GUZMAN ","SAEZ ","RIOS ","CARRASCO ","DURAN ","CABRERA ","SALAZAR ","RIVERA ","LORENZO ","GARCIA ","CABALLERO ","ROBLES ","MORA ","GONZALES ","HIDALGO ","CALVO ","MERINO ","PASCUAL ","GALLEGO ","MARTI ","AGIS ","ZAPATA "};
		return ap[rand()%APELLIDO];
}

char* apmat()
{
        char ap[150][20]={"GARCIA ","LOPEZ ","PEREZ ","GONZALEZ ","SANCHEZ ","MARTINEZ ","RODRIGUEZ ","FERNANDEZ ","GOMEZ ","MARTIN ","HERNANDEZ ","RUIZ ","DIAZ ","ALVAREZ ","JIMENEZ ","MORENO ","MUNOZ ","ALONSO ","GUITIERREZ ","ROMERO ","SANZ ","TORRES ","SUAREZ ","RAMIREZ ","VAZQUEZ ","NAVARRO ","DOMINGUEZ ","RAMOS ","CASTRO ","GIL ","FLORES ","MORALES ","BLANCO ","SERRANO ","MOLINA ","ORTIZ ","SANTOS ","MORRELL ","DELGADO ","MENDEZ ","CASTILLO ","MARQUEZ ","CRUZ ","MEDINA ","HERRERA ","MARIN ","NUNEZ ","VEGA ","IGLESIAS ","ROJAS ","REYES ","LUNA ","CAMPOS ","RUBIO ","PENA ","FERRER ","LOZANO ","GARRIDO ","LEON ","AGUILAR ","CANO ","ARIAS ","HERRERO ","HERRERA ","GIMENEZ ","FUENTES ","CIFUENTES ","DIEZ ","VIDAL ","PRIETO ","GUERRERO ","MONTERO ","CORTEZ ","RUIZ ","SANTANA ","SOTO ","VARGAS ","MENDOZA ","GUZMAN ","SAEZ ","RIOS ","CARRASCO ","DURAN ","CABRERA ","SALAZAR ","RIVERA ","LORENZO ","GARCIA ","CABALLERO ","ROBLES ","MORA ","GONZALES ","HIDALGO ","CALVO ","MERINO ","PASCUAL ","GALLEGO ","MARTI ","AGIS ","ZAPATA "};
		return ap[rand()%APELLIDO];
}

char* nombre(int op, int op2)
{
	char nomH[100][20]={"RAMON","AURELIO ","ADRIAN ","AGUSTIN ","LOGAN ","SERGIO ","ALBERTO ","ALFONSO ","ALFREDO ","ALONSO ","ALVARO ","ALVINO ","AMADEO ","AMADO ","ANDREO ","ANDRES ","ANGEL ","ANGELINO ","ANGELITO ","ANGELO ","ANIBAL ","ANTONIO ","AQUILA ","AQUILINO ","ARCHIBALDO ","ARLO ","ARMANDO ","ARNOLDO ","ARTURO ","AURELIO ","BARTOLO ","BELTRAN ","BEMABE ","BENEDICTO ","BERNARDO ","BERTO ","BLANCO ","CALVINO ","CARLOS ","CESAR ","CHAVEZ ","CHAYO ","CICERON ","CLAUDIO ","CONSTANTINO ","CORNELIO ","CORTEZ ","CRISTIAN ","CRISTIANO ","CRISTOBAL ","CRISTOPHER ","DARIO ","EDUARDO ","EFRAIN ","ELIAS ","ELOY ","ELVIO ","EMANUEL ","EMILIO ","ENRIQUE ","ERASMO ","ERNESTO ","ESEQUIEL ","ESTEBAN ","ESTEFAN ","ESTEVAN ","EUGENIO ","EVERARDO ","EZEQUIEL ","FAUSTO ","FEDERICO ","FELIPE ","FELIX ","FERMIN ","FERNANDO ","FIDEL ","FLORINIO ","FRANCISCO ","FRESCO ","GABRIEL ","GALTERO ","GASPAR ","GERARDO ","GERMAN ","GILBERTO ","GREGORIO ","GUADALUPE ","GUILLERMO ","GUSTAVO ","HECTOR ","ABRAHAM ","HERIBERTO ","HERNAN ","HIDALGO ","HUGO ","HUMBERTO ","JAVIER ","JUAQUIN ","JORGE ","OSCAR "};
	char nomM[100][20]={"LINETTE ","NARUBI ","AURORA ","AMBAR ","AMIRA ","XIMENA ","SOFIA ","BEATRIZ ","ALMA ","BELINDA ","MONZERRAT ","ALICIA ","BERENICE ","BERTHA ","VIVIANA ","BLANCA ","MELINA ","CAMILA ","CANDAS ","CARLA ","CARLOTA ","CARMILA ","CARMEN ","GIMENA ","KASSANDRA ","KATARINA ","CECILIA ","IRELIA ","DIANA ","THALILLA ","SASHA ","SARA ","LUXANA ","DANIELA ","LORENA ","GUADALUPE ","TAMARA ","LIZ ","KELLY ","DASY ","DEVORA ","DINA ","DOLORES ","DOMINGA ","DOMINICA ","DORA ","DULCE ","ELENA ","ELISA ","ELVIA ","ELVIRA ","EMILIA ","EMILY ","ESMERALDA ","ESPERANZA ","ESTEFANY ","ESTELA ","ESTEPHANIE ","ESTRELLA ","EVA ","EZMERALDA ","FIDELINA ","FLOR ","GABRIELA ","GALA ","GEOVANNA ","GRACIELA ","GRIZELDA ","GRECIA ","GUADALUPE ","GUILLERMINA ","IMELDA ","INEZ ","IRMA ","ISABEL ","ISABELA ","IVETTE ","IVONNE ","JACINTA ","JADE ","JESENIA ","JIMENA ","JOSEFA ","JUANA ","JUANITA ","JUDITH ","JULIANA ","JULIETA ","KATIA ","LALA ","LAURA ","LEA ","LEONOR ","LEONORA ","LETICIA ","LILIA ","LILIANA ","LLUVIA ","LOLA ","LORE "};
	char nom1[30];
	char nom2[30];
	char nom[30];
	char nombres[50];
	int pos1,pos2,tamN,n1,n2,i;
	
	if(op==1&&op2==1)
	{	  
		 strcpy(nombres,strcat(nomH[rand()%NHOMBRE],nomH[rand()%NHOMBRE]));  
		  return nombres;   
	}
	if(op==2&&op2==1)
	{
	   return nomH[rand()%NHOMBRE];	
	}
		if(op==1&&op2==2)
	{
	
		 strcpy(nombres,strcat(nomM[rand()%NHOMBRE],nomM[rand()%NHOMBRE]));
		 
		 return nombres;
	}
	if(op==2&&op2==2)
	{
	   return nomM[rand()%NHOMBRE];	
	}
	return nombres;
}

char *sexo(int op)
{
	char sex[4][4]={"N""M","M","F"};
	return sex[op];
}


int buscar(long Matri)
{
	int band=FALSE;
   Talumno registro;
   FILE *arch;
   system ("cls");
   
   arch=fopen("datos.dat","rb");
   if(!arch)
    {
      printf("NO HAY REGISTRO\n");
    } 

   while(fread(&registro,sizeof(struct _tdato),1,arch)&&band==FALSE)
    {
      if(registro.matri==Matri)
    	{
    	       
    	   printf("ALUMNO\n");
           printf("\nMATRICULA    APPATERNO   APMATERNO     NOMBRE               EDAD   SEXO   ESTADO\n");
   	       printf("%-12ld %-12s %-12s %-21s %-5d %3s %5d\n",registro.matri,registro.apPat,registro.apMat,registro.nombre,registro.edad,registro.sexo,registro.statu);
   	       printf("-------------------------------------------------------------------------------\n");
    	   fclose(arch);
			band=TRUE;	   
	   }
   
	}
	
	 if(band==FALSE)
	   {
	   	printf("NO HAY REGISTRO\n");
	   }
	system("pause");
}

void burbuja(Talumno A[], int n)
{
	int i, j;
	Talumno aux;
	for(j=0;j<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(A[j+1].matri < A[j].matri)
			{
				aux=A[j+1];
				A[j+1]=A[j];
				A[j]=aux;
			}
		}
	}
	system("pause");
}

void salida()
{
	Talumno registro;
	int i=0;
	char nombre[15];
	system("cls");

	FILE *arch,*texto;
	arch=fopen("datos.dat","rb");
    if(!arch)
      {
      	printf("NO HAY REGISTROS\n");
    	system("pause");
    	return;
      }
      printf("NOMBRE DEL ARCHIVO:\n");
      fflush(stdin); 
	  gets(nombre);
      strcat(nombre,".txt");
      texto=fopen(nombre,"w");
      rewind(texto);
      fprintf(texto,"                                   ALUMNO\n");
      fprintf(texto,"\nMATRICULA    APPATERNO   APMATERNO     NOMBRE               EDAD   SEXO   ESTADO\n");
	  while(fread(&registro,sizeof(struct _tdato),1,arch))
             {
                fprintf(texto,"%-3d %-12ld %-12s %-12s %-21s %-5d %3s %5d\n",i+1,registro.matri, registro.apPat,registro.apMat,registro.nombre,registro.edad,registro.sexo,registro.statu);
   	            fprintf(texto,"-------------------------------------------------------------------------------\n");
                i++;
            }
      printf("\nARCHIVO CREADO\n");
      fclose(arch);
      fclose(texto);
      system("pause");
}

char* leecadena(char*msge) 
{
	char cadena[40], NOespa[40];
	int letra,i,x,n,j,k;
	system("cls");
	printf("%s\n",msge);
	i=0;
	do{
		letra=getch();
		if((letra== 'm') || (letra=='f')||((letra=='M')||(letra=='F')))
		{
		    x=toupper(letra);
			printf("%c",x);
			cadena[i]=x;
			i++;
		}
	}while (letra!=13);
	cadena[i]='\0';
	return cadena;
}

int validanum(long r1, long r2, char *msge, char *merror)
{
	char xnum[30];
	long num;
	do{
		system("cls");
		printf("%s:",msge);
		fflush(stdin);
		gets(xnum);
		num=atol(xnum);
		if(num<r1||num>r2)
		{
			printf("%s",merror);
			delay(250);
		}
		
	}while(num<r1||num>r2);
	return num;
}

void delay(int tiempo)
{
  int i,j;
  for(i=0;i<tiempo*100;i++)
     {
	   for(j=0;j<tiempo*100;j++);
	 }
}

