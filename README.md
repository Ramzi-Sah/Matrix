### matrix manipulation class
a simple C++ matrix manipulation class

## how to use
```c++
Matrix matrix_A = Matrix(3, 2, 1.0f);
```
this will create a 3 by 2 matrix with a 1 on all its values

```c++
Matrix matrix_B = Matrix(2, 3);
```
this will create a 3 by 5 matrix

you can set its values with the setVal(index_j, index_i, value) method like this
```c++
matrix_B.setVal(0, 0, 1.0f);
matrix_B.setVal(0, 1, 2.0f);
matrix_B.setVal(0, 2, 3.0f);
matrix_B.setVal(1, 0, 4.0f);
matrix_B.setVal(1, 1, 5.0f);
matrix_B.setVal(1, 2, 6.0f);
```

you can multiply a matrix by a value like this
```c++
matrix_B = matrix_B.multiplyBy(5.0f);
```

you can multiply two matrices by a value like this
```c++
matrix_B = matrix_B.multiplyBy(matrix_A);
```

you can get a matrix's transpose like this
```c++
matrix_B = matrix_B.getTranspose();
```

you can get a matrix's size with these two methods getSizeX/getSizeY like this
```c++
unsigned int matrix_B_sizeX = matrix_B.getSizeX();
unsigned int matrix_B_sizeY = matrix_B.getSizeY();
```

you can convert a matrix to a string like this
```c++
std::string matrix = matrix_B.toStr();
std::cout << matrix << std::endl;
```