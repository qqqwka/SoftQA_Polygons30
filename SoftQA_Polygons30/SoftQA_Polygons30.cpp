#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include"Header.h"

using namespace std;

int main(int argc, char* argv[])
{
	//----------ПРОВЕРКА ОШИБОК РАБОТЫ С ФАЙЛАМИ----------

	//Выдать ошибку, если входной файл не указан в аргументах командной строки
	if (argc == 1)
	{
		cout << "The input data file is specified incorrectly. It is possible that the file at the specified location does not exist.\n";
		return 1;
	}
	//Выдать ошибку, если выходной файл не указан в аргументах командной строки
	if (argc == 2)
	{
		cout << "The output data file is specified incorrectly. It is possible that the file at the specified location does not exist.\n";
		return 2;
	}


	ifstream inputFile;	//Файл ввода
	inputFile.open(argv[1]);
	if (!inputFile.is_open()) //Выдать ошибку,если входной файл невозможно открыть
	{
		cout << "The input data file cannot be opened. The file may have the wrong extension.";
		return 3;
	}

	ofstream outputFile;	//Файл вывода
	outputFile.open(argv[2]);
	if (!outputFile.is_open()) //Выдать ошибку,если выходной файл невозможно открыть
	{
		cout << "The output data file cannot be opened. The file may have the wrong extension.";
		return 4;
	}
	else
	{
		outputFile.trunc;
	}

	string inStr; //Переменная считывающая данные из файла ввода

	int numberOfPolygons = 0; //Количество многоугольников

	vector<vector<double>> initialCoordinatesVector; //двумерный вектор, содержащий многоугольники (вектор многоугольников)

	vector<vector<double>> totalCoordinatesVector;

	int numberOfVertices = 0; //количество вершин в многоугольнике

	double coordinateItself; //сама координата

	while (!inputFile.eof())
	{
		inStr = "";

		inputFile >> inStr;

		numberOfPolygons = std::stoi(inStr); //считывание количества многоугольников из файла ввода

		if (numberOfPolygons < 0) // Если количество многоугольников меньше нуля
		{
			outputFile << "The number of polygons is incorrectly specified.";
			outputFile.close();
			return 0;
		}
		else if (numberOfPolygons == 0) // Если количество многоугольников равно нулю
		{
			outputFile << "There are no polygons on the plane.";
			outputFile.close();
			return 0;
		}

		initialCoordinatesVector.resize(numberOfPolygons);

		for (int i = 0; i < numberOfPolygons; i++) // Для каждого многоугольника
		{
			inStr = "";
			inputFile >> inStr;

			numberOfVertices = std::stoi(inStr);//считывание количества вершин в многоугольнике из файла ввода


			if (numberOfVertices < 3) //если количество вершин меньше трех - не получится замкнутой фигуры
			{
				outputFile << "The number of vertices in " << i + 1 << " polygon is incorrectly specified.";
				outputFile.close();
				return 0;
			}

			initialCoordinatesVector[i].resize(2 * numberOfVertices);

			for (int j = 0; j < (2 * numberOfVertices); j++) // Для каждой координаты многоугольника
			{
				inStr = "";
				inputFile >> inStr;

				coordinateItself = std::stod(inStr); //считывание координаты из файла ввода

				initialCoordinatesVector[i][j] = coordinateItself; // Записать координату в многоугольник 
			}

		}

	}

	for (int i = 0; i < numberOfPolygons; i++) // Для каждого многоугольника
	{
		if (numberOfVertices > 4) // Если вершин многоугольника больше 4
		{
			if (isPolygonConvex(initialCoordinatesVector[i]) == 0) // проверить многоугольник на выпуклость
			{
				outputFile << "Polygon specified " << i + 1 << " is non-convex." << endl;
				return 0;
			}
		}
	}

	totalCoordinatesVector.resize(numberOfPolygons);

	for (int i = 0; i < numberOfPolygons; i++) // Для каждого многоугольника
	{
		for (int j = 0; j < initialCoordinatesVector[i].size(); j++) // Для каждой координаты многоугольника
		{
			totalCoordinatesVector[i].push_back(initialCoordinatesVector[i][j]); // Вставить координату из изначального вектора во второй
		}
	}

	//Вставить в конец вектора координаты первой точки многоугольника для удобства
	for (int i = 0; i < numberOfPolygons; i++)
	{
		initialCoordinatesVector[i].push_back(initialCoordinatesVector[i][0]);
		initialCoordinatesVector[i].push_back(initialCoordinatesVector[i][1]);
	}

	//Вставить в конец вектора координаты первой точки многоугольника для удобства
	for (int i = 0; i < numberOfPolygons; i++)
	{
		totalCoordinatesVector[i].push_back(totalCoordinatesVector[i][0]);
		totalCoordinatesVector[i].push_back(totalCoordinatesVector[i][1]);
	}

	for (int i = 0; i < numberOfPolygons; i++) // Для каждого вектора
	{
		for (int j = 0; j < numberOfPolygons; j++)
		{
			if (i == j && i != numberOfPolygons - 1)
			{
				j = j + 1;
			}

			if (i == j && i == numberOfPolygons - 1)
			{
				break;
			}

			// Вставить точку пересечения в многоугольник
			intersectionPointInsert(initialCoordinatesVector[i], initialCoordinatesVector[j], totalCoordinatesVector[i], totalCoordinatesVector[j]);

		}
	}

	//Удалить координаты первой точки многоугольника из конца многоугольника
	for (int i = 0; i < numberOfPolygons; i++)
	{
		initialCoordinatesVector[i].pop_back();
		initialCoordinatesVector[i].pop_back();
	}

	//Удалить координаты первой точки многоугольника из конца многоугольника
	for (int i = 0; i < numberOfPolygons; i++)
	{
		totalCoordinatesVector[i].pop_back();
		totalCoordinatesVector[i].pop_back();
	}


	if (numberOfPolygons > 1)
	{
		//УДАЛЕНИЕ ТОЧЕК ВЕКТОРА, ЕСЛИ ОНИ НАХОДЯТСЯ ВНУТРИ ДРУГОГО ВЕКТОРА
		for (int i = 0; i < numberOfPolygons; i++) // Для каждого многоугольника
		{
			for (int j = 0; j < numberOfPolygons; j++) // Для каждого многоугольника
			{
				if (i == j && i != numberOfPolygons - 1)
				{
					j = j + 1;
				}

				if (i == j && i == numberOfPolygons - 1) // если оба итератора дошли до последней координаты второго многоугольника
				{
					break; // выйти из цикла
				}

				for (int e = 0; e < totalCoordinatesVector[j].size() - 1; e += 2)
				{
					if (isPointInPolygon(totalCoordinatesVector[j][e], totalCoordinatesVector[j][e + 1], totalCoordinatesVector[i]) == 1) // Если есть точка внутри вектора
					{
						if (isIntersectionPointAlreadyInVector(totalCoordinatesVector[i], totalCoordinatesVector[j], totalCoordinatesVector[j][e], totalCoordinatesVector[j][e + 1]) == 0)
						{
							totalCoordinatesVector[j].erase(totalCoordinatesVector[j].begin() + e); //Удалить эту точку из вектора
							totalCoordinatesVector[j].erase(totalCoordinatesVector[j].begin() + e); //Удалить эту точку из вектора
							e = -2;
						}
					}
				}

			}
		}
	}

	for (int i = 0; i < numberOfPolygons; i++) // Для каждого вектора
	{
		for (int j = 0; j < numberOfPolygons; j++) // Для каждого вектора
		{
			if (i == j && i != numberOfPolygons - 1)
			{
				j = j + 1;
			}

			if (i == j && i == numberOfPolygons - 1)
			{
				break;
			}

			//ПОВЕРКА, ЕСТЬ ЛИ В ДВУХ ВЕКТОРАХ КАК МИНИМУМ ДВЕ ОБЩИЕ ТОЧКИ
			if (areThereCommonPointsInPolygons(totalCoordinatesVector[i], totalCoordinatesVector[j]) == 1)
			{
				//ОБЪЕДИНЕНИЕ ДВУХ МНОГОУГОЛЬНИКОВ
				if (totalCoordinatesVector[i][1] <= totalCoordinatesVector[j][1]) // Если Y первой точки первого вектора меньше или равен Y первой точки второго вектора
				{
					combiningPolygons(totalCoordinatesVector[i], totalCoordinatesVector[j]);
					totalCoordinatesVector.erase(totalCoordinatesVector.begin() + j);
					numberOfPolygons = totalCoordinatesVector.size();
					i = 0;
					if (numberOfPolygons > 1)
					{
						j = -2;
					}
					break;
				}

				if (totalCoordinatesVector[j][1] < totalCoordinatesVector[i][1]) // //Если Y первой точки второго вектора меньше или равен Y первой точки первого вектора
				{
					combiningPolygons(totalCoordinatesVector[j], totalCoordinatesVector[i]);
					totalCoordinatesVector.erase(totalCoordinatesVector.begin() + i);
					numberOfPolygons = totalCoordinatesVector.size();
					i = 0;
					if (numberOfPolygons > 1)
					{
						j = -2;
					}
					break;
				}

				if (numberOfPolygons == 1) // Если остался один многоугольник
				{
					break; // Выйти из цикла
				}

			}
		}
		if (numberOfPolygons == 1) // Если остался один многоугольник
		{
			break; // Выйти из цикла
		}
	}

	//УДАЛИТЬ ВЕКТОР С КООРДИНАТАМИ, ЕСЛИ ОСТАЛОСЬ 2 ИЛИ МЕНЬШЕ ВЕРШИНЫ
	for (int i = 0; i < numberOfPolygons; i++) //Для каждого многоугольника
	{
		if (totalCoordinatesVector[i].size() <= 4) // Если в многоугольнике меньше, чем  2 или ровно 2 точки
		{
			totalCoordinatesVector.erase(totalCoordinatesVector.begin() + i); // Удалить этот многоугольник
			numberOfPolygons = numberOfPolygons - 1; // Количество многоугольников уменьшить на 1
		}
	}


	for (int i = 0; i < numberOfPolygons; i++) // Цикл, который идёт по строкам
	{
		for (int j = 0; j < totalCoordinatesVector[i].size(); j += 2) // Цикл, который идёт по элементам
		{
			outputFile << "(" << totalCoordinatesVector[i][j] << ";" << totalCoordinatesVector[i][j + 1] << ") "; // Вывод элементов i строки вектора
		}
		outputFile << "\n";
	}

	outputFile.close();

	return 0;
}

