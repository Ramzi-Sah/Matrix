#include "Matrix.hpp"

Matrix::Matrix(const Matrix &mat) {
    //std::cout << "copy constructor" << std::endl;

    size_x = mat.size_x;
    size_y = mat.size_y;

    // dynamically allocate matrix memory
    values = (float**) malloc(sizeof(float*) * size_x * size_y);

    for (unsigned int k = 0; k < size_y; k++)
        values[k] = (float*) malloc(sizeof(float) * size_x);

    // set values
    for (unsigned int j = 0; j < size_y; j++)
        for (unsigned int i = 0; i < size_x; i++)
            values[j][i] = mat.values[j][i];
};

Matrix& Matrix::operator=(const Matrix &mat) {
    //std::cout << "= operator" << std::endl;

    size_x = mat.size_x;
    size_y = mat.size_y;

    // dynamically allocate matrix memory
    values = (float**) malloc(sizeof(float*) * size_x * size_y);

    for (unsigned int k = 0; k < size_y; k++)
        values[k] = (float*) malloc(sizeof(float) * size_x);

    // set values
    for (unsigned int j = 0; j < size_y; j++)
        for (unsigned int i = 0; i < size_x; i++)
            values[j][i] = mat.values[j][i];

    return *this;
};

Matrix::Matrix(unsigned int _sizeY, unsigned int _sizeX) {
    size_x = _sizeX;
    size_y = _sizeY;

    // dynamically allocate matrix memory
    values = (float**) malloc(sizeof(float*) * size_x * size_y);

    for (unsigned int j = 0; j < size_y; j++)
        values[j] = (float*) malloc(sizeof(float) * size_x);
};

Matrix::Matrix(unsigned int _sizeY, unsigned int _sizeX, float val) {
    size_x = _sizeX;
    size_y = _sizeY;

    // dynamically allocate matrix memory
    values = (float**) malloc(sizeof(float*) * size_x * size_y);

    for (unsigned int k = 0; k < size_y; k++)
        values[k] = (float*) malloc(sizeof(float) * size_x);

    // set values
    for (unsigned int j = 0; j < _sizeY; j++)
        for (unsigned int i = 0; i < _sizeX; i++)
            values[j][i] = val;
};

Matrix::~Matrix() {
    dispose();
};

void Matrix::dispose() {
    for (unsigned int k = 0; k < size_y; k++)
        free(values[k]);

    free(values);
};

// convert matrix to string
std::string Matrix::toStr() {
    std::stringstream ss;

    for (unsigned int j = 0; j < size_y; j++) {
        for (unsigned int i = 0; i < size_x; i++) {
            ss << getVal(j, i);
            if (i < size_x-1)
                ss << " | ";
        };
        ss << "\n";
    };

    return ss.str();
};

//---------------------------------------------
// value setters and getters
void Matrix::setVal(unsigned int index_y, unsigned int index_x, float val) {
    if (!(index_x >= size_x || index_y >= size_y))
        values[index_y][index_x] = val;
};
float Matrix::getVal(unsigned int index_y, unsigned int index_x) {
    if (index_x >= size_x || index_y >= size_y)
        return 0;

    return values[index_y][index_x];
};

unsigned int Matrix::getSizeY() {
    return size_y;
};
unsigned int Matrix::getSizeX() {
    return size_x;
};

//---------------------------------------------
// transpose
Matrix Matrix::getTranspose() {
    Matrix temp = Matrix(size_x, size_y);

    for (unsigned int j = 0; j < size_y; j++)
        for (unsigned int i = 0; i < size_x; i++)
            temp.setVal(i, j, values[j][i]);

    return temp;
};

//---------------------------------------------
// addition
Matrix Matrix::add(Matrix mat) {
    // init temp matrix
    Matrix temp(size_y, size_x, 0.0f);

    if (size_x != mat.getSizeX() || size_y != mat.getSizeY()) {
        std::cout << "Error: tried to add a " << size_y << "x" << size_x <<
        " matrx to a " << mat.getSizeY() << "x" << mat.getSizeX() << " matrix" << std::endl;

        return temp;
    };

    for (unsigned int j = 0; j < size_y; j++)
        for (unsigned int i = 0; i < size_x; i++)
            temp.setVal(j, i, values[j][i] + mat.getVal(j, i));

    return temp;
};

//---------------------------------------------
// multiplication
Matrix Matrix::multiplyBy(float val) {
    // init temp matrix
    Matrix temp(size_y, size_x);

    // do the matrix multiplication
    for (unsigned int j = 0; j < size_y; j++)
        for (unsigned int i = 0; i < size_x; i++)
            temp.setVal(j, i, values[j][i] * val);

    return temp;
};

Matrix Matrix::multiplyBy(Matrix mat) {
    // init temp matrix
    Matrix temp(size_y, mat.getSizeX(), 0.0f);

    // size verification
    if (size_x != mat.getSizeY() || size_y != mat.getSizeX()) {
        std::cout << "Error: tried to multiply a " << size_y << "x" << size_x <<
        " matrx by a " << mat.getSizeY() << "x" << mat.getSizeX() << " matrix" << std::endl;

        return temp;
    };

    // the matrix multiplication
    for (unsigned int i = 0; i < size_x; i++) {
        Matrix temp1(size_y, mat.getSizeX());

        for (unsigned int j = 0; j < size_y; j++)
            for (unsigned int k = 0; k < mat.getSizeX(); k++)
                temp1.setVal(j, k, values[j][i] * mat.getVal(i, k));

        temp = temp.add(temp1);
    };

    return temp;
};
