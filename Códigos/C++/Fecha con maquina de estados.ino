#include <LiquidCrystal.h>
//                RS, E, D4,D5,D6,D7
LiquidCrystal lcd(11, 10, 8, 5, 6, 7);

#define MAS (digitalRead(2) == HIGH)
#define MENOS (digitalRead(3) == HIGH)
#define OK (digitalRead(4) == HIGH)
#define PAR (DecYear == 0 || DecYear == 2 || DecYear == 4 || DecYear == 6 || DecYear == 8)
#define IMPAR (DecYear == 1 || DecYear == 3 || DecYear == 5 || DecYear == 7 || DecYear == 9) 

const int TablaMes[] = {0,6,2,2,5,0,3,5,1,4,6,2,4};
const int TablaSiglo[] = {0,5,3,1};

void DecenaDia (void);
void UnidadDia_1 (void);
void UnidadDia_2 (void);
void UnidadDia_3 (void);
void DecenaMes (void);
void UnidadMes_0 (void);
void UnidadMes_1 (void);
void UnidadMes_2 (void);
void UnidadMes_3 (void);
void UnidadMes_4 (void);
void MilenioYear (void);
void CentenaYear (void);
void DecenaYear (void);
void UnidadYear_0 (void);
void UnidadYear_1 (void);
void UnidadYear_2 (void);
void CalculoDia (void);
void Fin (void);

int DecDia = 0, UniDia = 1, DecMes = 0, UniMes = 1, MilYear = 0, CenYear = 0, DecYear = 0, UniYear = 0;
void (*Funcion)(void) = DecenaDia;

void setup(void){
  //Inicio el LCD
  lcd.begin(16, 2);
  
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  
  lcd.setCursor(3, 0);
  lcd.print("01/01/0000");
  lcd.setCursor(0, 1);
  lcd.print("Decena Dia");
}

void loop(void){
  if(OK || MAS || MENOS){
    Funcion();
    delay(500);
  }
}

void DecenaDia (void){
  if(MAS && DecDia <3)DecDia++;
  else{
  if(MAS && DecDia >=3)DecDia = 0;
  }
  if(MENOS && DecDia >0)DecDia--;
  else{
    if(MENOS && DecDia <=0)DecDia = 3;
  }
  
  lcd.setCursor(3, 0);
  lcd.print(DecDia);
  
  if(OK && DecDia == 3){
    Funcion= &UnidadDia_3;
    lcd.setCursor(0, 1);
    lcd.print("Unidad dia");
  }
  else{
    if(OK && (DecDia == 2 || DecDia == 1)){
      Funcion= &UnidadDia_2;
      lcd.setCursor(0, 1);
      lcd.print("Unidad dia");
    }
    else{
      if(OK && DecDia == 0){
      Funcion = &UnidadDia_1;
      lcd.setCursor(0, 1);
      lcd.print("Unidad dia");
      }
    }
  }
}

void UnidadDia_1 (void){
  if(MAS && UniDia <9)UniDia++;
  else{
  if(MAS && UniDia >=9)UniDia = 1;
  }
  if(MENOS && UniDia >1)UniDia--;
  else{
  if(MENOS && UniDia <=1)UniDia = 9;
  }
    
  lcd.setCursor(4, 0);
  lcd.print(UniDia);
  
  if(OK){
    Funcion= &DecenaMes;
    lcd.setCursor(0, 1);
    lcd.print("Decena mes");
  }
}

void UnidadDia_3 (void){
  if((MAS || MENOS) && UniDia == 0)UniDia = 1;
  else{
  if((MAS || MENOS) && UniDia == 1)UniDia = 0;
  }
  
  lcd.setCursor(4, 0);
  lcd.print(UniDia);
  
  if(OK){
    Funcion= &DecenaMes;
    lcd.setCursor(0, 1);
    lcd.print("Decena mes");
  }
}

void UnidadDia_2 (void){
  if(MAS && UniDia <9)UniDia++;
  else{
  if(MAS && UniDia >=9)UniDia = 0;
  }
  if(MENOS && UniDia >0)UniDia--;
  else{
  if(MENOS && UniDia <=0)UniDia = 9;
  }
  
  lcd.setCursor(4, 0);
  lcd.print(UniDia);
  
  if(OK){
    Funcion= &DecenaMes;
    lcd.setCursor(0, 1);
    lcd.print("Decena mes");
  }
}

void DecenaMes (void){
  if((MAS || MENOS) && DecMes == 0)DecMes = 1;
  else{
  if((MAS || MENOS) && DecMes == 1)DecMes = 0;
  }
  
  lcd.setCursor(6, 0);
  lcd.print(DecMes);
  
  if(OK && DecMes == 0 && DecDia <= 2){
    Funcion = &UnidadMes_0;
    lcd.setCursor(0, 1);
    lcd.print("Unidad mes");
  }
  if(OK && DecMes == 0 && DecDia == 3 && UniDia == 0){
    Funcion = &UnidadMes_1;
    lcd.setCursor(0, 1);
    lcd.print("Unidad mes");
  }
  if(OK && DecMes == 0 && DecDia == 3 && UniDia == 1){
    Funcion = &UnidadMes_2;
    lcd.setCursor(0, 1);
    lcd.print("Unidad mes");
  }
  if(OK && DecMes == 1 && (DecDia <=2 || (DecDia == 3 && UniDia == 0))){
    Funcion = &UnidadMes_3;
    lcd.setCursor(0, 1);
    lcd.print("Unidad mes");
  }
  if(OK && DecMes == 1 && DecDia == 3 && UniDia == 1){
    Funcion = &UnidadMes_4;
    lcd.setCursor(0, 1);
    lcd.print("Unidad mes");
  }
}