double CrossProduct(vector<double>& A)
{
	double X1 = (A[2] - A[0]); // Хранит угловой коэффициент X вектора 1

	double Y1 = (A[3] - A[1]); // Хранит угловой коэффициент Y вектора 1

	double X2 = (A[4] - A[0]); // Хранит угловой коэффициент X вектора 2

	double Y2 = (A[5] - A[1]); // Хранит угловой коэффициент Y вектора 2

	return (X1 * Y2 - Y1 * X2); // Возвращает перекрестное произведение двух векторов
}

bool isPolygonConvex(vector<double>& points)
{
	int N = points.size(); // Количество координат в многоугольнике

	double prev = 0; // Угловой коэффициент перекрестного произведения предыдущих пройденных ребер

	double curr = 0; // Угловой коэффициент перекрестного произведения текущих пройденных ребер

	// Для каждой тройки координат переданного многоугольника
	for (int i = 0; i < N - 1; i += 2) {

		// Записать координаты двух смежных ребра многоугольника
		vector<double> temp = { points[i % N], points[(i + 1) % N],
			points[(i + 2) % N], points[(i + 3) % N],
			points[(i + 4) % N], points[(i + 5) % N]
		};

		// Обновление curr
		curr = CrossProduct(temp); // Перекрестное произведение векторов из вектора temp

		// Если curr не равен 0
		if (curr != 0) {

			// Если угловой коэффициент перекрестного произведения всех соседних ребер не совпадает
			if (curr * prev < 0) {

				return false; // Многоугольник - невыпуклый
			}
			else {

				// Обновление curr
				prev = curr;
			}
		}
	}
	return true; // Многоугольник - выпуклый
}

