#include <iostream>
#include <vector>
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

	string inStr; //Переменная считывающая данные из файла ввода

	int numberOfPolygons; //Количество многоугольников

	vector<vector<double>> initialCoordinatesVector; //двумерный вектор, содержащий многоугольники (вектор многоугольников)

	vector<vector<double>> totalCoordinatesVector;

	int numberOfVertices; //количество вершин в многоугольнике

	double coordinateItself; //сама координата

	while (!inputFile.eof())
	{
		inStr = "";

		inputFile >> inStr;

		numberOfPolygons = std::stoi(inStr); //считывание количества многоугольников из файла ввода

		if (numberOfPolygons < 0) // Если количество многоугольников меньше нуля
		{
			outputFile << "The number of polygons is incorrectly specified.";
			return 0;
		}
		else if (numberOfPolygons == 0) // Если количество многоугольников равно нулю
		{
			outputFile << "There are no polygons on the plane.";
			return 0;
		}

		initialCoordinatesVector.resize(numberOfPolygons);

		for (int i = 0; i < numberOfPolygons; i++) // Для каждого многоугольника
		{
			inputFile >> inStr;

			numberOfVertices = std::stoi(inStr); //считывание количества вершин в многоугольнике из файла ввода

			if (numberOfVertices < 3) //если количество вершин меньше трех - не получится замкнутой фигуры
			{
				outputFile << "The number of vertices in " << i + 1 << " polygon is incorrectly specified.";
				return 0;
			}

			initialCoordinatesVector[i].resize(2 * numberOfVertices);

			for (int j = 0; j < (2 * numberOfVertices); j++) // Для каждой координаты многоугольника
			{
				inputFile >> inStr;

				coordinateItself = std::stod(inStr); //считывание координаты из файла ввода

				initialCoordinatesVector[i][j] = coordinateItself; // Записать координату в многоугольник 
			}
		}
	}

	for (int i = 0; i < numberOfPolygons; i++) // Цикл, который идёт по строкам
	{
		for (int j = 0; j < totalCoordinatesVector[i].size(); j += 2) // Цикл, который идёт по элементам
		{
			outputFile << "(" << totalCoordinatesVector[i][j] << ";" << totalCoordinatesVector[i][j + 1] << ") "; // Вывод элементов i строки вектора
		}
		outputFile << endl;
	}

	outputFile.close();

	return 0;
}
