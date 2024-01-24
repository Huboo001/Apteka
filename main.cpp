#include "Interface.h"

int main()
{
	Interface interface("zasoby.txt", "oczekujacy.txt", "hasla_aptekarzy.txt");
	interface.DzialajProgramiku();
	return 0;
}