void UnidadMes_0 (void){
  if(MAS && UniMes <9)UniMes++;
  else{
    if(MAS && UniMes >=9)UniMes = 1;
  }
  if(MENOS && UniMes >1)UniMes--;
  else{
    if(MENOS && UniMes <=1)UniMes = 9;
  }
  
  lcd.setCursor(7, 0);
  lcd.print(UniMes);
  
  if(OK){
    Funcion= &MilenioYear;
    lcd.setCursor(0, 1);
    lcd.print("Milenio year");
  }
}

void UnidadMes_1 (void){
  if(MAS && (UniMes <1 || (UniMes >= 3 && UniMes<9)))UniMes++;
  else{
    if(MAS && UniMes == 1)UniMes = 3;
    else{
      if(MAS && UniMes >=9)UniMes = 0;
    }
  }
  if(MENOS && UniMes >3)UniMes--;
  else{
    if(MENOS && UniMes ==3)UniMes = 1;
    else{
      if(MENOS && UniMes <=1)UniMes = 9;
    }
  }
  
  lcd.setCursor(7, 0);
  lcd.print(UniMes);

  if(OK){
    Funcion= &MilenioYear;
    lcd.setCursor(0, 1);
    lcd.print("Milenio year");
  }
}

void UnidadMes_2 (void){
  if(MAS){
    switch(UniMes){
      default: 
        UniMes = 1;
        break;
      case 1: 
        UniMes = 3;
        break;
      case 3:
        UniMes = 5;
        break;
      case 5:
        UniMes = 7;
        break;
      case 7:
        UniMes = 8;
        break;
      case 8:
        UniMes = 1;
        break;
    }
  }
  if(MENOS){
    switch(UniMes){
      default: 
        UniMes = 9;
        break;
      case 1: 
        UniMes = 8;
        break;
      case 3:
        UniMes = 1;
        break;
      case 5:
        UniMes = 3;
        break;
      case 7:
        UniMes = 5;
        break;
      case 8:
        UniMes = 7;
        break;
    }
  }
  
  lcd.setCursor(7, 0);
  lcd.print(UniMes);
  
  if(OK){
    Funcion = &MilenioYear;
    lcd.setCursor(0, 1);
    lcd.print("Milenio year");
  }
}

void UnidadMes_3 (void){
  if(MAS && UniMes <2)UniMes++;
  else{
    if(MAS && UniMes >=2)UniMes = 0;
  }
  if(MENOS && UniMes >0)UniMes--;
  else{
    if(MENOS && UniMes <=0)UniMes = 2;
  }
  
  lcd.setCursor(7, 0);
  lcd.print(UniMes);

  if(OK){
    Funcion = &MilenioYear;
    lcd.setCursor(0, 1);
    lcd.print("Milenio year");
  }
}

void UnidadMes_4 (void){
  if(MAS || MENOS){
    switch(UniMes){
      default: 
        UniMes = 0;
        break;
      case 0: 
        UniMes = 2;
        break;
      case 2:
        UniMes = 0;
        break;
    }
  }
  
  lcd.setCursor(7, 0);
  lcd.print(UniMes);

  if(OK){
    Funcion = &MilenioYear;
    lcd.setCursor(0, 1);
    lcd.print("Milenio year");
  }
}

void MilenioYear (void){
  if(MAS && MilYear <9)MilYear++;
  else{
    if(MAS && MilYear >=9)MilYear = 0;
  }
  if(MENOS && MilYear >0)MilYear--;
  else{
    if(MENOS && MilYear <=0)MilYear = 9;
  }
  
  lcd.setCursor(9, 0);
  lcd.print(MilYear);

  if(OK){
    Funcion = &CentenaYear;
    lcd.setCursor(0, 1);
    lcd.print("Centena year");
  }
}

void CentenaYear (void){
  if(MAS && CenYear <9)CenYear++;
  else{
    if(MAS && CenYear >=9)CenYear = 0;
  }
  if(MENOS && CenYear >0)CenYear--;
  else{
    if(MENOS && CenYear <=0)CenYear = 9;
  }
  
  lcd.setCursor(10, 0);
  lcd.print(CenYear);

  if(OK){
    Funcion = &DecenaYear;
    lcd.setCursor(0, 1);
    lcd.print("Decena year    ");
  }
}

