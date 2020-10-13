#include "Matrix.hpp"

int main() {
    //-------------------------------------------------
    // mat 1
    Matrix A(2, 3);

    A.setVal(0, 0, 1.0f);
    A.setVal(0, 1, 2.0f);
    A.setVal(0, 2, 3.0f);
    A.setVal(1, 0, 4.0f);
    A.setVal(1, 1, 5.0f);
    A.setVal(1, 2, 6.0f);

    std::cout << "A is a "<< A.getSizeY() << "x" << A.getSizeX() << " matrix."<< std::endl;
    std::cout << A.toStr() << std::endl;

    // A * 5
	A = A.multiplyBy(5.0f);

    std::cout << "multiplying A by 5: " << std::endl;
    std::cout << A.toStr() << std::endl;

    //-------------------------------------------------
	std::cout << "----------------------------------" << std::endl;

    // mat 2
    Matrix B(A.getSizeX(), A.getSizeY(), 1.0f);

    std::cout << "B is a "<< B.getSizeY() << "x" << B.getSizeX() << " matrix."<< std::endl;
    std::cout << B.toStr() << std::endl;

    //-------------------------------------------------
	std::cout << "----------------------------------" << std::endl;

    // A * B
    Matrix C = A.multiplyBy(B);

    std::cout << "A * B is a "<< C.getSizeY() << "x" << C.getSizeX() << " matrix."<< std::endl;
    std::cout << C.toStr() << std::endl;

    //-------------------------------------------------
    std::cout << "----------------------------------" << std::endl;

    // assign new C matrix
    C = Matrix(3, 3);

    for (unsigned int j = 0; j < C.getSizeY(); j++)
        for (unsigned int i = 0; i < C.getSizeX(); i++)
            C.setVal(j, i, j * C.getSizeY() + i);

    C.setVal(0, 0, 1.0f);

    std::cout << "C is a "<< C.getSizeY() << "x" << C.getSizeX() << " matrix."<< std::endl;
	std::cout << C.toStr() << std::endl;

    // transpose C
    C = C.getTranspose() + C;
	std::cout << "C' + C is a "<< C.getSizeY() << "x" << C.getSizeX() << " matrix."<< std::endl;
	std::cout << C.toStr() << std::endl;

    // calculate determinant
	float determinant = C.getDeterminant();
	std::cout << "determinant(C) is: "<< std::endl;
	std::cout << determinant << std::endl << std::endl;

    C = C * determinant;
    std::cout << "C x determinant(C) is: "<< std::endl;
    std::cout << C.toStr() << std::endl;

    C = C * Matrix(C.getSizeX(), C.getSizeY(), 2.0f);
    std::cout << "C x Matrix(2) is: "<< std::endl;
    std::cout << C.toStr() << std::endl;

    std::cout << "----------------------------------" << std::endl;
    Matrix D = Matrix::identity(10);
    std::cout << "D is a "<< D.getSizeY() << "x" << D.getSizeX() << " matrix."<< std::endl;
    std::cout << D.toStr() << std::endl;

/*
    try {
        C.setVal(44554,64546456, 50);
        std::cout << C.getVal(44554,64546456) << std::endl;
    } catch (int e) {
        std::cout << "flag" << '\n';
    }
*/

    return 0;
};
