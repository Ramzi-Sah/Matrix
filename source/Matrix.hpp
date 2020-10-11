#ifndef SAH_MATRIX
#define SAH_MATRIX

#include <iostream>
#include <stdlib.h>
#include <sstream>

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

    std::string toStr();

    // value setters and getters
    void setVal(unsigned int index_x, unsigned int index_y, float val);
    float getVal(unsigned int index_x, unsigned int index_y);

    unsigned int getSizeY();
    unsigned int getSizeX();

    // transpose
    Matrix getTranspose();

    // addition
    Matrix add(Matrix mat);

    // multiplication
    Matrix multiplyBy(float val);
    Matrix multiplyBy(Matrix mat); // A.multiplyBy(B) => A x B
};

#endif
