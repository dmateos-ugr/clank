#include "motor.h"

Motor::Motor(uint8_t pin_velocidad, uint8_t pin_sentido1, uint8_t pin_sentido2)
	: m_pin_velocidad(pin_velocidad)
	, m_pin_sentido1(pin_sentido1)
	, m_pin_sentido2(pin_sentido2)
	, m_encendido(false)
	, m_sentido(Forwards)
	, m_velocidad(0)
{
	pinMode(m_pin_velocidad, OUTPUT);
	pinMode(m_pin_sentido1, OUTPUT);
	pinMode(m_pin_sentido2, OUTPUT);
	update_velocidad();
	update_sentido();
}

void Motor::update_velocidad() {
	uint8_t valor_analog = map(m_velocidad, 0, 100, 0, 255);
	analogWrite(m_pin_velocidad, valor_analog*m_encendido);
}

void Motor::update_sentido() {
	digitalWrite(m_pin_sentido1, m_sentido);
	digitalWrite(m_pin_sentido2, !m_sentido);
}

void Motor::set_sentido(SentidoGiro sentido) {
	m_sentido = sentido;
	update_sentido();
}

void Motor::set_velocidad(uint8_t velocidad) {
	m_velocidad = velocidad;
	update_velocidad();
}

void Motor::encender() {
	m_encendido = true;
	update_velocidad();
}

void Motor::apagar() {
	m_encendido = false;
	update_velocidad();
}

bool Motor::encendido() const {
	return m_encendido;
}