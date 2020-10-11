#include "Matrix.hpp"

const unsigned int MAT_SIZE_Y = 2;
const unsigned int MAT_SIZE_X = 3;

int main() {
    //-------------------------------------------------
	std::cout << "----------------------------------" << std::endl;
    // mat 1
    Matrix A(MAT_SIZE_Y, MAT_SIZE_X);

    A.setVal(0, 0, 1.0f);
    A.setVal(0, 1, 2.0f);
    A.setVal(0, 2, 3.0f);
    A.setVal(1, 0, 4.0f);
    A.setVal(1, 1, 5.0f);
    A.setVal(1, 2, 6.0f);
	
    std::cout << "A is a "<< A.getSizeX() << "x" << A.getSizeY() << " matrix."<< std::endl;
    std::cout << A.toStr() << std::endl;
	
    // A * 5
	A = A.multiplyBy(5.0f);

    std::cout << "multiplying A by 5: " << std::endl;
    std::cout << A.toStr() << std::endl;

    //-------------------------------------------------
	std::cout << "----------------------------------" << std::endl;
    // mat 2
    Matrix B(A.getSizeX(), A.getSizeY(), 1.0f);

    std::cout << "B is a "<< B.getSizeX() << "x" << B.getSizeY() << " matrix."<< std::endl;
    std::cout << B.toStr() << std::endl;

    //-------------------------------------------------
	std::cout << "----------------------------------" << std::endl;

    // A * B
    Matrix C = A.multiplyBy(B);
	
    std::cout << "A * B is a "<< C.getSizeX() << "x" << C.getSizeY() << " matrix."<< std::endl;
    std::cout << C.toStr() << std::endl;
	
	C = C.getTranspose();
	std::cout << "A * B transpose is a "<< C.getSizeX() << "x" << C.getSizeY() << " matrix."<< std::endl;
	std::cout << C.toStr() << std::endl;


    return 0;
}
