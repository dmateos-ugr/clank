#ifndef _SENSOR_DISTANCIA_H
#define _SENSOR_DISTANCIA_H

// https://naylampmechatronics.com/blog/10_tutorial-de-arduino-y-sensor-ultrasonico-hc-sr04.html
// http://www.superrobotica.com/s320111.htm modo 2

class SensorDistancia {
	public:
		SensorDistancia(uint8_t pin) : m_pin(pin) {
			pinMode(pin, OUTPUT);
			digitalWrite(pin, 0);
		};

		long distancia() {
			digitalWrite(m_pin, HIGH);
			delayMicroseconds(10);
			digitalWrite(m_pin, LOW);

			pinMode(m_pin, INPUT);
			long t = pulseIn(m_pin, HIGH);

			pinMode(m_pin, OUTPUT);
			return t/59;
		}

	private:
		uint8_t m_pin;
};

#endif