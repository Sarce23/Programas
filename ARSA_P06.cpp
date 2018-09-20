#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

char *validcadena(int ,char *, char *);
char *validfecha(int, int, int, int ad, char*, char*);
void Soli(void);
char *Rfc(char *,char *,char *,char *,char *,char *,char *,char *);
void Curp(char *rfc, char *appat, char *apmat, char *nom, char *sexo, char* estado, char *anio);

int main()
{
	Soli();
	return 0;
}

void Soli(void)
{
	char appat[30],apmat[30],nom[30],anio[5],dia[3],mes[3],sexo[10],estado[30];
	int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	printf("\tRFC || CURP\n");
	
	strcpy(appat, validcadena(30,"Apellido paterno:\n","Los apellidos no llevan numeros"));
	strcpy(apmat, validcadena(30,"Apellido Materno:\n","Los apellidos no llevan numeros"));
	strcpy(nom, validcadena(30,"Nombre(s):\n","Los nombres no llevan numeros"));
	strcpy(anio, validfecha(1900,2016,2,2,"Anio de nacimiento:\n","Solo valido para años de 1960-2016"));
	strcpy(mes, validfecha(1,12,2,0,"Mes de nacimiento:\n","Por Favor ingrese los meses en su valor numerico 01(Enero)-12(Diciembre)"));
	
	if( atoi(mes) == 2 && atoi(anio)%4 != 0 )
	  {
	  	m[2]=29;
	  }
	  
	strcpy(dia, validfecha(1,m[atoi(mes)],2,0,"Dia de nacimiento:\n","El dia es incorrecto, Por favor ingrese un dia valido"));
	strcpy(sexo, validcadena(10,"Hombre || Mujer\n","El sexo esta incorrecto, por favor rectifiquelo"));
	strcpy(estado,validcadena(2,"Siglas de tu Estado:\n","Escribe solo las siglas del estado, rectifiquelo"));
	
	RFC(appat,apmat,nom,anio,mes,dia,sexo,estado);
	
}

char *Rfc(char *appat,char *apmat,char *nom,char *anio,char *mes,char *dia,char *sexo, char *estado)
{
	char rfc[11], palim[10][5]={{"PEDO"},{"PUTA"},{"PUTO"},{"PENE"},{"PITO"},{"CACA"},{"LOCA"},{"CULO"},{"COJE"},{"JOTO"}};
	int i=1,r,c;
	
	rfc[0]=appat[0];
	rfc[1]=appat[1];
	
	while( rfc[1] != 'A' && rfc[1] != 'E' && rfc[1] != 'I' && rfc[1] != 'O' && rfc[1] != 'U')
       {
            rfc[1]=appat[i++];              
       }
       
	rfc[2]=apmat[0];
	rfc[3]=nom[0];
	rfc[4]=anio[0];
	rfc[5]=anio[1];
	rfc[6]=mes[0];
	rfc[7]=mes[1];
	rfc[8]=dia[0];
	rfc[9]=dia[1];
	rfc[10]='\0';
	
	for( r=0; i < 10; i++ )
	{
		if( rfc[0] == palim[i][0] && rfc[1] == palim[i][1] && rfc[2] == palim[i][2] && rfc[3] == palim[i][3] )
			{
		  		rfc[1]='X';
		  	} 
	}
	CURP(rfc,appat,apmat,nom,sexo,estado,anio);
    printf("\nTu Rfc Generado es: %s\n",rfc);
    system("pause");
}

void Curp(char *rfc,char *appat, char *apmat, char *nom, char *sexo,char *estado,char *anio)
{
	char curp[18],udig[11]={'0','1','2','3','4','5','6','7','8','9'},enie[3]={'Ñ','ñ'};
	int i=3,xnum;
	
	strcpy(curp,rfc);
	curp[10]=sexo[0];
	curp[11]=estado[0];
	curp[12]=estado[1];
	curp[13]=appat[2];
	
	if( strncmp(nom,"JOSE",4) == 0 )
	  {
	  	curp[3]= nom[5];
	  } 
	else
	  {
	  	if( strncmp(nom,"MARIA",5) == 0 )
	  	  {
	  	  	curp[3]=nom[6];
	      }
	  }
	  
	while( curp[13] == 'A' || curp[13] == 'E' || curp[13] == 'I' || curp[13] == 'O' || curp[13] == 'U' )
       {
            curp[13]=appat[i++];              
       }
       
    xnum=curp[13];  
	 
	if( xnum == -92 || xnum == -91 )
	  {
	  	curp[13]='X';
	  } 
	  
    curp[14]=apmat[1];
    i=1;
    
	while( curp[14] == 'A' || curp[14] == 'E' || curp[14] == 'I' || curp[14] == 'O' || curp[14] == 'U' )
       {
            curp[14]=apmat[i++];              
       }
       
    curp[15]=nom[1];
    i=1;
    
    while( curp[15] == 'A' || curp[15] == 'E' || curp[15] == 'I' || curp[15] == 'O' || curp[15] == 'U' )
       {
            curp[15]=nom[i++];              
       }
       
    if( atoi(anio) < 2000 )
      {
      	curp[16]='0';
	  }
	else
	  {
	  	curp[16]='1';
	  }
	  
	srand(time(NULL));
	curp[17]=udig[rand()%10];
	curp[18]='\0';
	printf("\nTu Curp Generado es es: %s",curp);
}

char *validcadena(int indice,char *msn, char *msnerror)
{
	char cadena[30],rfc[3];
	int num,i;
	
	do{
		
		puts(msn);
		fflush(stdin);
		gets(cadena);
		strupr(cadena);
		num= atoi(cadena);
		
		if( num != 0 || num == '0' || strlen(cadena) > indice )
		  {
		  	puts(msnerror);
		  }
	  }while( num != 0 || cadena[0] == '0' || strlen(cadena) > indice );
	  
	return cadena;
}

char *validfecha(int Li, int Ls, int indice, int ad, char *msn, char *msnerror)
{
	char fecha[5], rfc[3];
	int num,i;
	
	do{
		puts(msn);
		fflush(stdin);
		gets(fecha);
		num=atoi(fecha);
		
		for( i=0; i < indice; i++ )
		   {
		   	rfc[i]=fecha[i+ad];
		   }
		   
		if( num == 0 || num < Li || num > Ls )
	  	  {
	  		puts(msnerror);
	  	  }
	  	  
	  	if( fecha[0] != '0' && num < 10 )
	  	  {
	  	  	rfc[0]='0';
	  	  	rfc[1]=fecha[0];
		  }
		  
		rfc[2]='\0';
		
	   }while( (num < Li || num > Ls) || (num == 0 && fecha[0] != '0') );
	   
	return rfc;
}
