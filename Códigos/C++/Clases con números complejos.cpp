#include <iostream>
#include <math.h>

#define PASAJE 0.01745329251 //PI/180
#define PI 3.14159265359

void PaseABinomial(void);
void PaseAPolar(void);
void Suma(void);
void Resta(void);
void Multiplicacion(void);
void Division(void);

using namespace std;

char Eleccion = 'a';

class Complejo
{
    public:
        float Modulo, Angulo, Rad, Real, Imag;
        
        Complejo(void)
        {
            Modulo = 0;
            Angulo = 0;
            Rad = 0;
            Real = 0;
            Imag = 0;
        }
        
        void ABinomial(float Modulo, float Rad)
        {
            Real = Modulo*cos(Rad);
            Imag = Modulo*sin(Rad);
        }
        
        void APolar(float Real, float Imag)
        {
            Modulo = sqrt(Real*Real + Imag*Imag);
            Rad = atan2(Imag,Real);
            
            Angulo = Rad/PASAJE;
        }
};

Complejo operator + (const Complejo Num1, const Complejo Num2)
{
    Complejo Suma;
    Suma.Real = Num1.Real + Num2.Real;
    Suma.Imag = Num1.Imag + Num2.Imag;
    return Suma;
}

Complejo operator - (const Complejo Num1, const Complejo Num2)
{
    Complejo Resta;
    Resta.Real = Num1.Real - Num2.Real;
    Resta.Imag = Num1.Imag - Num2.Imag;
    return Resta;
}

Complejo operator * (const Complejo Num1, const Complejo Num2)
{
    Complejo Producto;
    Producto.Modulo = Num1.Modulo * Num2.Modulo;
    Producto.Angulo = Num1.Angulo + Num2.Angulo;
    return Producto;
}

Complejo operator / (const Complejo Num1, const Complejo Num2)
{
    Complejo Cociente;
    Cociente.Modulo = Num1.Modulo / Num2.Modulo;
    Cociente.Angulo = Num1.Angulo - Num2.Angulo;
    return Cociente;
}

int main()
{
    while(Eleccion != '0')
    {
        cout<<"**********************************************"<<endl
        <<"|  ¿Qué desea hacer?                         |\n"
        <<"|      1: Pasar número a binomial            |\n"
        <<"|      2: Pasar número a polar               |\n"
        <<"|      3: Sumar dos números complejos        |\n"
        <<"|      4: Restar dos números complejos       |\n"
        <<"|      5: Multiplicar dos números complejos  |\n"
        <<"|      6: Dividir dos números complejos      |\n"
        <<"|      0: Terminar                           |\n"
        <<"**********************************************"<<endl;
        
        cin>>Eleccion;
        
        switch(Eleccion)
        {
            case '1':
                cout<<"Ha elegido pasar su número a binomial"<<endl;
                PaseABinomial();
                break;
            case '2':
                cout<<"Ha elegido pasar su número a polar"<<endl;
                PaseAPolar();
                break;
            case '3':
                cout<<"Ha elegido sumar dos números complejos"<<endl;
                Suma();
                break;
            case '4':
                cout<<"Ha elegido restar dos números complejos"<<endl;
                Resta();
                break;
            case '5':
                cout<<"Ha elegido multiplicar dos números complejos"<<endl;
                Multiplicacion();
                break;
            case '6':
                cout<<"Ha elegido dividir dos números complejos"<<endl;
                Division();
                break;
            case '0':
                cout<<"Ha terminado el programa"<<endl;
                break;
        }
    }
    return 0;
}

void PaseABinomial(void)
{
    Complejo Num1;
    cout<<"Ingrese el módulo: ";
    cin>>Num1.Modulo;
    cout<<"Ingrese el ángulo en grados: ";
    cin>>Num1.Angulo;
    
    Num1.Rad = Num1.Angulo*PASAJE;
    
    Num1.ABinomial(Num1.Modulo, Num1.Rad);
    
    cout<<endl<<"----------------------------------------------"<<endl;
    cout<<" Su número en binomial es: "<<Num1.Real<<" + "<<Num1.Imag<<"j"<<endl; 
    cout<<"----------------------------------------------"<<endl<<endl;
}

void PaseAPolar(void)
{
    Complejo Num1;
    cout<<"Ingrese la parte real: ";
    cin>>Num1.Real;
    cout<<"Ingrese la parte imaginaria: ";
    cin>>Num1.Imag;

    Num1.APolar(Num1.Real, Num1.Imag);
    
    cout<<endl<<"----------------------------------------------"<<endl;
    cout<<" Su número en polar es: "<<Num1.Modulo<<" | "<<Num1.Angulo<<"°"<<endl;
    cout<<"----------------------------------------------"<<endl<<endl;
}

