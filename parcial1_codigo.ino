const int SER = 2;
const int RCLK = 3;
const int SRCLK = 4;

void ledOn(int); 
// Enciende los leds de una fila segun la entrada
// de un numero decimal

void prueba1();


void imagen(int);

void publik(int);


void setup()
{
  
  
  Serial.begin(9600);
  
  // Poner en modo salida los pines digitales
  
  pinMode(SER , OUTPUT);
  pinMode(RCLK , OUTPUT);
  pinMode(SRCLK , OUTPUT);
  
   // Inicilaizar salidas digitales en 0
 
  digitalWrite(SER , 0); 
  digitalWrite(RCLK , 0);
  digitalWrite(SRCLK , 0);
  
  // Imprimir el menu en el monitor
  
  Serial.println("MENU DE INICIO");
  Serial.println("1. Dibujar el patron 5");
  Serial.println("2. Encender todos los leds");
  Serial.println("3. Mostrar un patron a su eleccion");
  Serial.println("4. Mostrar una cadena de patrones a su eleccion");
  Serial.println("Seleccione una opcion: ");
  
  
  while(Serial.available()==0){}
    
  int ENTRADA = Serial.parseInt(); // lee un entero 
  Serial.print("Su elecciones fue: ");
  Serial.println(ENTRADA);
  
  
  
  if (ENTRADA == 1){
    // Ingresa a verificar el patron 5 
    prueba1();
  }
  
  else if(ENTRADA == 2){
    // Ingresa a realizar la verifiacion
    // que todos los LEDS esten encnendidos
    
    verificacion();
  }
  
  else if(ENTRADA == 3){
    
    

    // pedir al usuario un caracter para ser
    // visualizado
    
    Serial.println("Ingrese un caracter para mostrar el patron: ");
    while(Serial.available()==0){}
    
  	int ENTRADA3 = Serial.read(); // lee ascii 
  	Serial.println("Su caracter ingresado fue: ");
  	Serial.println(ENTRADA3);
    
    imagen(ENTRADA3-64); // A - > 65  caso 1 = A 65-64 -> 1 

    
  }
  
  if(ENTRADA == 4){
    // Pide al usuario que le ingrese una palabra para ser
    // mostrada secuencialmente, el tiempo entre patron y 
    // patron lo define el usuario y la variable se llama
    // TIEMPO

    Serial.print("Ingrese el tiempo de duracion en segundos: ");
    while(Serial.available()==0){}
    int SEGU = Serial.parseInt(); 
  
	publik(SEGU);
    
  }
}

  
void loop(){

}


// Funciones de nuestro programa

void ledOn(int n){
  
  	/*
    
    Funcion que enciende una fila del arreglo de LEDS
    segun n
    
    El parametro de entrada (n) es un entero que se convierte
    a binario para generar datos a la entrada SER
    
    -> Si n = 221  (Un ejemplo particular)
       el binario es 11011101 donde 1 es enecendido y 0 apagado
    
    
    */
  
    int b;
  	for (int i = 0 ; i < 8 ; i++){
    b = n%2;
    n = n/2;
    
     //[paso 1]
    digitalWrite(SER ,b); // envia la informacion del bit menos
                         //significativo al mas significativo

    // [Paso 2] 
    digitalWrite(SRCLK , 0);
    digitalWrite(SRCLK , 1);
    digitalWrite(SRCLK , 0);

    // [Paso 3]
    digitalWrite(RCLK , 0);
    digitalWrite(RCLK , 1);
    digitalWrite(RCLK , 0);
  }
}


void prueba1(){
  
    /* Funcion que muestra el numero 5 en un patron de LEDS*/
  
  int p1[8] = {126,255,199,7,254,224,255,255};
  
  for (int k = 0; k < 8; k++){
    ledOn(*(p1+k));
  }
}


void verificacion(){ 
  
  /* Funcion que verifica que todos
  los LEDS esten encendidos*/
  
  int p2[8] = {255,255,255,255,255,255,255,255};
  
  for (int k = 0; k < 8; k++){
    ledOn(*(p2+k));
  }
}

