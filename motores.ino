#include "motores.h"

Motores::Motores(
	uint8_t pin_velocidad_izq, uint8_t pin_sentido1_izq, uint8_t pin_sentido2_izq,
	uint8_t pin_velocidad_der, uint8_t pin_sentido1_der, uint8_t pin_sentido2_der)
	: m_motor_izq(pin_velocidad_izq, pin_sentido1_izq, pin_sentido2_izq)
	, m_motor_der(pin_velocidad_der, pin_sentido1_der, pin_sentido2_der)
{
}

void Motores::set_direccion(Direccion direccion) {
	Motor::SentidoGiro sentido_izq, sentido_der;
	switch (direccion) {
		case Right:
			sentido_izq = Motor::Forwards;
			sentido_der = Motor::Backwards;
			break;
		case Left:
			sentido_izq = Motor::Backwards;
			sentido_der = Motor::Forwards;
			break;
		case Forwards:
			sentido_izq = Motor::Forwards;
			sentido_der = Motor::Forwards;
			break;
		case Backwards:
			sentido_izq = Motor::Backwards;
			sentido_der = Motor::Backwards;
			break;
	}
	m_motor_izq.set_sentido(sentido_izq);
	m_motor_der.set_sentido(sentido_der);
}

void Motores::set_velocidad(uint8_t velocidad) {
	m_motor_der.set_velocidad(velocidad);
	m_motor_izq.set_velocidad(velocidad);
}

void Motores::encender() {
	m_motor_der.encender();
	m_motor_izq.encender();
}

void Motores::apagar() {
	m_motor_der.apagar();
	m_motor_izq.apagar();
}