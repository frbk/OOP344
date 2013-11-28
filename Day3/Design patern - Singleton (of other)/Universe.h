#ifndef UNIVERSE_H
#define UNIVERSE_H
#include <iostream>
using namespace std;

class Universe
{
	Universe() {}
	friend class Singleton;
public:
	void DisplaySolarSystem()
	{
		cout << "Sun, Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, Neptun, Pluto" << endl;
		return;
	}
};

#endif