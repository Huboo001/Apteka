#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Oczekujacy_na_lek
{
	string nazwa_leku;
	vector<string> lista_maili_oczekujacych;
};

struct Dane_leku//te same typy to bêd¹ zamienniki
{
	int typ;
	string nazwa;
	int ilosc;
};

struct Dane_aptekarzy
{
	string nazwa_uzytkownika;
	string haslo;
};
