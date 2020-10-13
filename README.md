# Matrix manipulation class
a simple C++ matrix manipulation class

## How to use
### Matrix declaration
you can create a matrix like this:
```c++
Matrix A = Matrix(2, 3);
```
this will create a 2 by 3 matrix.
you can set its values with the setVal(index_j, index_i, value) method like this:
```c++
A.setVal(0, 0, 1.0f);
A.setVal(0, 1, 2.0f);
A.setVal(0, 2, 3.0f);
A.setVal(1, 0, 4.0f);
A.setVal(1, 1, 5.0f);
A.setVal(1, 2, 6.0f);
```

and you can access its values with the getVal(index_j, index_i) method like this:
```c++
A.getVal(0, 2); // this will return 3.0f
```

you can access a matrix's size with these two methods getSizeX / getSizeY like this:
```c++
unsigned int A_nbr_rows = A.getSizeX(); // get number of rows (in this case 3)
unsigned int A_nbr_columns = A.getSizeY(); // get number of columns (in this case 2)
```

you can also create a matrix and set all values like this:
```c++
Matrix B = Matrix(3, 2, 2.0f);
```
this will create a 3 by 2 matrix with 2.0f on all its values.

### Matrix multiplication
you can multiply a matrix by a value like this:
```c++
A = A.multiplyBy(5.0f);
```

or simply by doing this:
```c++
A = A * 5.0f;
```

you can multiply two matrices by doing this:
```c++
Matrix C = A.multiplyBy(B);
```

this also works:
```c++
Matrix C = A * B;
```

### Usefull functions
you can get a matrix's transpose like this:
```c++
C = C.getTranspose();
```

you can convert a matrix to a string like this:
```c++
// convert matrix to string
std::string matrix = C.toStr();

// print matrix to console
std::cout << matrix << std::endl;
```

you can calculate a matrix's determinant like this:
```c++
float determinant = C.getDeterminant();
```

### Predefined Matrices
you can create an identity matrix with size x like this:
```c++
Matrix D = Matrix::identity(5); // this will create a 5 by 5 identity matrix
```