bool isPointInPolygon(double XofPoint, double YofPoint, vector<double>& vec)
{
	point SomePoint; // Точка, нахождение внутри многоугольника которой будет проверяться

	SomePoint.x = XofPoint;

	SomePoint.y = YofPoint;

	bool result = false; // Результат

	int j = vec.size() - 1;

	for (int i = 0; i < vec.size() - 1; i += 2) {

		// Если прямая, выходящая из точки, проходит четное количество ребер
		if ((vec[i + 1] < SomePoint.y && vec[j] >= SomePoint.y || vec[j] < SomePoint.y && vec[i + 1] >= SomePoint.y) &&
			(vec[i] + (SomePoint.y - vec[i + 1]) / (vec[j] - vec[i + 1]) * (vec[j - 1] - vec[i]) < SomePoint.x))
		{
			result = !result;
		}

		j = i + 1;
	}

	return result; // Вернуть результат

}

bool doSegmentsIntersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	double Ua, Ub, UaNumer, UbNumer, UDenom;

	UaNumer = ((x4 - x3) * (y1 - y3)) - ((y4 - y3) * (x1 - x3)); // Числитель первого уравнения на координаты точки пересечения
	UbNumer = ((x2 - x1) * (y1 - y3)) - ((y2 - y1) * (x1 - x3)); // Числитель второго уравнения на координаты точки пересечения
	UDenom = ((y4 - y3) * (x2 - x1)) - ((x4 - x3) * (y2 - y1)); // Знаменатель уравнений на координаты точки пересечения

	if (UDenom == 0) // Если знаменатель равен нулю
	{
		return false; // Отрезки не имеют точку пересечения
	}

	Ua = UaNumer / UDenom; // Первое уравнение на координаты точки пересечения

	Ub = UbNumer / UDenom; // Второе уравнение на координаты точки пересечения

	if (0 <= Ua && Ua <= 1 && 0 <= Ub && Ub <= 1) // Если Ua и Ub принадлежат промежутку [0;1]
	{
		return true; // Отрезки имеют точку пересечения
	}
	else
	{
		return false; // Отрезки не имеют точку пересечения
	}
	return false; // Отрезки не имеют точку пересечения
}

