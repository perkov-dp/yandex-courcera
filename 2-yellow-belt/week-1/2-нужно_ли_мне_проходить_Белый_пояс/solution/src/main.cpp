#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
using namespace std;

class Matrix {
public:
	Matrix() {
		num_rows_ = 0;
		num_columns_ = 0;
	}
	Matrix(const int& num_rows, const int& num_cols) {
		Reset(num_rows, num_cols);
	}

	void Reset(const int& new_num_rows, const int& new_num_cols)
	{
		if (new_num_rows < 0) {
			throw out_of_range("new_num_rows must be >= 0");
		}
		else if (new_num_cols < 0) {
			throw out_of_range("new_num_cols must be >= 0");
		}
		//	Матрицы с нулём строк или нулём столбцов считаются пустыми
		else if (new_num_rows == 0 || new_num_cols == 0) {
			num_rows_ = num_columns_ = 0;
		}

		num_rows_ = new_num_rows;
		num_columns_ = new_num_cols;

		//	все строки заполняю векторами столбцов
		matrix.assign(num_rows_, vector<int>(num_columns_));
	}

	int At (const int& row, const int& col) const {
		return matrix.at(row).at(col);	//	если такого эл-та нет, то выбросится исключение
	}

	int& At (const int& row, const int& col) {
		return matrix.at(row).at(col);	//	если такого эл-та нет, то выбросится исключение
	}

	int GetNumRows() const {
		return num_rows_;
	}

	int GetNumColumns() const {
		return num_columns_;
	}

private:
	  int num_rows_;
	  int num_columns_;

	  vector <vector<int>> matrix;
};

ostream&  operator<<(ostream& stream, const Matrix& matrix) {
	stream << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
	for (int i = 0; i < matrix.GetNumRows(); i++) {
		for (int j = 0; j < matrix.GetNumColumns(); j++) {
			stream << matrix.At(i, j) << " ";
		}
		stream << endl;
	}

	return stream;
}

istream& operator>>(istream& stream, Matrix& matrix) {
	int row_num = 0;
	int col_num = 0;

	stream >> row_num >> col_num;
	matrix.Reset(row_num, col_num);

	for (int i = 0; i < matrix.GetNumRows(); i++) {
		for (int j = 0; j < matrix.GetNumColumns(); j++) {
			stream >> matrix.At(i, j);
		}
	}

	return stream;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
	if (lhs.GetNumRows() != rhs.GetNumRows()) {
		throw invalid_argument("The number of rows does not match");
	}
	else if (lhs.GetNumColumns() != rhs.GetNumColumns()) {
		throw invalid_argument("The number of colums does not match");
	}

	Matrix result(lhs.GetNumRows(), lhs.GetNumColumns());
	for (int i = 0; i < result.GetNumRows(); i++) {
		for(int j = 0; j < result.GetNumColumns(); j++) {
			result.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
		}
	}

	return result;
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
	if ((lhs.GetNumRows() != rhs.GetNumRows()) ||
		(lhs.GetNumColumns() != rhs.GetNumColumns())) {
		return false;
	}

	for (int i = 0; i < lhs.GetNumRows(); i++) {
		for(int j = 0; j < lhs.GetNumColumns(); j++) {
			if (lhs.At(i, j) != rhs.At(i, j)) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	Matrix one;
	Matrix two;

	cin >> one >> two;
	cout << one + two << endl;

	return 0;
}
