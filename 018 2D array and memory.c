// 2D arrays and 2D array memory allocation
#include <stdio.h>
#include <stdlib.h>

// 2D array using two separate typedefs
typedef char columns[2]; // columns
typedef columns twod[4]; // 4 rows of 2 columns

int array2D[2][2] = {
						{1,2},
						{3,4}
					};

// This is just so it will fit onscreen
#define PARRAY(R, C, ARRAY) \
					for (r = 0; r < R; r++) { \
						for (c = 0; c < C; c++) { \
							printf("%d ", ARRAY); \
						}                         \
					}

int main() {
	int r, c, j = 0;
	twod two_d;
	for (r = 0; r < 4; r++) {
		for (c = 0; c < 2; c++) {
			two_d[r][c] = j++;
		}
	}
	PARRAY(4, 2, two_d[r][c]);
	printf("\n");
	PARRAY(2, 2, array2D[r][c]);
	// 2D memory allocation for 2D array. Size can be decided at runtime
	int rows;
	int cols;
	printf("\nRows: Columns: ");
	scanf("%d %d", &rows, &cols);
	int ** ppn = (int**) malloc(rows * sizeof(int*)); // allocate rows
	for (r = 0; r < rows; r++) {
		ppn[r] = (int*) malloc(cols * sizeof(int));   // each row
	}
	j = 0;
	for (r = 0; r < rows; r++) {
		for (c = 0; c < cols; c++) {
			ppn[r][c] = j++;
		}
	}
	PARRAY(rows, cols, ppn[r][c]); // r for rows c for columns
	// free memory
	for (r = 0; r < rows; r++) {
		free(ppn[r]);              // each row
	}
	free(ppn);                     // top level
	return 0;
}
