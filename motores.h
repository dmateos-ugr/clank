#ifndef _MOTORES_H
#define _MOTORES_H

#include "motor.h"

class Motores {
	public:
		Motores(uint8_t pin_velocidad_izq, uint8_t pin_sentido1_izq, uint8_t pin_sentido2_izq,
		        uint8_t pin_velocidad_der, uint8_t pin_sentido1_der, uint8_t pin_sentido2_der);

		enum Direccion {
			Right,
			Left,
			Forwards,
			Backwards,
		};
		void set_direccion(Direccion direccion);
		void set_velocidad(uint8_t velocidad); // velocidad entre 0 y 100
		void encender();
		void apagar();
		bool encendidos() const;

	private:
		Motor m_motor_izq;
		Motor m_motor_der;

};

#endif