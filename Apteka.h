#pragma once
#include "Baza_danych.h"

class Apteka
{
private:
	Baza_danych bd;

public:
	Apteka(string pzz, string pzo, string pzka) : bd(pzz, pzo, pzka) {}

	bool Logowanie()
	{
		string nazwa_uzytkownika;
		string haslo;

		cout << "Podaj nazwe uzytkownika i haslo w formacie nazwa_uz haslo(ENTER) ";
		cin >> nazwa_uzytkownika >> haslo;

		vector<Dane_aptekarzy> lista_aptekarzy = bd.DawajDaneAptekarzy();

		for (Dane_aptekarzy i : lista_aptekarzy)
		{
			if (i.nazwa_uzytkownika == nazwa_uzytkownika && i.haslo == haslo)
			{
				return true;
			}
		}

		return false;
	}

	void KupLek()
	{
		int typ_leku;
		int j = 0;
		string ktory_lek;

		cout << "Podaj typ leku, ktory chcesz kupic: ";
		cin >> typ_leku;

		vector<Dane_leku> lista_lekow = bd.DawajListeLekow();

		for (Dane_leku i : lista_lekow)
		{
			if (i.typ == typ_leku)
			{
				j++;
				cout << j << ". Lek: " << i.nazwa << endl << "Podany typ: " << typ_leku << endl << "Dostepnosc w ilosci: " << i.ilosc << endl;
			}
		}

		cout << "Wybierz nazwe leku, ktory chcesz kupic i kliknij ENTER(nawet jezeli go nie ma), jezeli sie rozmysliles, wcisnij cokolwiek innego i ENTER ";

		cin >> ktory_lek;

		for (Dane_leku& i : lista_lekow)
		{
			if (i.nazwa == ktory_lek)
			{
				if (i.ilosc > 0)
				{
					i.ilosc--;

					cout << "Zakupiono lek!" << endl;

					bd.ZaktualizujZasoby(lista_lekow);
					return;
				}
				else if (i.ilosc == 0)
				{
					DodawanieDoListyOczekujacych(ktory_lek);
					return;
				}
			}
		}
	}

	void DodawanieDoListyOczekujacych(string nazwa_leku)
	{
		cout << "Czy chcesz zostac dodanym do oczekujacych na " << nazwa_leku << "? Jezeli tak napisz tak i wcisnij ENTER: ";
		string odpowiedz;
		string mail;
		cin >> odpowiedz;

		if (odpowiedz == "tak")
		{
			cout << "Podaj swoj mail: ";
			cin >> mail;

			vector<Oczekujacy_na_lek> lista_oczekujacych = bd.DawajListeOczekujacych();

			for (Oczekujacy_na_lek& i : lista_oczekujacych)
			{
				if (i.nazwa_leku == nazwa_leku)
				{
					i.lista_maili_oczekujacych.push_back(mail);

					cout << "Dodano maila" << endl;

					bd.AktualizujOczekujacych(lista_oczekujacych);
					break;
				}
			}
		}
	}

	void UzupelnijZasoby()
	{
		vector<Dane_leku> lista_lekow = bd.DawajListeLekow();
		vector<string> lista_uzupelnionych_lekow;
		int ile_uzupelnic;

		for (Dane_leku& i : lista_lekow)
		{
			if (i.ilosc == 0)
			{
				do
				{
					cout << "W jakiej ilosci chcesz uzupelnic " << i.nazwa << " (wartosci >= 0): ";
					cin >> ile_uzupelnic;

					if (cin.fail() || ile_uzupelnic < 0)
					{
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

						cout << "Blad! Wprowadz poprawna liczbe wieksza lub rowna 0." << endl;
					}
				} while (cin.fail() || ile_uzupelnic < 0);

				if (ile_uzupelnic > 0)
				{
					i.ilosc = ile_uzupelnic;
					lista_uzupelnionych_lekow.push_back(i.nazwa);
					cout << "Uzupelniono " << i.nazwa << "(" << ile_uzupelnic << " sztuk)" << endl;
				}
			}
		}
		bd.ZaktualizujZasoby(lista_lekow);

		PowiadomLudzi(lista_uzupelnionych_lekow);
	}

	void PowiadomLudzi(vector<string> lista_uzupelnionych_lekow)
	{
		vector<Oczekujacy_na_lek> lista_oczekujacych = bd.DawajListeOczekujacych();

		for (string lek : lista_uzupelnionych_lekow)
		{
			for (Oczekujacy_na_lek& i : lista_oczekujacych)
			{
				if (lek == i.nazwa_leku)
				{
					for (string mail : i.lista_maili_oczekujacych)
					{
						cout << "Powiadamiam " << mail << " o dostepnosci leku " << lek << endl;
					}

					i.lista_maili_oczekujacych.clear();
				}
			}
		}

		bd.AktualizujOczekujacych(lista_oczekujacych);
	}

	void WyswietlZasoby()
	{
		vector<Dane_leku> lista = bd.DawajListeLekow();

		for (Dane_leku i : lista)
		{
			cout << i.nazwa << ", typ " << i.typ << endl << "Ilosc na stanie: " << i.ilosc << endl;
		}
	}

	void WyswietlOczekujacych()
	{
		vector<Oczekujacy_na_lek> lista = bd.DawajListeOczekujacych();

		for (Oczekujacy_na_lek i : lista)
		{
			cout << i.nazwa_leku << endl << "Lista Oczekujacych na ten lek:" << endl;

			for (string j : i.lista_maili_oczekujacych)
			{
				cout << j << ", ";
			}

			cout << endl << endl;
		}
	}

	void WyswietlAptekarzy()
	{
		vector<Dane_aptekarzy> lista = bd.DawajDaneAptekarzy();

		for (Dane_aptekarzy i : lista)
		{
			cout << "Aptekarz: " << i.nazwa_uzytkownika << ", haslo to " << i.haslo << endl;
		}
	}
};