void imagen(int n){
  
  	/*Funcion que recibe como parametro un entero,
      que representa un caracter y muestra en la 
      matriz de leds su correspondiente patron
     */
     
  	/* A cada letra del abecedario se le asigna una
    matriz que en decimal representa un conjunto de arreglos
    para que dicha letra se vea como un patron en la
    matriz de LEDS
    */
  
    int vacio[8] = {255,255,0,0,0,0,255,255};      
    int A[8] = {195,195,195,255,255,195,66,60};
    int B[8] = {124,66,66,124,124,66,66,124};
    int C[8] = {126,254,224,224,224,224,254,126};
    int D[8] = {252,254,99,99,99,99,254,252};
    int E[8] = {255,255,192,252,252,192,255,255};
    int F[8] = {192,192,192,252,252,192,255,255};
    int G[8] = {124,126,194,206,206,192,126,124};
    int H[8] = {195,195,195,255,255,195,195,195};
    int I[8] = {255,255,24,24,24,24,255,255};
    int J[8] = {112,248,24,24,24,24,255,255};
    int K[8] = {198,204,216,240,240,216,204,198};
    int L[8] = {254,254,192,192,192,192,192,192};
  	int M[8] = {195,195,195,219,255,231,195,195};
  	int N[8] = {195,199,207,223,251,243,227,195};
  	int O[8] = {60,126,195,195,195,195,126,60};
  	int P[8] = {192,192,254,255,193,193,255,254};
    int Q[8] = {1,126,70,74,66,66,126,0};
  	int R[8] = {204,216,240,252,198,198,254,252};
  	int S[8] = {60,126,6,62,124,96,126,60};
  	int T[8] = {24,24,24,24,24,24,255,255};
  	int U[8] = {255,255,195,195,195,195,195,195};
  	int V[8] = {24,60,102,195,195,195,195,195};
  	int W[8] = {60,126,219,219,219,195,195,195};
    int X[8] = {195,102,60,24,60,102,195,129};
  	int Y[8] = {24,24,24,24,60,102,195,195};
    int Z[8] = {255,127,48,24,12,6,255,255};

    switch (n) {

    case 1:
        for (int k = 0; k < 8; k++){
          ledOn(*(A+k));
        }
        break;
      
      
    case 2:
        for (int k = 0; k < 8; k++){
          ledOn(*(B+k));
        }
        break;
    case 3:
        for (int k = 0; k < 8; k++){
          ledOn(*(C+k));
        }
        break;
    case 4:
        for (int k = 0; k < 8; k++){
          ledOn(*(D+k));
        }
        break;
      
    case 5:
        for (int k = 0; k < 8; k++){
          ledOn(*(E+k));
        }
        break; 
      
    case 6:
        for (int k = 0; k < 8; k++){
          ledOn(*(F+k));
        }
        break;
    case 7:
        for (int k = 0; k < 8; k++){
          ledOn(*(G+k));
        }
        break;
    case 8:
        for (int k = 0; k < 8; k++){
          ledOn(*(H+k));
        }
        break;
    case 9:
        for (int k = 0; k < 8; k++){
          ledOn(*(I+k));
        }
        break;
    case 10:
        for (int k = 0; k < 8; k++){
          ledOn(*(J+k));
        }
        break;
    case 11:
        for (int k = 0; k < 8; k++){
          ledOn(*(K+k));
        }
        break;
    case 12:
        for (int k = 0; k < 8; k++){
          ledOn(*(L+k));
        }
        break;
    case 13:
        for (int k = 0; k < 8; k++){
          ledOn(*(M+k));
        }
        break;
    case 14:
        for (int k = 0; k < 8; k++){
          ledOn(*(N+k));
        }
        break;   
    case 15:
        for (int k = 0; k < 8; k++){
          ledOn(*(O+k));
        }
        break;    
    case 16:
        for (int k = 0; k < 8; k++){
          ledOn(*(P+k));
        }
        break;
    case 17:
        for (int k = 0; k < 8; k++){
          ledOn(*(Q+k));
        }
        break;
    case 18:
        for (int k = 0; k < 8; k++){
          ledOn(*(R+k));
        }
        break;
    case 19:
        for (int k = 0; k < 8; k++){
          ledOn(*(S+k));
        }
        break;   
    case 20:
        for (int k = 0; k < 8; k++){
          ledOn(*(T+k));
        }
        break;    
    case 21:
        for (int k = 0; k < 8; k++){
          ledOn(*(U+k));
        }
        break;
    case 22:
        for (int k = 0; k < 8; k++){
          ledOn(*(V+k));
        }
        break;
    case 23:
        for (int k = 0; k < 8; k++){
          ledOn(*(W+k));
        }
        break;
    case 24:
        for (int k = 0; k < 8; k++){
          ledOn(*(X+k));
        }
        break;
    case 25:
        for (int k = 0; k < 8; k++){
          ledOn(*(Y+k));
        }
        break;
    case 26:
        for (int k = 0; k < 8; k++){
          ledOn(*(Z+k));
        }
        break;
      
    default :
        for (int k = 0; k < 8; k++){
          ledOn(*(vacio+k));
        }
        break;
    }
      

}


void publik(int SEG){

    int TIEMPO = SEG*1000; 
    
	Serial.println("Ingrese la cadena: ");
  	while(Serial.available()==0){}
  
  	int len = 20;
  	char buffer[len] = {0};
  
  	int a = Serial.readBytes(buffer,len); // ->> HOLA a = 4
  	Serial.print("Su cadena es = ");
  	Serial.println(buffer);
 
    
  	for(int i=0; i< a; i++){
      imagen(buffer[i]-64);
      delay(TIEMPO);
    }
}



