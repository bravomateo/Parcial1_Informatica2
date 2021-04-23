
/* Dar nombre a los pines*/
                   // ARDUINO -> HC595 
const int SER = 2;  // pin 2  -> SER (PIN 14)
const int RCLK = 3; // pin 3  -> RCLK (PIN 12)
const int SRCLK = 4;// pin 4  -> SRCLK (PIN 11)


int *p_a; // crear puntero

// prototipo de funciones

void ledOn(int); 
// Funcion que enceinde una fila de Leds 
//segun la entrada (numero decimal) 

void prueba1();
// Funcion que permite ver el patron "5"

void imagen(int); // funcion que permite ver un patron en el arreglo de leds

void publik(int); // funcion que permite ver una secuencia de patrones 


void setup()
{
  
  Serial.begin(9600); // Establece los baudios para la transmisión de datos en serie.
  
  
  // Poner en modo salida los pines digitales
  pinMode(SER , OUTPUT);
  pinMode(RCLK , OUTPUT);
  pinMode(SRCLK , OUTPUT);
  
  
  // Inicilaizar salidas digitales en 0
  digitalWrite(SER , 0); 
  digitalWrite(RCLK , 0);
  digitalWrite(SRCLK , 0);
  
  // Imprimir el menu en el monitor en serie
  Serial.println("MENU DE INICIO");
  Serial.println("1. Dibujar el patron 5");
  Serial.println("2. Probar funcionamiento de todos los leds");
  Serial.println("3. Mostrar un patron escribiendo un caracter de su teclado");
  Serial.println("4. Mostrar una secuencia de patrones diferentes");
  Serial.println("Seleccione una opcion: ");
  Serial.println(" ");
  
  
  while(Serial.available()==0){} // Permite ingresar datos al usuario
    
  int ENTRADA = Serial.parseInt(); // lee un entero 
  Serial.print("Su elecciones fue: ");
  Serial.println(ENTRADA);
  
  /*
  Verificacion de entradas del usuario
  */
  
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
   
    Serial.println("");

    // pedir al usuario un caracter para ser
    // visualizado
    Serial.println("Ingrese un caracter para mostrar el patron: ");
    while(Serial.available()==0){}
  	int ENTRADA3 = Serial.read(); // lee ascii y le asigna el valor en ascci
	
    // A -> 65 o  1-> 49
	
    imagen(ENTRADA3); 
    
  }
  
  if(ENTRADA == 4){
	  
    // Solicita al usuario que le ingrese una palabra
	// el tiempo entre patron y patron 
	
	Serial.println("");
    Serial.print("Ingrese el tiempo de duracion en segundos: ");
    while(Serial.available()==0){}
	
	
    int SEGU = Serial.parseInt(); // SEGU = tiempo en segundos 
  
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
    
    El parametro de entrada (n) es un entero que se convierte   -> 1
    a binario para generar datos a la entrada SER
    
    -> Si n = 158 (Un ejemplo particular)
       el binario es 10011110 
	   Qa = 1  Qb = 0  Qc = 0  Qd = 1  Qe = 1   Qf = 1  Qg = 1   Qh = 0
    */
  
    int b;
	
  	for (int i = 0 ; i < 8 ; i++){
    b = n%2; // residuo para extraer bits
    n = n/2;
    
     //[paso 1]
    digitalWrite(SER ,b); // envia la informacion del bit menos // 0 1 1 1 1 0 0 1 -> 
          //	00000000 - 10000000 - 11000000 -11100000 -11110000- 01111000 - 00111100 - 10011110 ->  10011110
                         //significativo al mas significativo

    // [Paso 2] 
    digitalWrite(SRCLK , 0);
    digitalWrite(SRCLK , 1); // Se flaque la entrada SRCLK = 4
    digitalWrite(SRCLK , 0);

    // [Paso 3]
    digitalWrite(RCLK , 0);
    digitalWrite(RCLK , 1);  // Se flanquea la entrada RCLK = 3
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
	los LEDS funcionen, enciende todos los leds*/

    p_a = new int[8]; //reservar memoria para un arreglo de 8 posiciones 
    
	/* Asiganacion a cada posicion del arreglo 
	un numero decimal */
	
    p_a[0] = 255; p_a[1] = 255; p_a[2] = 255; // 255 -> 11111111 -> 
    p_a[3] = 255; p_a[4] = 255; p_a[5] = 255;
    p_a[6] = 255; p_a[7] = 255;
    

    for (int i=0; i<8; i++){
      		ledOn(*(p_a+i));
        }
    
    delete[] p_a;

}


void imagen(int n){


	// n representa en ascci un carcter ingresado
	
	
	if (n == 65 || n == 97) {  // LETRA A o a
		
		p_a = new int[8];
		p_a[0] = 195; p_a[1] = 195; p_a[2] = 195;
		p_a[3] = 255; p_a[4] = 255; p_a[5] = 195;
		p_a[6] = 66; p_a[7] = 60;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
	else if (n == 66 || n == 98) {  // LETRA B o n
		
		p_a = new int[8];
		p_a[0] = 124; p_a[1] = 66; p_a[2] = 66;
		p_a[3] = 124; p_a[4] = 124; p_a[5] = 66;
		p_a[6] = 66; p_a[7] = 124;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
	else if (n == 67 || n == 99) {
		
		p_a = new int[8];
		p_a[0] = 126; p_a[1] = 254; p_a[2] = 224;
		p_a[3] = 224; p_a[4] = 224; p_a[5] = 224;
		p_a[6] = 254; p_a[7] = 126;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}

	else if (n == 68 || n == 100) {
		
		p_a = new int[8];
		p_a[0] = 252; p_a[1] = 254; p_a[2] = 99;
		p_a[3] = 99; p_a[4] = 99; p_a[5] = 99;
		p_a[6] = 254; p_a[7] = 252;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}

	else if (n == 69 || n == 101) {
		
		p_a = new int[8];
		p_a[0] = 255; p_a[1] = 255; p_a[2] = 192;
		p_a[3] = 252; p_a[4] = 252; p_a[5] = 192;
		p_a[6] = 255; p_a[7] = 255;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}	
	
	else if (n == 70 || n == 102) {
		
		p_a = new int[8];
		p_a[0] = 192; p_a[1] = 192; p_a[2] = 192;
		p_a[3] = 252; p_a[4] = 252; p_a[5] = 192;
		p_a[6] = 255; p_a[7] = 255;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
	else if (n == 71 || n == 103) {
		
		p_a = new int[8];
		p_a[0] = 124; p_a[1] = 126; p_a[2] = 194;
		p_a[3] = 206; p_a[4] = 206; p_a[5] = 192;
		p_a[6] = 126; p_a[7] = 124;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}

	else if (n == 72 || n == 104) {
		
		p_a = new int[8];
		p_a[0] = 195; p_a[1] = 195; p_a[2] = 195;
		p_a[3] = 255; p_a[4] = 255; p_a[5] = 195;
		p_a[6] = 195; p_a[7] = 195;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
	else if (n == 73 || n == 105) {
		
		p_a = new int[8];
		p_a[0] = 255; p_a[1] = 255; p_a[2] = 24;
		p_a[3] = 24; p_a[4] = 24; p_a[5] = 24;
		p_a[6] = 255; p_a[7] = 255;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}

	else if (n == 74 || n == 106) {
		
		p_a = new int[8];
		p_a[0] = 112; p_a[1] = 248; p_a[2] = 24;
		p_a[3] = 24; p_a[4] = 24; p_a[5] = 24;
		p_a[6] = 255; p_a[7] = 255;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
	else if (n == 75 || n == 107) {
		
		p_a = new int[8];
		p_a[0] = 198; p_a[1] = 204; p_a[2] = 216;
		p_a[3] = 240; p_a[4] = 240; p_a[5] = 216;
		p_a[6] = 204; p_a[7] = 198;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
	else if (n == 76 || n == 108) {
		
		p_a = new int[8];
		p_a[0] = 254; p_a[1] = 254; p_a[2] = 192;
		p_a[3] = 192; p_a[4] = 192; p_a[5] = 192;
		p_a[6] = 192; p_a[7] = 192;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
	else if (n == 77 || n == 109) {
		
		p_a = new int[8];
		p_a[0] = 195; p_a[1] = 195; p_a[2] = 195;
		p_a[3] = 219; p_a[4] = 255; p_a[5] = 231;
		p_a[6] = 195; p_a[7] = 195;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
	else if (n == 78 || n == 110) {
		
		p_a = new int[8];
		p_a[0] = 195; p_a[1] = 199; p_a[2] = 207;
		p_a[3] = 223; p_a[4] = 251; p_a[5] = 243;
		p_a[6] = 227; p_a[7] = 195;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
	else if (n == 79 || n == 111) {
		
		p_a = new int[8];
		p_a[0] = 60; p_a[1] = 126; p_a[2] = 195;
		p_a[3] = 195; p_a[4] = 195; p_a[5] = 195;
		p_a[6] = 126; p_a[7] = 60;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
  else if (n == 80 || n == 112) {
		//Letra P o p
		p_a = new int[8];
		p_a[0] = 192; p_a[1] = 192; p_a[2] = 254;
		p_a[3] = 255; p_a[4] = 193; p_a[5] = 193;
		p_a[6] = 255; p_a[7] = 254;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
		else if (n == 81 || n == 113) {
		p_a = new int[8];
		p_a[0] = 1; p_a[1] = 126; p_a[2] = 70;
		p_a[3] = 74; p_a[4] = 66; p_a[5] = 66;
		p_a[6] = 126; p_a[7] = 0;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
		else if (n == 82 || n == 114) {

		p_a = new int[8];
		p_a[0] = 204; p_a[1] = 216; p_a[2] = 240;
		p_a[3] = 252; p_a[4] = 198; p_a[5] = 198;
		p_a[6] = 254; p_a[7] = 252;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
		else if (n == 83 || n == 115) {

		p_a = new int[8];
		p_a[0] = 60; p_a[1] = 126; p_a[2] = 6;
		p_a[3] = 62; p_a[4] = 124; p_a[5] = 96;
		p_a[6] = 126; p_a[7] = 60;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
		else if (n == 84 || n == 116) {

		p_a = new int[8];
		p_a[0] = 24; p_a[1] = 24; p_a[2] = 24;
		p_a[3] = 24; p_a[4] = 24; p_a[5] = 24;
		p_a[6] = 255; p_a[7] = 255;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	  	
		else if (n == 85 || n == 117) {
	
		p_a = new int[8];
		p_a[0] = 255 ; p_a[1] = 255; p_a[2] = 195;
		p_a[3] = 195; p_a[4] = 195; p_a[5] =195;
		p_a[6] = 195; p_a[7] =195;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
		else if (n == 86 || n == 118) {

		p_a = new int[8];
		p_a[0] = 24; p_a[1] = 60; p_a[2] = 102;
		p_a[3] = 195; p_a[4] = 195; p_a[5] =195;
		p_a[6] = 195; p_a[7] =195;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
		else if (n == 87 || n == 119) {
	
		p_a = new int[8];
		p_a[0] = 60; p_a[1] = 126; p_a[2] = 219;
		p_a[3] = 219; p_a[4] = 219; p_a[5] = 195;
		p_a[6] = 195; p_a[7] = 195;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
		else if (n == 88 || n == 120) {

		p_a = new int[8];
		p_a[0] = 195; p_a[1] = 102; p_a[2] = 60;
		p_a[3] = 24; p_a[4] = 60; p_a[5] = 102;
		p_a[6] = 195; p_a[7] = 129;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
		
	}
  
  		else if (n == 89 || n == 121) {
		p_a = new int[8];
		p_a[0] = 24; p_a[1] = 24; p_a[2] = 24;
		p_a[3] = 24; p_a[4] = 60; p_a[5] = 102;
		p_a[6] = 195; p_a[7] = 195;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
		
	}
  
  
		else if (n == 90 || n == 122) {
		//letra z Z

		p_a = new int[8];
		p_a[0] = 255; p_a[1] = 127; p_a[2] = 48;
		p_a[3] = 24; p_a[4] = 12; p_a[5] = 6;
		p_a[6] = 255; p_a[7] = 255;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;
	}	
  
  
  
	// numeros 
	
	else if (n == 48) {
		// numero 1
		p_a = new int[8];
		p_a[0] = 126; p_a[1] = 66; p_a[2] = 66;
		p_a[3] = 66; p_a[4] = 66; p_a[5] = 66;
		p_a[6] = 66; p_a[7] = 126;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}

	else if (n == 49) {
		
		p_a = new int[8];
		p_a[0] = 255; p_a[1] = 255; p_a[2] = 12;
		p_a[3] = 12; p_a[4] = 12; p_a[5] = 108;
		p_a[6] = 60; p_a[7] = 28;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
	else if (n == 50 ) {
		
		p_a = new int[8];
		p_a[0] = 126; p_a[1] = 126; p_a[2] = 48;
		p_a[3] = 24; p_a[4] = 12; p_a[5] = 38;
		p_a[6] = 62; p_a[7] = 28;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
	else if (n == 51 ) {
		
		p_a = new int[8];
		p_a[0] = 124; p_a[1] = 124; p_a[2] = 2;
		p_a[3] = 28; p_a[4] = 28; p_a[5] = 2;
		p_a[6] = 124; p_a[7] = 124;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	
	else if (n == 52 ) {
		
		p_a = new int[8];
		p_a[0] = 6; p_a[1] = 6; p_a[2] = 255;
		p_a[3] = 198; p_a[4] = 102; p_a[5] = 54;
		p_a[6] = 30; p_a[7] = 14;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
	else if (n == 53 ) {
		
		p_a = new int[8];
		p_a[0] = 124; p_a[1] = 2; p_a[2] = 2;
		p_a[3] = 2; p_a[4] = 124; p_a[5] = 64;
		p_a[6] = 64; p_a[7] = 126;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
  
	else if (n == 54 ) {
		
		p_a = new int[8];
		p_a[0] = 60; p_a[1] = 102; p_a[2] = 102;
		p_a[3] = 102; p_a[4] =124; p_a[5] = 96;
		p_a[6] = 98; p_a[7] = 60;
		
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
  	else if (n == 55 ) {
		
		p_a = new int[8];
		p_a[0] = 4; p_a[1] = 4; p_a[2] = 4;
		p_a[3] = 63; p_a[4] = 4; p_a[5] = 4;
		p_a[6] = 4; p_a[7] = 124;
      
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
    else if (n == 56 ) {
		
		p_a = new int[8];
		p_a[0] = 60; p_a[1] = 66; p_a[2] = 66;
		p_a[3] = 60; p_a[4] = 60; p_a[5] = 66;
		p_a[6] = 66; p_a[7] = 60;
      
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
  
    else if (n == 57 ) {
		// numero 9
		p_a = new int[8];
		p_a[0] = 126; p_a[1] = 2; p_a[2] = 2;
		p_a[3] = 126; p_a[4] = 66; p_a[5] = 66;
		p_a[6] = 66; p_a[7] = 126;
		
      
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
    else {
		// muestra un signo de interrrogacion
		p_a = new int[8];
		p_a[0] = 24; p_a[1] = 0; p_a[2] = 24;
		p_a[3] = 12; p_a[4] = 6; p_a[5] = 102;
		p_a[6] = 126; p_a[7] = 60;
		
      
		for (int i=0; i<8; i++){
			ledOn(*(p_a+i));
        }
		
		delete[] p_a;	
	}
  
}





void publik(int SEG){
	
	/*
	Recibe como parametros de entras un entero que represeta el tiempo
	*/

    int TIEMPO = SEG*1000;  // 1 seg o 
    
	Serial.println("Ingrese la cadena: ");
  	while(Serial.available()==0){}
  
  	int len = 20; // a cadema a lo sumo tiene 20 carac. 
  	char buffer[len] = {0}; // creamos un arreglo vacio
  
  	int a = Serial.readBytes(buffer,len); // ->> HOLA a = 4 HOLA
  	Serial.print("Su cadena es = ");
  	Serial.println(buffer);
 
    
  	for(int i=0; i< a; i++){
      imagen(*(buffer+i)); // con buffer[i] se extrea caracter a caracter en ascci HOLA -> H -> 72  O -> 79
      delay(TIEMPO);
    }
}




