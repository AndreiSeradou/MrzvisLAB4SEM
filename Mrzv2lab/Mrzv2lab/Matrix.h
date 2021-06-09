#pragma once
#include <vector>
using namespace std;

class Matrix
{
private:
	vector<vector<double>> matrixVector;
public:
	Matrix sum(Matrix b);
	Matrix multiplicate(Matrix b);
	Matrix multiplicate(int b);
	vector<vector<double>> getMatrixVector();
	void setMatrixVector(const vector<vector<double>>& vec);
};