void DecenaYear (void){
  if(MAS && DecYear <9)DecYear++;
  else{
    if(MAS && DecYear >=9)DecYear = 0;
  }
  if(MENOS && DecYear >0)DecYear--;
  else{
    if(MENOS && DecYear <=0)DecYear = 9;
  }
  
  lcd.setCursor(11, 0);
  lcd.print(DecYear);
  
  if(OK && DecDia == 2 && UniDia == 9 && DecMes == 0 && UniMes == 2 && (PAR)){
    Funcion = &UnidadYear_1;
    lcd.setCursor(0, 1);
    lcd.print("Unidad year    ");
  }
  else{
    if(OK && DecDia == 2 && UniDia == 9 && DecMes == 0 && UniMes == 2 && (IMPAR)){
      Funcion = &UnidadYear_2;
      lcd.setCursor(0, 1);
      lcd.print("Unidad year    ");
    }
    else{
      if(OK){
          Funcion = &UnidadYear_0;
          lcd.setCursor(0, 1);
        lcd.print("Unidad year    ");
      }
    }
  }
}

void UnidadYear_0 (void){
  if(MAS && UniYear <9)UniYear++;
  else{
    if(MAS && UniYear >=9)UniYear = 0;
  }
  if(MENOS && UniYear >0)UniYear--;
  else{
    if(MENOS && UniYear <=0)UniYear = 9;
  }
  
  lcd.setCursor(12, 0);
  lcd.print(UniYear);
  
  if(OK){
    Funcion = &Fin;
    CalculoDia();
  }
}

void UnidadYear_1 (void){
  if(CenYear != 0 && DecYear == 0){
    if((MAS || MENOS) && UniYear == 4)UniYear = 8;
    else{
     if((MAS || MENOS) && UniYear == 8)UniYear = 4;
     else{
       if(MAS || MENOS)UniYear = 4;
     }
  }
  }
  else{
    if(MAS){
     switch (UniYear){
      case 0: 
          UniYear = 4;
          break;
        case 4:
          UniYear = 8;
          break;
        case 8:
          UniYear = 0;
          break;
        default:
          UniYear = 0;
          break;
     }
    }
    if(MENOS){
     switch (UniYear){
      case 0: 
          UniYear = 8;
          break;
        case 4:
          UniYear = 0;
          break;
        case 8:
          UniYear = 4;
          break;
        default:
          UniYear = 0;
          break;
     }
    }
  }
  
  lcd.setCursor(12, 0);
  lcd.print(UniYear);
  
  if(OK){
    Funcion = &Fin;
    CalculoDia();
  }
}

void UnidadYear_2 (void){
  if((MAS || MENOS) && UniYear == 6)UniYear = 2;
  else{
    if((MAS || MENOS) && UniYear == 2)UniYear = 6;
    else{
      if(MAS || MENOS)UniYear = 2;
    }
  }
  
  lcd.setCursor(12, 0);
  lcd.print(UniYear);
  
  if(OK){
    Funcion = &Fin;
    CalculoDia();
  }
}

void CalculoDia (void){
  int Dia = (10*DecDia)+UniDia;
  int Mes = (10*DecMes)+UniMes;
  int Year = (10*DecYear)+UniYear;
  int Siglo = (10*MilYear)+CenYear;
  int A = 0, B = 0, C = 0, D = 0, E = 0, R = 0, Aux = 0;

  int ModSiglo = Siglo%4;
  
  A = TablaSiglo[ModSiglo];

  Aux = Year/4;
  B = Year + Aux;

  int RestoY = Year%4;
  if(RestoY == 0 && (Mes == 1 || Mes == 2) && (CenYear == 0 || Year != 0))C = -1;
  else C = 0;
  
  D = TablaMes[Mes];
  E = Dia;
  
  R = A+B+C+D+E;

  while(R>=7){
    R = R-7;
  }

  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print(DecDia);
  lcd.print(UniDia);
  lcd.print("/");
  lcd.print(DecMes);
  lcd.print(UniMes);
  lcd.print("/");
  lcd.print(MilYear);
  lcd.print(CenYear);
  lcd.print(DecYear);
  lcd.print(UniYear);
  switch(R){
    case 0:
      lcd.setCursor(4, 1);
      lcd.print("Domingo");
      break;
    case 1:
      lcd.setCursor(5, 1);
      lcd.print("Lunes");
      break;
    case 2:
      lcd.setCursor(5, 1);
      lcd.print("Martes");
      break;
    case 3:
      lcd.setCursor(3, 1);
      lcd.print("Miercoles");
      break;
    case 4:
      lcd.setCursor(5, 1);
      lcd.print("Jueves");
      break;
    case 5:
      lcd.setCursor(4, 1);
      lcd.print("Viernes");
      break;
    case 6:
      lcd.setCursor(5, 1);
      lcd.print("Sabado");
      break;
  }
}
     
void Fin (void){
  if(OK){
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("01/01/0000");
    lcd.setCursor(0, 1);
    lcd.print("Decena dia");
    Funcion = &DecenaDia;
    DecDia = 0;
    UniDia = 1;
    DecMes = 0;
    UniMes = 1;
    MilYear = 0;
    CenYear = 0;
    DecYear = 0;
    UniYear = 0;
  }
}
