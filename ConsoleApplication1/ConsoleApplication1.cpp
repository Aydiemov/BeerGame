#include <iostream>
#include <string>
using namespace std;

bool PonderingAnswer(int guess, int beerCount);
wstring AnsweringAnswer(int guess, int beerCount);
wstring MinuteCasing(int guessCount);

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int beerCount = rand() % 20 + 1;
	int guessCount = 5;
	int guess;
	wcout << L"(вводите ответ числом)\n\n";
	wcout << L"Сколько пива я сегодня выпил?" << endl;

	
	while (guessCount > 0 && !cin.fail())
	{
		wcout << L"На размышление дается " << guessCount << " " << MinuteCasing(guessCount) << ": ";
		cin >> guess;

		if (cin.fail() && guessCount > 1)
		{
			wcout << L"бляяЯЯЯ ЧЕ СКАЗАЛ НИХУЯ НЕ ПОНЯЛ\nя спрашиваю СКОЛЬКО ПИВА Я СЕГОДНЯ ВЫПИЛ??" << endl;
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); //я нихуя не понимаю
		}
		else if (PonderingAnswer(guess, beerCount))
		{
			wcout << L"БляяЯЯЯ ХАРОШ!! А ХУЛИ НЕ НА ФРОНТЕ??\n\n";
			break;
		}
		else if (!cin.fail())
		{
			wcout << AnsweringAnswer(guess, beerCount);
		}
		guessCount--;
	}

	if (guessCount == 0)
	{
		wcout << L"Тебе там за щеку присунули, проверяй\n\n";
	}
	system("pause");
	return 0;
}

bool PonderingAnswer(int guess, int beerCount)
{
	if (guess == beerCount)
	{
		return true;
	}
	else
	{
		return false;
	}
}

wstring AnsweringAnswer(int guess, int beerCount)
{
	if (guess > beerCount)
	{
		return L"Много! Иди нахуй!\n";
	}
	else
	{
		return L"Мало! Иди нахуй!\n";
	}
}

wstring MinuteCasing(int guessCount)
{
	if (guessCount == 5)
	{
		return L"минут";
	}
	else if (guessCount > 1 && guessCount < 5)
	{
		return L"минуты";
	}
	else
	{
		return L"минута";
	}
}