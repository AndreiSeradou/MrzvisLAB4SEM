
#include "Matrix.h"


void Matrix::setMatrixVector(const vector<vector<double>>& vec)
{
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i].size() != vec[i - 1].size()) {
			delete this;
		}
	}
	matrixVector = vec;
}

vector<vector<double>> Matrix::getMatrixVector() {
	return matrixVector;
}

/*Matrix Matrix::sum(Matrix b) {
	if (matrixVector.size() == b.matrixVector.size()) {
		for (int i = 0; i < matrixVector.size(); i++) {
			if (matrixVector[i].size() == b.matrixVector[i].size()) {
				for (int j = 0; j < matrixVector[i].size(); j++) {
					b.matrixVector[i][j] += matrixVector[i][j];
				}
			}
			else return Matrix{ {} };
		}
		return b;
	}
	else return Matrix{ {} };
}

Matrix Matrix::multiplicate(Matrix b) {
	vector<vector<double>> vec;
	for (int i = 0; i < matrixVector.size(); i++) {
		if (matrixVector[i].size() == b.matrixVector.size()){
			vec.push_back(vector<double> {});
			for (int j = 0; j < b.matrixVector[i].size(); j++) {
				double counter = 0;
				for (int k = 0; k < matrixVector[i].size(); k++) {
					counter += matrixVector[i][k]*b.matrixVector[k][j];
				}
				vec[i].push_back(counter);
			}
		}
		else {
			return Matrix{ {} };
		}
	}
	return Matrix{ vec };
}

Matrix Matrix::multiplicate(int b) {
	vector<vector<double>> vec;
	for (int i = 0; i < matrixVector.size(); i++) {
		vec.push_back(vector<double> {});
		for (int j = 0; j < matrixVector[i].size(); j++) {
			vec[i].push_back(matrixVector[i][j]*b);
		}
	}
	return Matrix{ vec };
}*/
