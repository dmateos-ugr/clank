#include "motor.h"
#include "motores.h"
#include "sensor_linea.h"
#include "sensor_distancia.h"

#define PIN_MOTOR_DER_VELOCIDAD 10 // PWM
#define PIN_MOTOR_IZQ_VELOCIDAD 9  // PWM
#define PIN_MOTOR_DER_SENTIDO1 7
#define PIN_MOTOR_DER_SENTIDO2 6
#define PIN_MOTOR_IZQ_SENTIDO1 5
#define PIN_MOTOR_IZQ_SENTIDO2 4
#define PIN_SENSOR_LINEA1 A0
// #define PIN_SENSOR_LINEA2 A0
#define PIN_SENSOR_DISTANCIA 3

// Motor motor_izq(PIN_MOTOR_IZQ_VELOCIDAD, PIN_MOTOR_IZQ_SENTIDO1, PIN_MOTOR_IZQ_SENTIDO2);
// Motor motor_der(PIN_MOTOR_DER_VELOCIDAD, PIN_MOTOR_DER_SENTIDO1, PIN_MOTOR_DER_SENTIDO2);
Motores motores(PIN_MOTOR_IZQ_VELOCIDAD, PIN_MOTOR_IZQ_SENTIDO1, PIN_MOTOR_IZQ_SENTIDO2,
                PIN_MOTOR_DER_VELOCIDAD, PIN_MOTOR_DER_SENTIDO1, PIN_MOTOR_DER_SENTIDO2);

SensorLinea sensor_linea1(PIN_SENSOR_LINEA1);
// SensorLinea sensor_linea2(PIN_SENSOR_LINEA2);

SensorDistancia sensor_distancia(PIN_SENSOR_DISTANCIA);

bool en_linea() {
	// return sensor_linea1.en_linea() || sensor_linea2.en_linea();
}

void setup_prueba_motores() {
	motores.set_velocidad(50);
}

void setup()
{
	Serial.begin(9600);
	// setup_prueba_motores();
}

void prueba_motores() {
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

void prueba_sensor_linea() {
	// Serial.println(en_linea());
	Serial.println(sensor_linea1.en_linea());
	delay(1000);
}

void prueba_sensor_distancia() {
	Serial.println(sensor_distancia.distancia());
	delay(1000);
}

void loop()
{
	// Serial.println("hola mundo");

	// prueba_motores();
	// prueba_sensor_linea();
	prueba_sensor_distancia();
}