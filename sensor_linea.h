#ifndef _SENSOR_LINEA_H
#define _SENSOR_LINEA_H

// https://hetpro-store.com/TUTORIALES/cny70-sensor-optico/

class SensorLinea {
	public:
		SensorLinea(uint8_t pin) : m_pin(pin) {
			pinMode(pin, INPUT);
		};

		bool en_linea() {
			int value = analogRead(m_pin);
			// Serial.println(value);
			return analogRead(m_pin) < 100;
		}

	private:
		uint8_t m_pin;

};

#endif