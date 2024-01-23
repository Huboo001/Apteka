#include "Interface.h"

int main()
{
	Interface interfejs = Interface("zasoby.txt", "oczekujacy.txt", "hasla_aptekarzy.txt");
	int wybor;

	cout << "Witaj w aptece, co chcesz zrobic" << endl;
	cout << "1. Zaloguj sie jako aptekarz" << endl;
	cout << "2. Zakup lek" << endl;
	cin >> wybor;

	while (wybor == 1 || wybor == 2)
	{
		if (wybor == 1)
		{
			if (interfejs.Logowanie())
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
						interfejs.WyswietlZasoby();
					}
					else if (wybor == 2)
					{
						interfejs.WyswietlOczekujacych();
					}
					else if (wybor == 3)
					{
						interfejs.WyswietlAptekarzy();
					}
					else if (wybor == 4)
					{
						interfejs.UzupelnijZasoby();
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
			interfejs.KupLek();
		}

		cout << "Witaj w aptece, co chcesz zrobic" << endl;
		cout << "1. Zaloguj sie jako aptekarz" << endl;
		cout << "2. Zakup lek" << endl;
		cin >> wybor;
		system("cls");
	}

	return 0;
}