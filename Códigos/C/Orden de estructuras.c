#include <stdio.h>
#include <stdlib.h>

#define CantNotas 3

void CrearAlumno(void);
void UbicarPromedio(void);
void UbicarAlfabeticamente (void);
void ImprimirLista(void);


float Prom, SumaN=0;
int Elegir, Cant, Orden;

struct Alumnos
{
    char Nombre[15];
    char Apellido[15];
    int Notas[CantNotas];
    float Promedio;
    struct Alumnos *next;
}Alumno;

struct Alumnos *Lista = NULL;
struct Alumnos *p = NULL;

int main()
{
    printf("¿Desea ingresar alumnos? 1:Si 2:No\n");
    scanf("%d", &Elegir);
    while(Elegir == 1)
    {
        printf("¿Cuantos desea ingresar?\n");
        scanf("%d", &Cant);
        printf("¿Quiere ordenar alfabéticamente (1) o por promedio (2)?\n");
        scanf("%d", &Orden);
        
        if(Orden == 1)
        {
            for(int i=0; i<Cant; i++)
            {
                CrearAlumno();
                UbicarAlfabeticamente();
            }
        }
        
        if(Orden == 2)
        {
            for(int i=0; i<Cant; i++)
            {
                CrearAlumno();
                UbicarPromedio();
            }
        }
        printf("¿Desea ingresar más alumnos? 1:Si 2:No\n");
        scanf("%d", &Elegir);
    }
    
    printf("¿Desea imprimir la lista de alumnos? 1:Si 2:No\n");
    scanf("%d", &Elegir);
    if(Elegir == 1)
        ImprimirLista();

    return 0;
}

void CrearAlumno(void)
{
    p = malloc(sizeof(struct Alumnos));
    printf("\nIngrese el nombre del alumno\n");
    scanf("%s", p->Nombre);
    printf("Ingrese el apellido del alumno\n");
    scanf("%s", p->Apellido);
    printf("Ingrese las notas del alumno\n");
        
    for(int j=0; j<CantNotas; j++)
    {
        scanf("%d", &p->Notas[j]);
        SumaN= SumaN + p->Notas[j];
    }
    
    (p->Promedio) = SumaN/CantNotas;
    SumaN=0;
}

void UbicarPromedio (void)
{
    if(Lista == NULL)
    {
        Lista = p;
        Lista->next = NULL;
    }
    
    else
    {
        if(Lista->Promedio < p->Promedio)
        {
            p->next = Lista;
            Lista = p;
        }
        
        else
        {
            struct Alumnos *Aux = Lista;
        
            while(((Aux->next) != NULL)&&(((Aux->next)->Promedio) >= (p->Promedio)))
                Aux = Aux->next;
                
            p->next = Aux->next;
            Aux->next = p;
        }
    }
}

void UbicarAlfabeticamente (void)
{
    if(Lista == NULL)
    {
        Lista = p;
        Lista->next = NULL;
    }
    
    else
    {
        if(Lista->Apellido[0] > p->Apellido[0])
        {
            p->next = Lista;
            Lista = p;
        }
        
        else
        {
            struct Alumnos *Aux = Lista;
        
            while(((Aux->next) != NULL)&&(((Aux->next)->Apellido[0]) <= (p->Apellido[0])))
                Aux = Aux->next;
                
            p->next = Aux->next;
            Aux->next = p;
        }
    }
}

void ImprimirLista(void)
{
    struct Alumnos *Aux = Lista;
    printf("\nLista de alumnos:\n");
    while(Aux != NULL)
    {
        printf("%s %s: %.2f \n", Aux->Apellido, Aux->Nombre, Aux->Promedio);
        Aux = Aux->next;
    }
}
