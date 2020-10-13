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

    //-------------------------------------------------
    std::cout << "----------------------------------" << std::endl;
    Matrix D = Matrix(3, 3);
    for (unsigned int j = 0; j < C.getSizeY(); j++)
        for (unsigned int i = 0; i < C.getSizeX(); i++)
            D.setVal(j, i, j * C.getSizeY() + i);

    D.setVal(0, 0, 1.0f);
    std::cout << "D is a "<< D.getSizeY() << "x" << D.getSizeX() << " matrix."<< std::endl;
    std::cout << D.toStr() << std::endl;

    float determinant_D = D.getDeterminant();
    std::cout << "determinant(D) is: "<< std::endl;
    std::cout << determinant_D << std::endl << std::endl;

    // adjugate D
    Matrix adjugate_D = D.getAdjugate();
    std::cout << "D adjugate is a "<< adjugate_D.getSizeY() << "x" << adjugate_D.getSizeX() << " matrix."<< std::endl;
    std::cout << adjugate_D.toStr() << std::endl;

    // inverse D
    Matrix inverse_D = D.inverse();
    std::cout << "D inverse is a "<< inverse_D.getSizeY() << "x" << inverse_D.getSizeX() << " matrix."<< std::endl;
    std::cout << inverse_D.toStr() << std::endl;

    // D * inverse D
    Matrix D_recalculated = inverse_D * D;
    std::cout << "inv(D) x D is a "<< D_recalculated.getSizeY() << "x" << D_recalculated.getSizeX() << " matrix."<< std::endl;
    std::cout << D_recalculated.toStr() << std::endl;

    //-------------------------------------------------
    std::cout << "----------------------------------" << std::endl;

    // 10 by 10 identity matrix
    Matrix E = Matrix::identity(10);
    std::cout << "E is a "<< E.getSizeY() << "x" << E.getSizeX() << " matrix."<< std::endl;
    std::cout << E.toStr() << std::endl;


    return 0;
};