void findIntersectionPoint(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double& totalX, double& totalY)
{
	double Ua, Ub, UaNumer, UbNumer, UDenom;

	UaNumer = ((x4 - x3) * (y1 - y3)) - ((y4 - y3) * (x1 - x3)); // Числитель первого уравнения на координаты точки пересечения
	UbNumer = ((x2 - x1) * (y1 - y3)) - ((y2 - y1) * (x1 - x3)); // Числитель второго уравнения на координаты точки пересечения
	UDenom = ((y4 - y3) * (x2 - x1)) - ((x4 - x3) * (y2 - y1)); // Знаменатель уравнений на координаты точки пересечения

	Ua = UaNumer / UDenom; // Первое уравнение на координаты точки пересечения

	Ub = UbNumer / UDenom; // Второе уравнение на координаты точки пересечения

	totalX = x1 + (Ua * (x2 - x1)); // Координата X точки пересечения
	totalY = y1 + (Ua * (y2 - y1)); // Координата Y точки пересечения
}

bool isIntersectionPointAlreadyInVector(vector<double>& vec1, vector<double>& vec2, double rX, double rY)
{
	for (int i = 0; i < vec1.size() - 1; i += 2) // Для каждой точки многоугольника
	{
		if (vec1[i] == rX && vec1[i + 1] == rY) // Если точка многоугольника совпадает с точкой пересечения
		{
			return true; // Такая точка уже есть в многоугольнике
		}
	}
	return false; // Такой точки нет в многоугольнике
}

void intersectionPointInsert(vector<double>& veci1, vector<double>& vecj1, vector<double>& veci2, vector<double>& vecj2)
{
	double firstX, firstY, secondX, secondY, thirdX, thirdY, fourthX, fourthY; // Координаты двух точек из каждого вектора

	double ResultX, ResultY; // Координаты точки пересечения двух отрезков

	//double A, B, C; // Переменные уравнения прямой

	for (int k = 0; k < veci2.size() - 3; k += 2) // Для каждой точки первого вектора с точками пересечения
	{

		for (int m = 0; m < vecj2.size() - 3; m += 2) // Для каждой точки второго вектора с точками пересечения
		{

			// Координаты двух точек из каждого вектора
			firstX = veci2[k];
			firstY = veci2[k + 1];

			secondX = veci2[k + 2];
			secondY = veci2[k + 3];

			thirdX = vecj2[m];
			thirdY = vecj2[m + 1];

			fourthX = vecj2[m + 2];
			fourthY = vecj2[m + 3];

			if (doSegmentsIntersect(firstX, firstY, secondX, secondY, thirdX, thirdY, fourthX, fourthY) == 1) // Имеют ли два отрезка точку пересечения
			{
				findIntersectionPoint(firstX, firstY, secondX, secondY, thirdX, thirdY, fourthX, fourthY, ResultX, ResultY); // Вычислить точку пересечения двух отрезков

				if (isIntersectionPointAlreadyInVector(veci2, vecj1, ResultX, ResultY) == 0) // Если такой точки нет в векторе
				{

					// Вставить координаты точки в вектор
					veci2.insert(veci2.begin() + k + 2, ResultX);
					veci2.insert(veci2.begin() + k + 3, ResultY);

				}

				if (isIntersectionPointAlreadyInVector(vecj2, veci1, ResultX, ResultY) == 0) // Если такой точки нет в векторе
				{

					// Вставить координаты точки в вектор
					vecj2.insert(vecj2.begin() + m + 2, ResultX);
					vecj2.insert(vecj2.begin() + m + 3, ResultY);

				}

			}
		}
	}
}

