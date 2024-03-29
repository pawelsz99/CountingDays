// ZliczanieDni.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//


#include <iostream>

using namespace std;

bool rok(int r); //czy rok jest przestepny

int dni(int a, int b); //ile miesiac ma dni

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int d1[6], d2[6];		// 0-rok 1-miesiac 2-dzien 3-godzina 4-minuta 5-sekunda
		int c = 0;		//liczba dni

		for (int i = 0; i < 6; i++)
			cin >> d1[i];
		for (int i = 0; i < 6; i++)
			cin >> d2[i];
		
			while (d2[5] != d1[5])	//zrownanie sekund
			{
				d1[5]++;
				if (d1[5] > 59)
				{
					d1[4]++;
					d1[5] = 0;
				}
			}
			if (d1[4] > 59) //overflow
			{
				d1[3]++;
				d1[4] = 0;
			}
			while (d2[4] != d1[4])	//zrownanie minut
			{
				d1[4]++;
				if (d1[4] > 59)
				{
					d1[3]++;
					d1[4] = 0;
				}
			}
			if (d1[3] > 23) //overflow
			{
				d1[2]++;
				d1[3] = 0;
			}
			while (d2[3] != d1[3])	//zrownanie godzin
			{
				d1[3]++;
				if (d1[3] > 23)
				{
					d1[2]++;
					d1[3] = 0;
				}
			}
			if (d1[2] > dni(d1[1],d1[0])) //overflow
			{
				d1[1]++;
				d1[2] = 1;
			}
			while (d2[2] != d1[2])	//zrownanie dni
			{
				d1[2]++;
				c++;
				if (d1[2] > dni(d1[1], d1[0]))
				{
					d1[1]++;
					d1[2] = 1;
				}
			}
			if (d1[1] > 12) //overflow
			{
				d1[0]++;
				d1[1] = 1;
			}
			while (d2[1] != d1[1])	//zrownanie miesiecy
			{	
				c += dni(d1[1], d1[0]);
				d1[1]++;
				
				if (d1[1] > 12)
				{
					d1[0]++;
					d1[1] = 1;
				}
			}
			while (d2[0] != d1[0])	//zrownanie lat
			{
				if (rok(d1[0]))
					c += 366;
				else
					c += 365;
				
				d1[0]++;
			}

		cout << c << endl;

	}
}


bool rok(int r) //czy rok jest przestepny
{
	if (r % 4 == 0)
	{
		if (r % 100 == 0 && r % 400 != 0)
			return false;
		else
			return true;
	}
	else
		return false;
}

int dni(int a, int b)
{
	switch (a)
	{
	case 1:
		return 31;
	case 2:
		if (rok(b))
			return 29;
		else
			return 28;
	case 3:
		return 31;
	case 4:
		return 30;
	case 5:
		return 31;
	case 6:
		return 30;
	case 7:
		return 31;
	case 8:
		return 31;
	case 9:
		return 30;
	case 10:
		return 31;
	case 11:
		return 30;
	case 12:
		return 31;
	}
}
// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
