#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>

void Calcular_RFC ();

char* Pedir_Datos_Cadena(int Li, int Ls, char* msge);
char* Pedir_Datos_Numero(int Li, int Ls, char* msge);

int main()
{
    Calcular_RFC();

    system("PAUSE");
    return 0;
}

void Calcular_RFC ()
{
    char RFC[11], Paterno[30], Materno[30], Nombre[30], Anio[5], Mes[3], Dia[3];
    strcpy (Paterno, Pedir_Datos_Cadena(0, 0, "Apellido Paterno"));
    strcpy (Materno, Pedir_Datos_Cadena(0, 0, "Apellido Materno"));
    strcpy (Nombre, Pedir_Datos_Cadena(0, 0, "Nombre"));
    strcpy (Anio, Pedir_Datos_Numero(1900, 2016, "Año de nacimiento"));
    strcpy (Mes, Pedir_Datos_Numero(1, 12, "Mes de nacimiento"));
    strcpy (Dia, Pedir_Datos_Numero(1, 31,"Dia de nacimiento"));

    strupr(Paterno);
    strupr(Materno);
    strupr(Nombre);
    //CALCULAR RFC
    RFC[0] = Paterno[0];
    RFC[1] = Paterno[1];
    RFC[2] = Materno[0];
    RFC[3] = Nombre[0];
    RFC[4] = Anio[2];
    RFC[5] = Anio[3];
    RFC[6] = Mes[0];
    RFC[7] = Mes[1];
    RFC[8] = Dia[0];
    RFC[9] = Dia[1];
    RFC[10] = '\0';

    printf("RFC: * %s *\n", RFC);

}

char *Pedir_Datos_Cadena(int Li, int Ls, char *msge)
{
    int iVariable;
    char Variable[30];
    do
    {
        printf("   ");
        puts(msge);
        printf("\tIngrese sus datos: ");
        gets(Variable);
        iVariable = atoi(Variable);
        printf("\n");
        if ( (Variable[0] == '0' || iVariable != 0 || Variable[0] == NULL) )
        {
            printf("ERROR; VALORES NO VALIDOS!\n");
        }
    }while ( (Variable[0] == '0' || iVariable != 0 || Variable[0] == NULL) );

    return Variable;
}

char *Pedir_Datos_Numero(int Li, int Ls, char *msge)
{
    int iVariable;
    char Variable[30];
    do
    {
        printf("   ");
        puts(msge);
        printf("\tIngrese sus datos: ");
        gets(Variable);
        iVariable = atoi(Variable);
        printf("\n");
        if ( iVariable < Li || iVariable > Ls || Variable[0] == NULL )
        {
            printf("ERROR; VALORES NO VALIDOS!\n");
        }
    }while ( iVariable < Li || iVariable > Ls || Variable[0] == NULL );

    return Variable;
}
