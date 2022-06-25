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
#define PIN_SENSOR_LINEA_ATRAS A0
#define PIN_SENSOR_LINEA_DELANTE A1
#define PIN_SENSOR_DISTANCIA 2

// Motor motor_izq(PIN_MOTOR_IZQ_VELOCIDAD, PIN_MOTOR_IZQ_SENTIDO1, PIN_MOTOR_IZQ_SENTIDO2);
// Motor motor_der(PIN_MOTOR_DER_VELOCIDAD, PIN_MOTOR_DER_SENTIDO1, PIN_MOTOR_DER_SENTIDO2);
Motores motores(PIN_MOTOR_IZQ_VELOCIDAD, PIN_MOTOR_IZQ_SENTIDO1, PIN_MOTOR_IZQ_SENTIDO2,
                PIN_MOTOR_DER_VELOCIDAD, PIN_MOTOR_DER_SENTIDO1, PIN_MOTOR_DER_SENTIDO2);

SensorLinea sensor_linea_atras(PIN_SENSOR_LINEA_ATRAS);
SensorLinea sensor_linea_delante(PIN_SENSOR_LINEA_DELANTE);

SensorDistancia sensor_distancia(PIN_SENSOR_DISTANCIA);

void setup_prueba_motores() {
	motores.set_velocidad(100);
}

void prueba_sensor_linea() {
	Serial.println(sensor_linea_atras.en_linea());
	delay(1000);
}

void prueba_sensor_distancia() {
	Serial.println(sensor_distancia.distancia());
	// delay(1000);
}

void setup()
{
	Serial.begin(9600);
	motores.set_velocidad(100);
	motores.encender();
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




void loop()
{
	
	// if (!sensor_linea_delante.en_linea()) {
	// 	motores.encender();
	// 	motores.set_direccion(Motores::Forwards);
	// }
	// else{
	// 	motores.apagar();
	// }

	// if (!sensor_linea_delante.en_linea()) {
	// 	motores.set_direccion(Motores::Backwards);	
	// }

	

	// prueba_motores();
	// prueba_sensor_linea();
	// prueba_sensor_distancia();

	// Ejemplo mantenerse a distancia
	// long distancia = sensor_distancia.distancia();
	// if (distancia < 30) {
	// 	motores.set_direccion(Motores::Backwards);
	// 	motores.encender();
	// } else if (30 <= distancia && distancia <= 35) {
	// 	motores.apagar();
	// } else if (35 < distancia) {
	// 	motores.set_direccion(Motores::Forwards);
	// 	motores.encender();
	// }

	if(sensor_linea_atras.en_linea()){
		motores.set_direccion(Motores::Forwards);
		Serial.println("LINEA ATRAS");
	}
	else if(sensor_linea_delante.en_linea()){
		motores.set_direccion(Motores::Backwards);
		Serial.println("LINEA DELANTE");
	}
	else if(sensor_distancia.distancia() < 50){
		motores.set_direccion(Motores::Forwards);
		Serial.println("PERSEGUIR");
	}
	else{
		motores.set_direccion(Motores::Left);
		Serial.println("GIRAR");
	}


	delay(10);
}