//
// Cableado de TCS3200 a Arduino
//
#define S0 8
#define S1 9
#define S2 12
#define S3 11
#define salidaSensor 10
 
// Para guardar las frecuencias de los fotodiodos
int frecuenciaRojo = 0;
int frecuenciaVerde = 0;
int frecuenciaAzul = 0;
 
void setup() {
  // Definiendo las Salidas
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // Definiendo salidaSensor como entrada
  pinMode(salidaSensor, INPUT);
  
  // Definiendo la escala de frecuencia a 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
   // Iniciar la comunicacion serie 
  Serial.begin(9600);
}
void loop() {
  // Definiendo la lectura de los fotodiodos con filtro rojo
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  // Leyendo la frecuencia de salida del sensor
  frecuenciaRojo = pulseIn(salidaSensor, LOW);
  
  // Mostrando por serie el valor para el rojo (R = Red)
  Serial.print("R = ");
  Serial.print(frecuenciaRojo);
  delay(100);
  
  // Definiendo la lectura de los fotodiodos con filtro verde
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Leyendo la frecuencia de salida del sensor
  frecuenciaVerde = pulseIn(salidaSensor, LOW);
  
  // Mostrando por serie el valor para el verde (G = Green)
  Serial.print(" G = ");
  Serial.print(frecuenciaVerde);
  delay(100);
 
  // Definiendo la lectura de los fotodiodos con filtro azul
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Leyendo la frecuencia de salida del sensor
  frecuenciaAzul = pulseIn(salidaSensor, LOW);
  
  // Mostrando por serie el valor para el azul (B = Blue)
  Serial.print(" B = ");
  Serial.println(frecuenciaAzul);
  delay(100);
}


//
// Cableado de TCS3200 a Arduino
//
#define S0 8
#define S1 9
#define S2 12
#define S3 11
#define salidaSensor 10
 
// Para guardar las frecuencias de los fotodiodos
int frecuenciaRojo = 0;
int frecuenciaVerde = 0;
int frecuenciaAzul = 0;
int colorRojo;
int colorVerde;
int colorAzul;
 
void setup() {
  // Definiendo las Salidas
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // Definiendo salidaSensor como entrada
  pinMode(salidaSensor, INPUT);
  
  // Definiendo la escala de frecuencia a 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
   // Iniciar la comunicacion serie 
  Serial.begin(9600);
}
 
void loop() {
  // Definiendo la lectura de los fotodiodos con filtro rojo
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  // Leyendo la frecuencia de salida del sensor
  frecuenciaRojo = pulseIn(salidaSensor, LOW);
 
  // Mapeando el valor de la frecuencia del ROJO (RED = R) de 0 a 255
  // Usted debe colocar los valores que registro. Este es un ejemplo: 
  // colorRojo = map(frecuenciaRojo, 70, 120, 255,0);
  colorRojo = map(frecuenciaRojo, xx, xx, 255,0);
  
  // Mostrando por serie el valor para el rojo (R = Red)
  Serial.print("R = ");
  Serial.print(colorRojo);
  delay(100);
  
  // Definiendo la lectura de los fotodiodos con filtro verde
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Leyendo la frecuencia de salida del sensor
  frecuenciaVerde = pulseIn(salidaSensor, LOW);
 
  // Mapeando el valor de la frecuencia del VERDE (GREEN = G) de 0 a 255
  // Usted debe colocar los valores que registro. Este es un ejemplo: 
  // colorVerde = map(frecuenciaVerde, 100, 199, 255,0);
  colorVerde = map(frecuenciaVerde, xx, xx, 255,0);
 
  // Mostrando por serie el valor para el verde (G = Green)
  Serial.print("G = ");
  Serial.print(colorVerde);
  delay(100);
 
  // Definiendo la lectura de los fotodiodos con filtro azul
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Leyendo la frecuencia de salida del sensor
  frecuenciaAzul = pulseIn(salidaSensor, LOW);
 
  // Mapeando el valor de la frecuencia del AZUL (AZUL = B) de 0 a 255
  // Usted debe colocar los valores que registro. Este es un ejemplo: 
  // colorAzul = map(frecuenciaAzul, 38, 84, 255, 0);
  colorAzul = map(frecuenciaAzul, xx, xx, 255, 0);
  
  // Mostrando por serie el valor para el azul (B = Blue)
  Serial.print("B = ");
  Serial.print(colorAzul);
  delay(100);
 
  // Comprobar cual es el color detectado y mostrarlo
  // con un mensaje en el monitor serie
  if(colorRojo > colorVerde && colorRojo > colorAzul){
      Serial.println(" - Detectado ROJO");
  }
  if(colorVerde > colorRojo && colorVerde > colorAzul){
    Serial.println(" - Detectado VERDE");
  }
  if(colorAzul > colorRojo && colorAzul > colorVerde){
    Serial.println(" - Detectado AZUL");
  }
}


import random



def generarTablero(filas,columnas):
    tablero=[]
    for i in range(filas):
        tablero.append([])
        for j in range(columnas):
            tablero[i].append("#")
    return tablero

