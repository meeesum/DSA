#include <iostream>
#include "sparseMatrix.h"
#include "sparseMatrix.cpp"
using namespace std;
int main(){
    SparseMatrixLinkedList<int> mat1;
    mat1.Insert(0, 1, 5);
    mat1.Insert(1, 2, 10);
    mat1.Insert(2, 0, 15);

    SparseMatrixLinkedList<int> mat2;
    mat2.Insert(0, 1, 3);
    mat2.Insert(1, 2, 7);
    mat2.Insert(2, 1, 8);

    // mat1.display();
    SparseMatrixLinkedList<int> result = mat1.addSparseMatrices(mat1, mat2);

   cout << "Resultant Sparse Matrix" <<endl;
    result.display();
    return 0;
}