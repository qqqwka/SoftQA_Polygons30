#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(const int argc, char* argv[])
{
	//----------ПРОВЕРКА ОШИБОК РАБОТЫ С ФАЙЛАМИ----------

	if (argc == 1)
	{
		cout << "The input file is specified incorrectly. It is possible that the file at the specified location does not exist.\n";
		return 0;
	}

	//Выдать ошибку, если выходной файл не указан в аргументах командной строки
	if (argc == 2)
	{
		cout << "The output file is specified incorrectly. It is possible that the file at the specified location does not exist..\n";
		return 0;
	}

	ifstream inputFile;	//Файл ввода

	inputFile.open(argv[1]);

	if (!inputFile.is_open()) //Выдать ошибку,если входной файл невозможно открыть
	{
		cout << "The input file cannot be opened. The file may have the wrong extension.\n";
		return 0;
	}

	ofstream outputFile;//Файл вывода

	outputFile.open(argv[2]);

	if (!outputFile.is_open()) //Выдать ошибку,если выходной файл невозможно открыть
	{
		cout << "The output data file cannot be opened. The file may have the wrong extension.\n";
		return 0;
	}
	else
	{
		outputFile.trunc;
	}

	int numberOfPolygons; //Количество многоугольников

	int numberOfVertices; //количество вершин в многоугольнике

	double coordinateItself; //сама координата

	outputFile.close();

	return 0;
}
