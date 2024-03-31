# MatikaApplication
Math Kernel for Advanced Computational Geometry and Graph Theory

# The repository contains the basic implementation of math kernel that multiplies two matrices and transposes a matrix

Salient features of the Matrix Kernel


- The math kernel is a header only implementation
- The matrix is implemented for INT, FLOAT, DOUBLE, LONG INT, LONG DOUBLE, and for COMPLEX numbers of the previously mentioned types.
- The operations throws exceptions with appropriate error messages. This is to keep up with modern designs when the returned error message/code alone is not sufficient.
- A **lazy matrix multiplication schema is implemented**, for rectangular (non-square) multiplications for matrices that are called using operator*() on more than 2 matrices

The Kwrnel uses dynamic programming technique to find that couples of the matrices in case of more than 2 multiplications, to find out the associative multiplication that can be achieved in lesser multiplications. The d_vals vector stores the minimum number of multiplication. The K matrix is used to find the best associations of the matrices. The matrix multiplication is lazy. evaluate() method is called only when needed (to query the element or when getting the data vector from the matrix)



- The internal data that the matrix uses is a 1-d vector and not 2d.
- The transpose of the matrix is implemented by setting a transpose flag true. **No data is moved or copied when transpose is requested. Just that the way the vector<numbers> is read is changed.** The getMatrixTransposeIndex() is called when the flag is unset. The function getMatrix2RowVectorIndex() is called when the transpose is requested. In any case, the data is not shifted or rotated or transposed in real sense. This flag m_Transposed is part of the state of the matrix object

An honest try is made to run the matrix multiplication and transpose in command line, like MATLAB or SCILAB. The executable for that is **CommandLineMatrixTest**

Note: Please feel free to modify the source files

**How to build the source in Windows**

- Checkout / download the files. Open the solution file in Windows Visual Studio MatikaApplication.sln and run build all

**Directions to run the command line tool**

The operation this supports are 
- **Matrix read from the standard input** (console)
- Statement > **a= int 2,3,0,1,2,3,4,5;** // reads and assigns matrix of size 2X3 and elements 0 1 2 3 4 5 in row read fashion like 
  0 1 2
  3 4 5
  int can be float double long_int or long_double
  In the case of complex numbers the input can be assigned as 
  **a= complex_int 2,3, (0,1), (2,3), (4,5), (6,7), (8,9), (10,10)**
  **a** is the name of the matrix ( treated as variable)
  
  
- **Matrix read from file**
Matrix can also be read from the file. The only difference is the file shall contain the data as above, but not the variable name
The file entry is as follows 
**complex_double 4,3,3,0,1,1,3,6,2
,3,0,9,7,8,3,1,7,
8,0,4,5,6,1,0,3,4;**
The above data in a file has complex_double

The matrix shall be read using the command **a=C:\Users\parth\source\repos\braincorp\LAKernel\LAKernel\int_file_10_10_file.txt**

- **Multiplication**
For the matrices already read, say a and b,
the multiplication can be executed as **z=a * b**
or **z=a * b  * c * d** if all the four matrices are defined


**- Transform**

Enter **a^** . It displays the transforms of **a**
Enter **b = a^** . It computes the transform of **a** and stores in **b**


**Assignment statements of the following types**

**a=b** is a simple assignment statement


**- Display**
   
**a** (enter)
**b** (enter)

displays the matrix at the console


