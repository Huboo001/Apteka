#pragma once
#include <fstream>
#include <sstream>
#include "plik_structow.h"

class Baza_danych
{
private:
	string plik_z_zasobami;
	string plik_z_oczekujacymi;
	string plik_z_kontami_aptekarzy;

public:
	Baza_danych(string pzz, string pzo, string pzka)
	{
		plik_z_oczekujacymi = pzo;
		plik_z_zasobami = pzz;
		plik_z_kontami_aptekarzy = pzka;
	}

	vector<Dane_aptekarzy> DawajDaneAptekarzy()
	{
		vector<Dane_aptekarzy> lista_aptekarzy;
		Dane_aptekarzy dodawany;

		ifstream pliczek(plik_z_kontami_aptekarzy);
		while (getline(pliczek, dodawany.nazwa_uzytkownika))
		{
			getline(pliczek, dodawany.haslo);
			lista_aptekarzy.push_back(dodawany);
		}

		pliczek.close();
		return lista_aptekarzy;
	}

	vector<Dane_leku> DawajListeLekow()
	{
		vector<Dane_leku> lista_lekow;
		Dane_leku dodawany;
		string pom;

		ifstream pliczek(plik_z_zasobami);
		while (getline(pliczek, pom))
		{
			dodawany.typ = stoi(pom);
			getline(pliczek, dodawany.nazwa);
			getline(pliczek, pom);
			dodawany.ilosc = stoi(pom);

			lista_lekow.push_back(dodawany);
		}

		pliczek.close();
		return lista_lekow;
	}

	void ZaktualizujZasoby(vector<Dane_leku> lista_lekow)
	{
		ofstream pliczek(plik_z_zasobami);

		for (Dane_leku lek : lista_lekow)
		{
			pliczek << lek.typ << endl << lek.nazwa << endl << lek.ilosc << endl;
		}

		pliczek.close();
	}

	void AktualizujOczekujacych(vector<Oczekujacy_na_lek> lista_oczekujacych)
	{
		ofstream pliczek(plik_z_oczekujacymi);

		for (Oczekujacy_na_lek i : lista_oczekujacych)
		{
			pliczek << i.nazwa_leku << endl;

			for (string j : i.lista_maili_oczekujacych)
			{
				pliczek << j << " ";
			}

			pliczek << endl;
		}

		pliczek.close();
	}

	vector<Oczekujacy_na_lek> DawajListeOczekujacych()
	{
		vector<Oczekujacy_na_lek> lista;
		string pom;
		Oczekujacy_na_lek dodawany;

		ifstream pliczek(plik_z_oczekujacymi);

		while (getline(pliczek, dodawany.nazwa_leku))
		{
			dodawany.lista_maili_oczekujacych.clear();
			getline(pliczek, pom);
			istringstream strumyk_tekstu(pom);
			string mail;

			while (strumyk_tekstu >> mail)
			{
				dodawany.lista_maili_oczekujacych.push_back(mail);
			}

			lista.push_back(dodawany);
		}

		pliczek.close();
		return lista;
	}
};
