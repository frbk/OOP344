#include "Singleton.h"
#include "Universe.h"

void main()
{
	Universe *u = Singleton::getInstance();
	u->DisplaySolarSystem();
}
