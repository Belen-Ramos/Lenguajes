def IngresoDatos():
    for x in Datos:
        Datos[x] = input("Ingrese su " + x + ": ")
        
        if x == "mail":
            while ("@" in Datos[x]) == False:
                Datos[x] = input("Su " + x + " no es valido, por favor vuelva a ingresarlo:\n")
        
        if x == "telefono" or x == "edad" or x == "peso":
            while (Datos[x].isdigit()) == False:
                Datos[x] = input("Su " + x + " no es valido, por favor solo ingrese valores numericos:\n")
              
        if x == "peso" or x == "altura":
            Datos[x] = float(Datos[x])

def CalcularIMC():
    Datos["IMC"] = Datos["peso"]/(Datos["altura"]**2)

def cat_imc(IMC):
    print("\n")
    if IMC < 18.5:
        print("Usted tiene bajo peso")
    elif IMC >= 18.5 and IMC < 25:
        print("Usted tiene peso normal")
    elif IMC >= 25 and IMC < 30:
        print("Usted tiene sobre peso")
    elif IMC >= 30 and IMC < 35:
        print("Usted tiene obesidad tipo I")
    elif IMC >= 35 and IMC < 40:
        print("Usted tiene obesidad tipo II")
    elif IMC >=40:
        print("Usted tiene obesidad tipo III")

def Imprimir(Datos):
    print("\nSus datos son:")
    for x in Datos:
        if x != "peso" and x != "altura" and x != "IMC":
            print("   " + x.capitalize() + ": " + Datos[x].upper())
        else:
            print(f"   " + x.capitalize() + ": {:.2f}".format(Datos[x]))
   
Datos = {
    "nombre": "", 
    "apellido": "",
    "mail": "",
    "edad": 0,
    "telefono": 0,
    "direccion": "",
    "peso": 0,
    "altura": 0
}
IngresoDatos()
CalcularIMC()
cat_imc(Datos["IMC"])
Imprimir(Datos)