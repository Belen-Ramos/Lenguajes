#include <stdio.h>
#include <string.h>

#define CantNotas 3
#define CantAl 2

void IngresoDatos(void);
void OrdenNotas (void);
void OrdenAlfabetico(void);
void ImprimirAlumnos (void);


float Prom, SumaN=0;
int Eleccion;

struct Alumnos
{
    char Nombre[15];
    char Apellido[15];
    int Notas[CantNotas];
    float Promedio;
}Alumno[CantAl];

int main()
{
    IngresoDatos();
    printf("¿Desea ordenar alfabéticamente (1) o por promedio (2)?\n");
    scanf("%d", &Eleccion);
    
    while(Eleccion != 1 && Eleccion != 2)
    {
        printf("\nHa habido un error, ingrese 1 o 2\n");
        scanf("%d", &Eleccion);
    }
    
    if(Eleccion == 1)
    {
        printf("\nSe ordenarán los alumnos alfabéticamente por apellido:\n\n");
        OrdenAlfabetico();
    }
    
    if (Eleccion == 2)
    {
        printf("\nSe ordenarán los alumnos de mayor a menor promedio:\n\n");
        OrdenNotas();
    }
    
    ImprimirAlumnos();
    return 0;
}

void IngresoDatos(void)
{
    for (int i=0; i<CantAl;i++)
    {
        printf("Ingrese el nombre del alumno\n");
        scanf("%s", Alumno[i].Nombre);
        printf("\nIngrese el apellido del alumno\n");
        scanf("%s", Alumno[i].Apellido);
        printf("\nIngrese las notas del alumno\n");
        
        for(int j=0; j<CantNotas; j++)
        {
            scanf("%d", &Alumno[i].Notas[j]);
            SumaN= SumaN + Alumno[i].Notas[j];
           
        }
        Alumno[i].Promedio = SumaN/CantNotas;
        SumaN=0;
        printf("\n");
    }
}

void OrdenNotas (void)
{
    char auxNom[15];
    char auxA[15];
    int auxNot[CantNotas];
    float auxP;
    
    int j;
    
    for(int i=1; i<CantAl; i++)
    {
        j=i;
        //Si el promedio de alumno j es mayor al de j-1, cambian de lugar
        while(j>0 && Alumno[j].Promedio>Alumno[j-1].Promedio)
        {
            auxP = Alumno[j].Promedio;
            Alumno[j].Promedio = Alumno[j-1].Promedio;
            Alumno[j-1].Promedio = auxP;
    
            strcpy(auxA, Alumno[j].Apellido);
            strcpy(Alumno[j].Apellido, Alumno[j-1].Apellido);
            strcpy(Alumno[j-1].Apellido, auxA);
            
            strcpy(auxNom,Alumno[j].Nombre);
            strcpy(Alumno[j].Nombre,Alumno[j-1].Nombre);
            strcpy(Alumno[j-1].Nombre,auxNom);
            
            for(int k=0; k<CantNotas; k++)
            {
                auxNot[k] = Alumno[j].Notas[k];
                Alumno[j].Notas[k] = Alumno[j-1].Notas[k];
                Alumno[j-1].Notas[k] = auxNot[k];
            }
            j--;
        }
    }
}

void OrdenAlfabetico(void)
{
    char auxNom[15];
    char auxA[15];
    int auxNot[CantNotas];
    float auxP;
    
    int j;
    
    for(int i=1; i<CantAl; i++)
    {
        j=i;
        //Si el apellido del alumno j está antes alfabéticamente que el del alumno j-1, cambian de lugar.
        while(j>0 && Alumno[j].Apellido[0]<Alumno[j-1].Apellido[0])
        {
            auxP = Alumno[j].Promedio;
            Alumno[j].Promedio = Alumno[j-1].Promedio;
            Alumno[j-1].Promedio = auxP;
    
            strcpy(auxA, Alumno[j].Apellido);
            strcpy(Alumno[j].Apellido, Alumno[j-1].Apellido);
            strcpy(Alumno[j-1].Apellido, auxA);
            
            strcpy(auxNom,Alumno[j].Nombre);
            strcpy(Alumno[j].Nombre,Alumno[j-1].Nombre);
            strcpy(Alumno[j-1].Nombre,auxNom);
            
            for(int k=0; k<CantNotas; k++)
            {
                auxNot[k] = Alumno[j].Notas[k];
                Alumno[j].Notas[k] = Alumno[j-1].Notas[k];
                Alumno[j-1].Notas[k] = auxNot[k];
            }
            j--;
        }
    }
}

void ImprimirAlumnos (void)
{
    for(int i=0; i<CantAl; i++)
    {
        printf("Alumno: %s %s\n", Alumno[i].Apellido, Alumno[i].Nombre);
        printf("Promedio: %.2f\n\n", Alumno[i].Promedio);
    }
}
