const int FR_ENA_ATRAS = 23;        // Rueda delantera derecha
const int FR_ENA_ADELANTE = 22;
const int FR_PWM_ATRAS = 9;        
const int FR_PWM_ADELANTE = 10;

const int FL_ENA_ATRAS = 35;        // Rueda delantera derecha
const int FL_ENA_ADELANTE = 34;
const int FL_PWM_ATRAS = 3;        
const int FL_PWM_ADELANTE = 4;

const int BR_ENA_ATRAS = 26;        // Rueda trasera derecha
const int BR_ENA_ADELANTE = 27;
const int BR_PWM_ATRAS = 6;        
const int BR_PWM_ADELANTE = 5;

const int BL_ENA_ATRAS = 30;        // Rueda trasera derecha
const int BL_ENA_ADELANTE = 31;
const int BL_PWM_ATRAS = 8;        
const int BL_PWM_ADELANTE = 7;




void initFR() {
  pinMode(FR_ENA_ATRAS, OUTPUT);
  pinMode(FR_ENA_ADELANTE, OUTPUT);
  pinMode(FR_PWM_ATRAS, OUTPUT);
  pinMode(FR_PWM_ADELANTE, OUTPUT);
}

void initFL() {
  pinMode(FL_ENA_ATRAS, OUTPUT);
  pinMode(FL_ENA_ADELANTE, OUTPUT);
  pinMode(FL_PWM_ATRAS, OUTPUT);
  pinMode(FL_PWM_ADELANTE, OUTPUT);
}

void avanzaFR() {
  digitalWrite(FR_ENA_ATRAS, HIGH);
  digitalWrite(FR_ENA_ADELANTE, HIGH);
  analogWrite(FR_PWM_ATRAS, 0);
  analogWrite(FR_PWM_ADELANTE, 100);
}

void avanzaFL() {
  digitalWrite(FL_ENA_ATRAS, HIGH);
  digitalWrite(FL_ENA_ADELANTE, HIGH);
  analogWrite(FL_PWM_ATRAS, 100);
  analogWrite(FL_PWM_ADELANTE, 0);
}


void frenaFR() {
  analogWrite(FR_PWM_ATRAS, 0);
  analogWrite(FR_PWM_ADELANTE, 0);
  analogWrite(FR_PWM_ATRAS, 0);
  analogWrite(FR_PWM_ADELANTE, 0);
}

void frenaFL() {
  analogWrite(FL_PWM_ATRAS, 0);
  analogWrite(FL_PWM_ADELANTE, 0);
  analogWrite(FL_PWM_ATRAS, 0);
  analogWrite(FL_PWM_ADELANTE, 0);
}

void setup() {
  // put your setup code here, to run once:
  initFR();
  initFL();
  delay(1000);
  avanzaFR();
  avanzaFL();
  delay(1000);
  frenaFR();
  frenaFL();
}

void loop() {
  // put your main code here, to run repeatedly:

}
