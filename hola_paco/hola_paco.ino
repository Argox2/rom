

// Rueda delantera derecha.
const int FR_ENA_ATRAS = 23;        
const int FR_ENA_ADELANTE = 22;
const int FR_PWM_ATRAS = 9;        
const int FR_PWM_ADELANTE = 10;

// Rueda delantera izquierda. 
const int FL_ENA_ATRAS = 35;        
const int FL_ENA_ADELANTE = 34;
const int FL_PWM_ATRAS = 3;        
const int FL_PWM_ADELANTE = 4;

// Rueda trasera derecha
const int BR_ENA_ATRAS = 26;        
const int BR_ENA_ADELANTE = 27;
const int BR_PWM_ATRAS = 6;        
const int BR_PWM_ADELANTE = 5;

// Rueda trasera izquierda 
const int BL_ENA_ATRAS = 30;        
const int BL_ENA_ADELANTE = 31;
const int BL_PWM_ATRAS = 8;        
const int BL_PWM_ADELANTE = 7;



// Es necesario poner los enables en cero cuando se frena?

// LLANTA DELANTERA DERECHA.
// Si velocidad cero, frena. 
// Si velocidad negativa gira hacia atras.

void frontRightWheel(int speed) {
    if (speed >= 0) {
      digitalWrite(FR_ENA_ATRAS, HIGH);
      digitalWrite(FR_ENA_ADELANTE, HIGH);
      analogWrite(FR_PWM_ATRAS, 0);
      analogWrite(FR_PWM_ADELANTE, speed);
    }
    else {
      digitalWrite(FR_ENA_ATRAS, HIGH);
      digitalWrite(FR_ENA_ADELANTE, HIGH);
      analogWrite(FR_PWM_ATRAS, speed);
      analogWrite(FR_PWM_ADELANTE, 0);
      }
  }


// LLANTA DELANTERA IZQUIERDA.
// Si velocidad cero, frena. 
// Si velocidad negativa gira hacia atras.

void frontLeftWheel(int speed) {
    if (speed >= 0) {
      digitalWrite(FL_ENA_ATRAS, HIGH);
      digitalWrite(FL_ENA_ADELANTE, HIGH);
      analogWrite(FL_PWM_ATRAS, speed);
      analogWrite(FL_PWM_ADELANTE, 0);
    }
    else {
      digitalWrite(FL_ENA_ATRAS, HIGH);
      digitalWrite(FL_ENA_ADELANTE, HIGH);
      analogWrite(FL_PWM_ATRAS, 0);
      analogWrite(FL_PWM_ADELANTE, speed);
      }
  }


// FALTA EDITAR LAS DOS LLANTAS TRASERAS.

// LLANTA DELANTERA DERECHA.
// Si velocidad cero, frena. 
// Si velocidad negativa gira hacia atras.

void backRightWheel(int speed) {
    if (speed >= 0) {
      digitalWrite(BR_ENA_ATRAS, HIGH);
      digitalWrite(BR_ENA_ADELANTE, HIGH);
      analogWrite(BR_PWM_ATRAS, 0);
      analogWrite(BR_PWM_ADELANTE, speed);
    }
    else {
      digitalWrite(BR_ENA_ATRAS, HIGH);
      digitalWrite(BR_ENA_ADELANTE, HIGH);
      analogWrite(BR_PWM_ATRAS, speed);
      analogWrite(BR_PWM_ADELANTE, 0);
      }
  }

// LLANTA DELANTERA DERECHA.
// Si velocidad cero, frena. 
// Si velocidad negativa gira hacia atras.

void backLeftWheel(int speed) {
    if (speed >= 0) {
      digitalWrite(BL_ENA_ATRAS, HIGH);
      digitalWrite(BL_ENA_ADELANTE, HIGH);
      analogWrite(BL_PWM_ATRAS, speed);
      analogWrite(BL_PWM_ADELANTE, 0);
    }
    else {
      digitalWrite(BL_ENA_ATRAS, HIGH);
      digitalWrite(BL_ENA_ADELANTE, HIGH);
      analogWrite(BL_PWM_ATRAS, 0);
      analogWrite(BL_PWM_ADELANTE, speed);
      }
  }

void goCar() {
    frontRightWheel(80);
    frontLeftWheel(80);
    backRightWheel(80);
    backLeftWheel(80);
}

void stopCar() {
    frontRightWheel(0);
    frontLeftWheel(0);
    backRightWheel(0);
    backLeftWheel(0);
}

void goCar() {
    frontRightWheel(-80);
    frontLeftWheel(-80);
    backRightWheel(-80);
    backLeftWheel(-80);
}

void initWheels() {
  pinMode(FR_ENA_ATRAS, OUTPUT);
  pinMode(FR_ENA_ADELANTE, OUTPUT);
  pinMode(FR_PWM_ATRAS, OUTPUT);
  pinMode(FR_PWM_ADELANTE, OUTPUT);

  pinMode(FL_ENA_ATRAS, OUTPUT);
  pinMode(FL_ENA_ADELANTE, OUTPUT);
  pinMode(FL_PWM_ATRAS, OUTPUT);
  pinMode(FL_PWM_ADELANTE, OUTPUT);

  pinMode(BR_ENA_ATRAS, OUTPUT);
  pinMode(BR_ENA_ADELANTE, OUTPUT);
  pinMode(BR_PWM_ATRAS, OUTPUT);
  pinMode(BR_PWM_ADELANTE, OUTPUT);

  pinMode(BL_ENA_ATRAS, OUTPUT);
  pinMode(BL_ENA_ADELANTE, OUTPUT);
  pinMode(BL_PWM_ATRAS, OUTPUT);
  pinMode(BL_PWM_ADELANTE, OUTPUT);
}

void setup() {
  initWheels();
  delay(1000);
  goCar();
  delay(1000);
  stopCar();
}

void loop() {
  // put your main code here, to run repeatedly:

}
