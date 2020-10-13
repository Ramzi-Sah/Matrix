#include "Matrix.hpp"

Matrix::Matrix(const Matrix &mat) {
    //std::cout << "copy constructor" << std::endl;

    // set matrix size
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

    // set matrix size
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
    // set matrix size
    size_x = _sizeX;
    size_y = _sizeY;

    if (size_x == 0) size_x = 1;
    if (size_y == 0) size_y = 1;

    // dynamically allocate matrix memory
    values = (float**) malloc(sizeof(float*) * size_x * size_y);

    for (unsigned int j = 0; j < size_y; j++)
        values[j] = (float*) malloc(sizeof(float) * size_x);
};
Matrix::Matrix(unsigned int _sizeY, unsigned int _sizeX, float val) {
    // set matrix size
    size_x = _sizeX;
    size_y = _sizeY;

    if (size_x == 0) size_x = 1;
    if (size_y == 0) size_y = 1;

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
    // delete allocated memory
    for (unsigned int k = 0; k < size_y; k++)
        free(values[k]);

    free(values);
};

//---------------------------------------------
// value setters and getters
void Matrix::setVal(unsigned int index_y, unsigned int index_x, float val) {
    if (index_x >= size_x || index_y >= size_y) {
        std::cerr << "tried to set an invalid matrix value [" << index_y << "][" << index_x << "] to " << val << "." << std::endl;
        return;
    };

    values[index_y][index_x] = val;
};
float Matrix::getVal(unsigned int index_y, unsigned int index_x) {
    if (index_x >= size_x || index_y >= size_y) {
        std::cerr << "tried to access invalid matrix value [" << index_y << "][" << index_x << "]."  << std::endl;
        return 0.0f;
    };

    return values[index_y][index_x];
};

unsigned int Matrix::getSizeY() {
    return size_y;
};
unsigned int Matrix::getSizeX() {
    return size_x;
};

//---------------------------------------------
// some predefined matrices
Matrix Matrix::identity(unsigned int size) {
    Matrix identity_mat(size, size);

    // set values
    unsigned int identity_index = 0;
    for (unsigned int j = 0; j < size; j++) {
        for (unsigned int i = 0; i < size; i++) {
            if (j == identity_index && i == identity_index) {
                identity_mat.setVal(j, i, 1.0f);
            } else {
                identity_mat.setVal(j, i, 0.0f);
            };
        };
        identity_index++;
    };

    return identity_mat;
};


//---------------------------------------------
// some usefull methods
std::string Matrix::toStr() {
    // convert matrix to string
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
Matrix Matrix::getTranspose() {
    Matrix temp = Matrix(size_x, size_y);

    // transpose the matrix
    for (unsigned int j = 0; j < size_y; j++)
        for (unsigned int i = 0; i < size_x; i++)
            temp.setVal(i, j, values[j][i]);

    return temp;
};
float Matrix::getDeterminant() {
    float determinant = 0.0f;

    // size verification
    if (size_x != size_y) {
        std::cerr << "tried to calculate a " << size_y << "x" << size_x << " matrx's determinant" << std::endl;
        return determinant;
    };

    // if it is a 1x1 matrix return value
    if (size_y == 1) // size_y == size_x no need to check size_x
        return values[0][0];

    // calculate matrix determinant
    for (unsigned int j = 0; j < size_x; j++) {

        Matrix temp(size_y-1, size_x-1);
        bool flag = false;
        for (unsigned int l = 0; l < temp.getSizeX(); l++) {
            for (unsigned int k = 0; k < temp.getSizeY(); k++) {
                if (flag) {
                    temp.setVal(k, l, values[k + 1][l + 1]);
                } else if (j != l) {
                    temp.setVal(k, l, values[k + 1][l]);
                } else {
                    flag = true;
                    temp.setVal(k, l, values[k + 1][l + 1]);
                };
            };
        };

        if (j % 2 == 0) {
            determinant += values[0][j] * temp.getDeterminant();
        } else {
            determinant -= values[0][j] * temp.getDeterminant();
        };
    };

    return determinant;
};

//---------------------------------------------
// addition
Matrix Matrix::add(Matrix mat) {
    // init temp matrix
    Matrix temp(size_y, size_x, 0.0f);

    // size verification
    if (size_x != mat.getSizeX() || size_y != mat.getSizeY()) {
        std::cerr << "Error: tried to add a " << size_y << "x" << size_x <<
        " matrx to a " << mat.getSizeY() << "x" << mat.getSizeX() << " matrix" << std::endl;
        return temp;
    };

    // do the addition
    for (unsigned int j = 0; j < size_y; j++)
        for (unsigned int i = 0; i < size_x; i++)
            temp.setVal(j, i, values[j][i] + mat.getVal(j, i));

    return temp;
};
Matrix Matrix::operator+(const Matrix &mat) {
    return add(mat);
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
Matrix Matrix::operator*(const float &val) {
    return multiplyBy(val);
};

Matrix Matrix::multiplyBy(Matrix mat) {
    // init temp matrix
    Matrix temp(size_y, mat.getSizeX(), 0.0f);

    // size verification
    if (size_x != mat.getSizeY() || size_y != mat.getSizeX()) {
        std::cerr << "Error: tried to multiply a " << size_y << "x" << size_x <<
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
Matrix Matrix::operator*(const Matrix &mat) {
    return multiplyBy(mat);
};
