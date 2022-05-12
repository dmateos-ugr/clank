#include "motor.h"
#include "motores.h"

#define PIN_MOTOR_DER_VELOCIDAD 10 // PWM
#define PIN_MOTOR_IZQ_VELOCIDAD 9  // PWM
#define PIN_MOTOR_DER_SENTIDO1 7
#define PIN_MOTOR_DER_SENTIDO2 6
#define PIN_MOTOR_IZQ_SENTIDO1 5
#define PIN_MOTOR_IZQ_SENTIDO2 4

// Motor motor_izq(PIN_MOTOR_IZQ_VELOCIDAD, PIN_MOTOR_IZQ_SENTIDO1, PIN_MOTOR_IZQ_SENTIDO2);
// Motor motor_der(PIN_MOTOR_DER_VELOCIDAD, PIN_MOTOR_DER_SENTIDO1, PIN_MOTOR_DER_SENTIDO2);
Motores motores(PIN_MOTOR_IZQ_VELOCIDAD, PIN_MOTOR_IZQ_SENTIDO1, PIN_MOTOR_IZQ_SENTIDO2,
                PIN_MOTOR_DER_VELOCIDAD, PIN_MOTOR_DER_SENTIDO1, PIN_MOTOR_DER_SENTIDO2);


void setup()
{
	Serial.begin(9600);
	// motores.set_direccion(Motores::Forwards);
	// motor_izq.set_sentido(Motor::Backwards);
	// motor_izq.set_velocidad(255);
	// motor_der.set_sentido(Motor::Forwards);
	// motor_der.set_velocidad(255);
	motores.set_velocidad(50);
}

void loop()
{
	// Serial.println("hola mundo");
	motores.encender();
	motores.set_direccion(Motores::Forwards);
	delay(3000);
	motores.set_direccion(Motores::Backwards);
	delay(3000);
	motores.set_direccion(Motores::Right);
	delay(3000);
	motores.set_direccion(Motores::Left);
	delay(3000);
	motores.apagar();
	delay(3000);
}