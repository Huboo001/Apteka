#pragma once
#include "Apteka.h"

class Interface
{
private:
	Apteka apteka;

public:
	Interface(string pzz, string pzo, string pzka) : apteka(pzz, pzo, pzka)
	{
		;
	}

	void DzialajProgramiku()
	{
		int wybor;

		cout << "Witaj w aptece, co chcesz zrobic" << endl;
		cout << "1. Zaloguj sie jako aptekarz" << endl;
		cout << "2. Zakup lek" << endl;
		cin >> wybor;

		while (wybor == 1 || wybor == 2)
		{
			if (wybor == 1)
			{
				if (apteka.Logowanie())
				{
					system("cls");
					cout << "Co chcesz zrobic" << endl;
					cout << "1. Wyswietl zasoby" << endl;
					cout << "2. Wyswietl liste oczekujacych na leki" << endl;
					cout << "3. Wyswietl liste_aptekarzy" << endl;
					cout << "4. Uzupelnij zasoby" << endl;
					cout << "5. Wyloguj" << endl;
					cin >> wybor;
					system("cls");

					while (wybor == 1 || wybor == 2 || wybor == 3 || wybor == 4)
					{
						if (wybor == 1)
						{
							apteka.WyswietlZasoby();
						}
						else if (wybor == 2)
						{
							apteka.WyswietlOczekujacych();
						}
						else if (wybor == 3)
						{
							apteka.WyswietlAptekarzy();
						}
						else if (wybor == 4)
						{
							apteka.UzupelnijZasoby();
						}

						cout << "Co chcesz zrobic" << endl;
						cout << "1. Wyswietl zasoby" << endl;
						cout << "2. Wyswietl liste oczekujacych na leki" << endl;
						cout << "3. Wyswietl liste_aptekarzy" << endl;
						cout << "4. Uzupelnij zasoby" << endl;
						cout << "5. Wyloguj" << endl;
						cin >> wybor;
						system("cls");
					}

				}
				else
				{
					system("cls");
					cout << "Bledne dane" << endl;
				}
			}
			else if (wybor == 2)
			{
				apteka.KupLek();
			}

			cout << "Witaj w aptece, co chcesz zrobic" << endl;
			cout << "1. Zaloguj sie jako aptekarz" << endl;
			cout << "2. Zakup lek" << endl;
			cin >> wybor;
			system("cls");
		}
	}
};
