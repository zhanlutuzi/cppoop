Main.cpp
#include<iostream>
#include "Matrix.h"
using namespace std;
int main() {
	int m;
	int n;
	cout << "First:\n" << "Dimensions:" << endl;
	cin >> m >> n;
	Matrix<int> a(m, n);
	cout << "Value:" << endl;
	cin >> a;
	cout << "Second:\n" << "Dimensions:" << endl;
	cin >> m >> n;
	Matrix<int> b(m, n);
	cout << "Value:" << endl;
	cin >> b;
	Matrix<int> c = a + b;

	c.CoutMatrix(c);
	c = a - b;
	c.CoutMatrix(c);
	c = a * b;
	c.CoutMatrix(c);
	c = a * 2;
	c.CoutMatrix(c);
	return 0;
}

Matrix.h
#pragma once
#include <iostream>
#include <fstream>
using namespace std;
template<class T>
class Matrix {
private:
	int m_x;
	int m_y;
	T** m_matrix = nullptr;
public:
	Matrix(int, int);
	~Matrix();
	Matrix(const Matrix<T>&);
	Matrix<T> operator+(const Matrix<T>&) const;
	Matrix<T> operator-(const Matrix<T>&)const;
	Matrix<T> operator*(const Matrix<T>&)const;
	Matrix<T> operator*(const T&)const;
	Matrix<T> operator=(const Matrix<T>&)const;
	void CoutMatrix(Matrix<T>&);
	friend istream& operator>><T>(istream&, Matrix<T>&);
};

template<class T>
void Matrix<T>::CoutMatrix(Matrix<T>&v) {
	ofstream ofs("CoutResult.dat", ios::app);
	for (int i = 0; i < v.m_x; i++) {
		for (int j = 0; j < v.m_y; j++) {
			cout << v.m_matrix[i][j] << '	';
			ofs << v.m_matrix[i][j] << '	';
		}
		cout << endl;
		ofs << endl;
	}
	ofs << endl;
	ofs.close();
}

template<class T>
Matrix<T>::Matrix(int x, int y) :m_x(x), m_y(y) {
	m_matrix = new T*[x] {0};
	for (int i = 0; i < x; i++) {
		m_matrix[i] = new T[y]{ 0 };
	}
}

template<class T>
Matrix<T>::~Matrix() {
	if (m_matrix != nullptr) {
		for (int i = 0; i < m_x; i++) {
			delete[] m_matrix[i];
		}
		delete[]m_matrix;
		m_matrix = nullptr;
	}
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>&m) {
	m_y = m.m_y;
	m_x = m.m_x;
	m_matrix = new T*[m_x];
	for (int i = 0; i < m_x; i++) {
		m_matrix[i] = new T[m_y];
	}
	for (int i = 0; i < m_x; i++) {
		for (int j = 0; j < m_y; j++) {
			m_matrix[i][j] = m.m_matrix[i][j];
		}
	}
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>&m) const {
	Matrix n(m_x, m_y);
	cout << "the result of +:" << endl;
	if (m_x == m.m_x&&m_y == m.m_y) {
		for (int i = 0; i < m_x; i++) {
			for (int j = 0; j < m_y; j++) {
				n.m_matrix[i][j] = m_matrix[i][j] + m.m_matrix[i][j];
			}
		}
		return n;
	}
	else {
		cout << "you are sweat baby" << endl;
		return *this;
	}
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>&m) const {
	Matrix n(m_x, m_y);
	cout << "the result of -:" << endl;
	if (m_x == m.m_x&&m_y == m.m_y) {
		for (int i = 0; i < m_x; i++) {
			for (int j = 0; j < m_y; j++) {
				n.m_matrix[i][j] = m_matrix[i][j] - m.m_matrix[i][j];
			}
		}
		return n;
	}
	else {
		cout << "you are sweat baby" << endl;
		return Matrix(m_x, m_y);
	}

}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>&m) const {
	Matrix<T> n(m_x, m.m_y);
	cout << "the result of *:" << endl;
	if (m_x == m.m_y&&m_y == m.m_x) {
		for (int i = 0; i < n.m_x; i++) {
			for (int j = 0; j < n.m_y; j++) {
				for (int p = 0; p < m.m_x; p++) {
					n.m_matrix[i][j] += m_matrix[i][j] * m.m_matrix[j][i];
				}
			}
		}
		return n;
	}
	else {
		cout << "you are sweat baby" << endl;
		return Matrix(m_x, m_y);
	}

}

template<class T>
Matrix<T> Matrix<T>::operator*(const T &n) const {
	Matrix m(m_x, m_y);
	cout << "the result of *:" << endl;
	for (int i = 0; i < m_x; i++) {
		for (int j = 0; j < m_y; j++) {
			m.m_matrix[i][j] = n * m_matrix[i][j];
		}
	}
	return m;
}

template<class T>
Matrix<T> Matrix<T>::operator=(const Matrix<T>&m) const {
	for (int i = 0; i < m_x; i++) {
		for (int j = 0; j < m_y; j++) {
			m_matrix[i][j] = m.m_matrix[i][j];
		}
	}
	return Matrix(m_x, m_y);
}

template<class T>
istream & operator>>(istream &in, Matrix<T>& b) {
	for (int i = 0; i < b.m_x; i++) {
		for (int j = 0; j < b.m_y; j++) {
			in >> b.m_matrix[i][j];
		}
	}
	return in;
}