bool areThereCommonPointsInPolygons(vector<double>& vec1, vector<double>& vec2)
{

	int commonPCheck = 0; // Счетчик одинаковых точек

	for (int i = 0; i < vec1.size() - 1; i += 2) // Для каждой точки первого вектора
	{
		for (int j = 0; j < vec2.size() - 1; j += 2) // Для каждой точки второго вектора
		{
			if (vec1[i] == vec2[j] && vec1[i + 1] == vec2[j + 1]) // Если точки совпадают
			{
				commonPCheck = commonPCheck + 1; // Увеличить счетчик на 1
			}
		}
	}

	if (commonPCheck < 2) // Если счетчик меньше 2
	{
		return false; // Одинаковых точек нет (или она одна)
	}
	else // Иначе
	{
		return true; // Одинаковые точки есть (их две или больше)
	}
}

void combiningPolygons(vector<double>& vec1, vector<double>& vec2)
{
	for (int i = 0; i < vec1.size() - 1; i += 2) // Для каждой точки первого вектора
	{
		for (int j = 0; j < vec2.size() - 1; j += 2) // Для каждой точки второго вектора
		{
			if (vec2.size() == 0) // Если размер второго вектора равен нулю
			{
				break; // Выйти из цикла
			}

			if (vec1[i] == vec2[j]) // Если координаты i первого многоугольника и j второго многоугольника равны
			{
				if (vec1[i + 1] == vec2[j + 1]) // Если координаты i+1 первого многоугольника и j+1 второго многоугольника равны
				{
					if (vec2.size() == 0) // Если размер второго вектора равен нулю
					{
						break; // Выйти из цикла
					}

					if (j == vec2.size() - 2) // Если итератор во втором векторе дошел до последней точки 
					{
						// Стереть эту точку из второго вектора
						vec2.erase(vec2.begin() + j);
						vec2.erase(vec2.begin() + j);

						j = 0; // Перейти к первой точке второго вектора

						for (int k = i; k < vec1.size() - 1; k += 2)
						{
							if (vec2.size() == 0) // Если размер второго вектора равен нулю
							{
								break; // Выйти из цикла
							}

							if (vec1[k + 2] != vec2[j] || vec1[k + 3] != vec2[j + 1])
							{
								// Вставить эту точку в первый вектор
								vec1.insert(vec1.begin() + k + 2, vec2[j]);
								vec1.insert(vec1.begin() + k + 3, vec2[j + 1]);

								// Стереть эту точку из второго вектора
								vec2.erase(vec2.begin() + j);
								vec2.erase(vec2.begin() + j);

							}

							if (vec1[k + 2] == vec2[j] && vec1[k + 3] == vec2[j + 1]) // Если следующая после i-ой точка первого вектора равна точке второго вектора 
							{
								// Стереть эту точку из второго вектора
								vec2.erase(vec2.begin() + j);
								vec2.erase(vec2.begin() + j);

								break; // Выйти из цикла
							}

						}

					}
					else
					{
						// Стереть эту точку из второго вектора
						vec2.erase(vec2.begin() + j);
						vec2.erase(vec2.begin() + j);

						for (int k = i; k < vec1.size() - 1; k += 2)
						{
							if (vec2.size() == 0) // Если размер второго вектора равен нулю
							{
								break; // Выйти из цикла
							}

							if (vec1[k + 2] != vec2[j] || vec1[k + 3] != vec2[j + 1]) // Если следующая после i-ой точка первого вектора не равна точке второго вектора 
							{
								// Вставить эту точку в первый вектор
								vec1.insert(vec1.begin() + k + 2, vec2[j]);
								vec1.insert(vec1.begin() + k + 3, vec2[j + 1]);

								// Стереть эту точку из второго вектора
								vec2.erase(vec2.begin() + j);
								vec2.erase(vec2.begin() + j);

							}

							if (vec2.size() <= 2) // Если размер второго вектора меньше либо равен 2
							{
								break; // Выйти из цикла
							}

							if (vec1[k + 2] == vec2[j] && vec1[k + 3] == vec2[j + 1]) // Если следующая после i-ой точка первого вектора равна точке второго вектора 
							{
								// Стереть эту точку из второго вектора
								vec2.erase(vec2.begin() + j);
								vec2.erase(vec2.begin() + j);

								break; // Выйти из цикла
							}
						}
					}
				}
			}
		}
	}
}