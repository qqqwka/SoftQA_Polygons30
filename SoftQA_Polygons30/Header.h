#pragma once

using namespace std;

/*!Структура координат точки
*/
struct point
{
	double x;
	double y;
};

/*!Найти перекрестное произведение двух векторов
\param[in] A - вектор, содержащий координаты двух смежных ребер многоугольника
\return перекрестное произведение двух векторов
*/
double CrossProduct(vector<double>& A);


/*!Проверить, является ли многоугольник выпуклым
\param[in] points - вектор, содержащий координаты многоугольника
*/
bool isPolygonConvex(vector<double>& points);

/*!Проверить нахождение точки в многоугольнике
\param[in] XofPoint - координата X точки
\param[in] YofPoint - координата Y точки
\param[in] vec - вектор, содержащий координаты многоугольника
*/
bool isPointInPolygon(double XofPoint, double YofPoint, vector<double>& vec);


/*!Проверить, имеют ли два отрезка точку пересечения
\param[in] x1 - координата X первой точки
\param[in] y1 - координата Y первой точки
\param[in] x2 - координата X второй точки
\param[in] y2 - координата Y второй точки
\param[in] x3 - координата X третьей точки
\param[in] y3 - координата Y третьей точки
\param[in] x4 - координата X четвертой точки
\param[in] y4 - координата Y четвертой точки
*/
bool doSegmentsIntersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);


/*!Найти точку пересечения двух отрезков
\param[in] x1 - координата X первой точки
\param[in] y1 - координата Y первой точки
\param[in] x2 - координата X второй точки
\param[in] y2 - координата Y второй точки
\param[in] x3 - координата X третьей точки
\param[in] y3 - координата Y третьей точки
\param[in] x4 - координата X четвертой точки
\param[in] y4 - координата Y четвертой точки
\param[in|out] totalX - координата X точки пересечения
\param[in|out] totalY - координата Y точки пересечения
*/
void findIntersectionPoint(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double& totalX, double& totalY);


/*!Определить, есть ли такая же точка в многоугольнике
\param[in] vec1 - первый вектор
\param[in] vec2 - второй вектор
\param[in] rX - координата X точки пересечения
\param[in] rY - координата Y точки пересечения
*/
bool isIntersectionPointAlreadyInVector(vector<double>& vec1, vector<double>& vec2, double rX, double rY);


/*!Вставить точку пересечения в вектор, хранящий координаты вершин многоугольника
\param[in] veci1 - первый вектор без точек пересечения
\param[in] vecj1 - второй вектор без точек пересечения
\param[in|out] veci2 - первый вектор с точками пересечения
\param[in|out] vecj2 - второй вектор с точками пересечения
*/
void intersectionPointInsert(vector<double>& veci1, vector<double>& vecj1, vector<double>& veci2, vector<double>& vecj2);


/*!Определить, есть ли одинаковые точки в двух многоугольниках
\param[in] vec1 - первый многоугольник
\param[in] vec2 - второй многоугольник
*/
bool areThereCommonPointsInPolygons(vector<double>& vec1, vector<double>& vec2);


/*!Объединить два многоугольника в один
\param[in|out] vec1 - первый многоугольник
\param[in] vec2 - второй многоугольник
*/
void combiningPolygons(vector<double>& vec1, vector<double>& vec2);