def generarMinas (filas,columnas,minas):
    tableroInvisible= generarTablero(filas,columnas)
    indice=0
    while indice <minas:
        horizontal=random.randint(0,filas-1)
        vertical=random.randint(0,columnas-1)
        if tableroInvisible[horizontal][vertical]!=":(":
            tableroInvisible[horizontal][vertical]=":("
            indice+=1
            
    for i in range(filas):
        for j in range(columnas):
            if tableroInvisible[i][j]!=":(":
                relacion=0
                if i<columnas-1:
                    if tableroInvisible[i+1][j]==":(":
                        relacion=relacion+1
                if i>0:
                    if tableroInvisible[i-1][j]==":(":
                        relacion=relacion+1
                if j<filas-1:
                    if tableroInvisible[i][j+1]==":(":
                        relacion=relacion+1
                if j>0:
                    if tableroInvisible[i][j-1]==":(":
                        relacion=relacion+1
                if i<columnas-1 and j<filas-1:
                    if tableroInvisible[i+1][j+1]==":(":
                        relacion=relacion+1
                if i<columnas-1 and j>0:
                    if tableroInvisible[i+1][j-1]==":(":
                        relacion=relacion+1
                if i>0 and j<filas-1:
                    if tableroInvisible[i-1][j+1]==":(":
                        relacion=relacion+1
                if i>0 and j>0:
                    if tableroInvisible[i-1][j-1]==":(":
                        relacion=relacion+1
                tableroInvisible[i][j]=relacion
    return tableroInvisible

def presentacion(tableroPresentacion,vidas,puntaje):
    i=0
    for i in range(len(tableroPresentacion[i])):
        print(tableroPresentacion[i],end="\n")
        print(end="\n")
    if vidas>0:
        print("-->",end="\t")
        print("BIEN JUGADO, TIENES",vidas,"VIDAS", end="\t")
        print("<--")  
        print(" °°°° TU PUNTAJE ES:",puntaje)
        


    
def jugabilidad(tableroInvisible,vidas,movimientos,muerte,puntaje):
    cantidadCasillas=(filas*columnas)-minas
    contador=0
    jugando=True
    while jugando==True:
        coordenadaHorizontal=int(input("Ingrese en que fila desea descubir:"))
        coordenadaVertical=int(input("Ingrese la columna que desea descubrir:"))
        if tableroInvisible[coordenadaHorizontal][coordenadaVertical]==":(":
            vidas=vidas-1
            tableroPresentacion[coordenadaHorizontal][coordenadaVertical]=":("
            muerte="True"
            if muerte=="True":
                puntaje=puntaje+0
        elif tableroInvisible[coordenadaHorizontal][coordenadaVertical]!=":(":
            tableroPresentacion[coordenadaHorizontal][coordenadaVertical]=tableroInvisible[coordenadaHorizontal][coordenadaVertical]
            muerte="False"
            movimientos=movimientos+1
            contador=contador+1
            if movimientos==1 and muerte=="False":
                puntaje=10
            elif movimientos!=1 and movimientos!=0 and muerte=="False":
                puntaje=puntaje+(puntaje*1.3)
        if cantidadCasillas==contador:
            print(end="\n")
            print(end="\t")
            print("HAS GANADO, FELICIDADES", end="\t")
            print(end="\n")
            print(end="\n")
            print("Asi queda el campo minado:")
            jugando=False
        
        presentacion(tableroPresentacion,vidas,puntaje)
        
        if vidas==0:
            jugando=False
            print(end="\n")
            print(end="\t")
            print("HAS PERDIDO TODAS TUS VIDAS", end="\n")
            print(end="\n")
            print("GAME OVER")
            print("Asi quedo tu campo minado:")
            presentacion(tableroPresentacion,vidas,puntaje)
            print("Tu puntaje fue de:",puntaje)
            


    
nombre=input("Ingrese su nombre:")
print("Seleccione dificultad:")
print("1. Bajo")
print("2. Medio")
print("3. Alto")
print("0. Salir")
vidas=5
movimientos=0
puntaje=0
dificultad=(int(input("Escriba el numero deseado para la dificultad, 0 para salir:")))

if dificultad==1:
    muerte="False"
    filas=5
    columnas=5
    minas=6
    tableroPresentacion=generarTablero(filas,columnas)
    tableroInvisible=generarMinas(filas,columnas,minas)
    presentacion(tableroPresentacion,vidas,puntaje)
    jugabilidad(tableroInvisible,vidas,movimientos,muerte,puntaje)
    
elif dificultad==2:
    muerte="False"
    filas=7
    columnas=7
    minas=10
    tableroPresentacion=generarTablero(filas,columnas)
    tableroInvisible=generarMinas(filas,columnas,minas)
    presentacion(tableroPresentacion,vidas,puntaje)
    jugabilidad(tableroInvisible,vidas,movimientos,muerte,puntaje)
    
elif dificultad==3:
    muerte="False"
    filas=9
    columnas=9
    minas=14
    tableroPresentacion=generarTablero(filas,columnas)
    tableroInvisible=generarMinas(filas,columnas,minas)
    presentacion(tableroPresentacion,vidas,puntaje)
    jugabilidad(tableroInvisible,vidas,movimientos,muerte,puntaje)
    
elif dificultad==0:
    print("Juego Terminado")
else:
    print("Seleccione una dificultad valida")
    







