#ifndef SAH_MATRIX
#define SAH_MATRIX

#include <stdlib.h>
#include <sstream>
#include <iostream>

class Matrix {
private:
    unsigned int size_y, size_x;
    float** values;

public:
    Matrix(const Matrix &mat); // copy constructor
    Matrix& operator=(const Matrix &mat); // = operator

    Matrix(unsigned int _sizeY, unsigned int _sizeX);
    Matrix(unsigned int _sizeY, unsigned int _sizeX, float val);

    ~Matrix();
    void dispose();

    // value setters and getters
    void setVal(unsigned int index_x, unsigned int index_y, float val); // set matrix's value by index
    float getVal(unsigned int index_x, unsigned int index_y); // get matrix's value on index

    unsigned int getSizeY(); // get matrix's number of rows
    unsigned int getSizeX(); // get matrix's number of coloumns

    // some predefined matrices
    static Matrix identity(unsigned int size); // identity matrix

    // some usefull methods
    std::string toStr(); // convert matrix to string
    Matrix getTranspose(); // get matrix's transpose
    float getDeterminant(); // calculate matrix's determinant

    // addition
    Matrix add(Matrix mat);
    Matrix operator+(const Matrix &mat); // + operator

    // multiplication
    Matrix multiplyBy(float val);
    Matrix operator*(const float &val);

    Matrix multiplyBy(Matrix mat); // A.multiplyBy(B) => A x B
    Matrix operator*(const Matrix &mat);

};

#endif
