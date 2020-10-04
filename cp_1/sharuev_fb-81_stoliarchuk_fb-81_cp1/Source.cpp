#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string textFileToString(string text)
{
	string buffer;
	ifstream fin("E:\\hello.txt");
	while (fin >> buffer)
	{
		text = text + buffer + " ";
	}
	return text;
}

string whitepaper(string text)
{
	string newText;
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] >= 'А' && text[i] <= 'я' || text[i] == ' ')
		{
			if (text[i] >= 'А' && text[i] <= 'Я')
			{
				text[i] += 32;
			}
			newText += text[i];
		}
	}
	return newText;
}

double Entropy_H1(int* alphabet, int length)
{
	double P = 0;//pi*log2(pi)
	double p;//вероятность
	cout << "Вероятность букв" << endl;
	wcout << L"а\t б\t в\t г\t д\t е\t ё\t ж\t з\t и\t й" << endl;
	for (int i = 0; i < 33; i++)
	{
		p = (double)alphabet[i] / length;
		cout << fixed;
		cout.precision(5);// х,ххххх
		cout << p << "\t";

		if (i == 10)
		{
			wcout << endl << L"к\t л\t м\t н\t о\t п\t р\t с\t т\t у\t ф" << endl;
		}
		if (i == 21)
		{
			wcout << endl << L"х\t ц\t ч\t ш\t щ\t ъ\t ы\t ь\t э\t ю\t я" << endl;
		}
		if (p != 0)
		{
			P += (p * log2(p));
		}
	}
	cout << endl;
	return(P * (-1));
}



int main()
{
	setlocale(LC_ALL, "rus");

	string text;
	text = textFileToString(text);
	cout << text;
	cout << "====================================================" << endl;
	text = whitepaper(text);
	cout << text;

	return 0;
}