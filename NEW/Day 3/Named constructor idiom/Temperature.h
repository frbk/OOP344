#ifndef TEMPERATURE_H
#define TMERATURE_H

class Temperature
{
	double dgr;
	Temperature(double dgr) { this->dgr = dgr; }
public:
	static Temperature Celsius(double) throw();
	static Temperature Farenheit(double) throw();
	double getTemperatue() const { return dgr; }
};

inline Temperature Temperature::Celsius(double dgr) throw()
{
	return Temperature(dgr);
}

inline Temperature Temperature::Farenheit(double dgr) throw()
{
	return Temperature((dgr-32.)*5./9);
}

#endif