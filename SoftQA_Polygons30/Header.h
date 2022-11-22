#pragma once

using namespace std;

/*!��������� ��������� �����
*/
struct point
{
	double x;
	double y;
};

/*!����� ������������ ������������ ���� ��������
\param[in] A - ������, ���������� ���������� ���� ������� ����� ��������������
\return ������������ ������������ ���� ��������
*/
double CrossProduct(vector<double>& A);


/*!���������, �������� �� ������������� ��������
\param[in] points - ������, ���������� ���������� ��������������
*/
bool isPolygonConvex(vector<double>& points);

/*!��������� ���������� ����� � ��������������
\param[in] XofPoint - ���������� X �����
\param[in] YofPoint - ���������� Y �����
\param[in] vec - ������, ���������� ���������� ��������������
*/
bool isPointInPolygon(double XofPoint, double YofPoint, vector<double>& vec);


/*!���������, ����� �� ��� ������� ����� �����������
\param[in] x1 - ���������� X ������ �����
\param[in] y1 - ���������� Y ������ �����
\param[in] x2 - ���������� X ������ �����
\param[in] y2 - ���������� Y ������ �����
\param[in] x3 - ���������� X ������� �����
\param[in] y3 - ���������� Y ������� �����
\param[in] x4 - ���������� X ��������� �����
\param[in] y4 - ���������� Y ��������� �����
*/
bool doSegmentsIntersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);


/*!����� ����� ����������� ���� ��������
\param[in] x1 - ���������� X ������ �����
\param[in] y1 - ���������� Y ������ �����
\param[in] x2 - ���������� X ������ �����
\param[in] y2 - ���������� Y ������ �����
\param[in] x3 - ���������� X ������� �����
\param[in] y3 - ���������� Y ������� �����
\param[in] x4 - ���������� X ��������� �����
\param[in] y4 - ���������� Y ��������� �����
\param[in|out] totalX - ���������� X ����� �����������
\param[in|out] totalY - ���������� Y ����� �����������
*/
void findIntersectionPoint(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double& totalX, double& totalY);


/*!����������, ���� �� ����� �� ����� � ��������������
\param[in] vec1 - ������ ������
\param[in] vec2 - ������ ������
\param[in] rX - ���������� X ����� �����������
\param[in] rY - ���������� Y ����� �����������
*/
bool isIntersectionPointAlreadyInVector(vector<double>& vec1, vector<double>& vec2, double rX, double rY);


/*!�������� ����� ����������� � ������, �������� ���������� ������ ��������������
\param[in] veci1 - ������ ������ ��� ����� �����������
\param[in] vecj1 - ������ ������ ��� ����� �����������
\param[in|out] veci2 - ������ ������ � ������� �����������
\param[in|out] vecj2 - ������ ������ � ������� �����������
*/
void intersectionPointInsert(vector<double>& veci1, vector<double>& vecj1, vector<double>& veci2, vector<double>& vecj2);


/*!����������, ���� �� ���������� ����� � ���� ���������������
\param[in] vec1 - ������ �������������
\param[in] vec2 - ������ �������������
*/
bool areThereCommonPointsInPolygons(vector<double>& vec1, vector<double>& vec2);


/*!���������� ��� �������������� � ����
\param[in|out] vec1 - ������ �������������
\param[in] vec2 - ������ �������������
*/
void combiningPolygons(vector<double>& vec1, vector<double>& vec2);