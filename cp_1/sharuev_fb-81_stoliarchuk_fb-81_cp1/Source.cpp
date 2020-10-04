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