void Suma(void)
{
    Complejo Num1, Num2, Suma;
    int Tipo;
    
    cout<<"¿Sus números estan en polar (1) o binomial (2)?"<<endl;
    cin>>Tipo;
    
    if(Tipo == 1)
    {
        cout<<"Ingrese el módulo y ángulo del primer número: ";
        cin>>Num1.Modulo>>Num1.Angulo;
        cout<<"Ingrese el módulo y ángulo del segundo número: ";
        cin>>Num2.Modulo>>Num2.Angulo; 
        
        Num1.Rad = Num1.Angulo*PASAJE;
        Num2.Rad = Num2.Angulo*PASAJE;
    
        Num1.ABinomial(Num1.Modulo, Num1.Rad);
        Num2.ABinomial(Num2.Modulo, Num2.Rad);
    }
    if(Tipo == 2)
    {
        cout<<"Ingrese la parte real e imaginaria del primer número (sin el +): ";
        cin>>Num1.Real>>Num1.Imag;
        cout<<"Ingrese la parte real e imaginaria del segundo número (sin el +): ";
        cin>>Num2.Real>>Num2.Imag; 
    }
    
    Suma = Num1+Num2;
    cout<<endl<<"----------------------------------------------"<<endl;
    cout<<" El total es: "<<Suma.Real<<" + "<<Suma.Imag<<"j"<<endl;
    cout<<"----------------------------------------------"<<endl<<endl;
}

void Resta(void)
{
    Complejo Num1, Num2, Resta;
    int Tipo;
    
    cout<<"¿Sus números estan en polar (1) o binomial (2)?"<<endl;
    cin>>Tipo;
    
    if(Tipo == 1)
    {
        cout<<"Ingrese el módulo y ángulo del primer número: ";
        cin>>Num1.Modulo>>Num1.Angulo;
        cout<<"Ingrese el módulo y ángulo del segundo número: ";
        cin>>Num2.Modulo>>Num2.Angulo; 
        
        Num1.Rad = Num1.Angulo*PASAJE;
        Num2.Rad = Num2.Angulo*PASAJE;
    
        Num1.ABinomial(Num1.Modulo, Num1.Rad);
        Num2.ABinomial(Num2.Modulo, Num2.Rad);
    }
    if(Tipo == 2)
    {
        cout<<"Ingrese la parte real e imaginaria del primer número (sin el +): ";
        cin>>Num1.Real>>Num1.Imag;
        cout<<"Ingrese la parte real e imaginaria del segundo número (sin el +): ";
        cin>>Num2.Real>>Num2.Imag; 
    }
    
    Resta = Num1-Num2;
    cout<<endl<<"----------------------------------------------"<<endl;
    cout<<" El total es: "<<Resta.Real<<" + "<<Resta.Imag<<"j"<<endl;
    cout<<"----------------------------------------------"<<endl<<endl;
}

void Multiplicacion(void)
{
    Complejo Num1, Num2, Producto;
    int Tipo;
    
    cout<<"¿Sus números estan en polar (1) o binomial (2)?"<<endl;
    cin>>Tipo;
    
    if(Tipo == 1)
    {
        cout<<"Ingrese el módulo y ángulo del primer número: ";
        cin>>Num1.Modulo>>Num1.Angulo;
        cout<<"Ingrese el módulo y ángulo del segundo número: ";
        cin>>Num2.Modulo>>Num2.Angulo; 
    }
    if(Tipo == 2)
    {
        cout<<"Ingrese la parte real e imaginaria del primer número (sin el +): ";
        cin>>Num1.Real>>Num1.Imag;
        cout<<"Ingrese la parte real e imaginaria del segundo número (sin el +): ";
        cin>>Num2.Real>>Num2.Imag;   
        
        Num1.APolar(Num1.Real, Num1.Imag);
        Num2.APolar(Num2.Real, Num2.Imag);
        
        Num1.Angulo = Num1.Rad/PASAJE;
        Num2.Angulo = Num2.Rad/PASAJE;
    }
    
    Producto = Num1*Num2;
    
    while(Producto.Angulo >= 360)
        Producto.Angulo -= 360;

    while(Producto.Angulo <= -360)
        Producto.Angulo += 360;

    cout<<endl<<"----------------------------------------------"<<endl;
    cout<<" El total es: "<<Producto.Modulo<<" | "<<Producto.Angulo<<"°"<<endl;
    cout<<"----------------------------------------------"<<endl<<endl;
}

void Division(void)
{
    Complejo Num1, Num2, Cociente;
    int Tipo;
    
    cout<<"¿Sus números estan en polar (1) o binomial (2)?"<<endl;
    cin>>Tipo;
    
    if(Tipo == 1)
    {
        cout<<"Ingrese el módulo y ángulo del primer número: ";
        cin>>Num1.Modulo>>Num1.Angulo;
        cout<<"Ingrese el módulo y ángulo del segundo número: ";
        cin>>Num2.Modulo>>Num2.Angulo; 
    }
    if(Tipo == 2)
    {
        cout<<"Ingrese la parte real e imaginaria del primer número (sin el +): ";
        cin>>Num1.Real>>Num1.Imag;
        cout<<"Ingrese la parte real e imaginaria del segundo número (sin el +): ";
        cin>>Num2.Real>>Num2.Imag;  
        
        Num1.APolar(Num1.Real, Num1.Imag);
        Num2.APolar(Num2.Real, Num2.Imag);
        
        Num1.Angulo = Num1.Rad/PASAJE;
        Num2.Angulo = Num2.Rad/PASAJE;
    }
    
    Cociente = Num1/Num2;
    
    while(Cociente.Angulo >= 360)
        Cociente.Angulo -= 360;

    while(Cociente.Angulo <= -360)
        Cociente.Angulo += 360;

    cout<<endl<<"----------------------------------------------"<<endl;
    cout<<" El total es: "<<Cociente.Modulo<<" | "<<Cociente.Angulo<<"°"<<endl;
    cout<<"----------------------------------------------"<<endl<<endl;
}