#ifndef _MOTOR_H
#define _MOTOR_H

class Motor {
	public:
		enum SentidoGiro : bool {
			Forwards = false,
			Backwards = true,
		};
		Motor(uint8_t pin_velocidad, uint8_t pin_sentido1, uint8_t pin_sentido2);
		void set_sentido(SentidoGiro sentido);
		void set_velocidad(uint8_t velocidad);
		void encender();
		void apagar();

	private:
		uint8_t m_pin_velocidad, m_pin_sentido1, m_pin_sentido2;

		bool m_encendido;
		SentidoGiro m_sentido;
		uint8_t m_velocidad;

		void update_velocidad();
		void update_sentido();

};

#endif