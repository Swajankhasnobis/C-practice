// C++ program for Sparse Matrix Representation
// using Array
#include<stdio.h>

int main()
{
	// Assume 4x5 sparse matrix
	int sparseMatrix[4][5] =
	{
		{0 , 0 , 3 , 0 , 4 },
		{0 , 0 , 5 , 7 , 0 },
		{0 , 0 , 0 , 0 , 0 },
		{0 , 2 , 6 , 0 , 0 }
	};

	int size = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			if (sparseMatrix[i][j] != 0)
				size++;

	// number of columns in compactMatrix (size) must be
	// equal to number of non - zero elements in
	// sparseMatrix
	int compactMatrix[3][size];

	// Making of new matrix
	int k = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			if (sparseMatrix[i][j] != 0)
			{
				compactMatrix[0][k] = i;
				compactMatrix[1][k] = j;
				compactMatrix[2][k] = sparseMatrix[i][j];
				k++;
			}

	for (int i=0; i<3; i++)
	{
		for (int j=0; j<size; j++)
			printf("%d ", compactMatrix[i][j]);

		printf("\n");
	}
	return 0;
}


#include <stdio.h>
#include <stdlib.h>

// Define the structure to represent a sparse matrix
typedef struct {
    int row;
    int col;
    int value;
} Element;

typedef struct {
    int rows;
    int cols;
    int numElements;
    Element *elements;
} SparseMatrix;

// Function to convert a sparse matrix to a non-sparse matrix
void convertToDense(SparseMatrix sparse, int **dense) {
    // Initialize the dense matrix with zeros
    for (int i = 0; i < sparse.rows; i++) {
        for (int j = 0; j < sparse.cols; j++) {
            dense[i][j] = 0;
        }
    }

    // Fill the dense matrix with the non-zero elements from the sparse matrix
    for (int i = 0; i < sparse.numElements; i++) {
        int row = sparse.elements[i].row;
        int col = sparse.elements[i].col;
        int value = sparse.elements[i].value;
        dense[row][col] = value;
    }
}

int main() {
    // Example sparse matrix with 3 rows and 3 columns, 4 non-zero elements
    SparseMatrix sparse;
    sparse.rows = 3;
    sparse.cols = 3;
    sparse.numElements = 4;

    // Allocate memory for the elements of the sparse matrix
    sparse.elements = (Element *)malloc(sparse.numElements * sizeof(Element));

    // Define the non-zero elements
    sparse.elements[0].row = 0;
    sparse.elements[0].col = 0;
    sparse.elements[0].value = 1;

    sparse.elements[1].row = 0;
    sparse.elements[1].col = 2;
    sparse.elements[1].value = 2;

    sparse.elements[2].row = 1;
    sparse.elements[2].col = 1;
    sparse.elements[2].value = 3;

    sparse.elements[3].row = 2;
    sparse.elements[3].col = 0;
    sparse.elements[3].value = 4;

    // Allocate memory for the dense matrix
    int **dense = (int **)malloc(sparse.rows * sizeof(int *));
    for (int i = 0; i < sparse.rows; i++) {
        dense[i] = (int *)malloc(sparse.cols * sizeof(int));
    }

    // Convert the sparse matrix to a dense matrix
    convertToDense(sparse, dense);

    // Print the dense matrix
    printf("Dense matrix:\n");
    for (int i = 0; i < sparse.rows; i++) {
        for (int j = 0; j < sparse.cols; j++) {
            printf("%d ", dense[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    free(sparse.elements);
    for (int i = 0; i < sparse.rows; i++) {
        free(dense[i]);
    }
    free(dense);

    return 0;
}

