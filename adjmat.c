#include "adjmat.h"
#include "topsort.h"
#include <stdio.h>
#include <stdlib.h>


void adjacency_matrix_in() {

	FILE *file_in;
	file_in = fopen("in.txt", "r");
	
	int iterator_1, iterator_2, number_matrix;
	
	fscanf(file_in, "%d", &number_matrix);

	int ** a = (int**)malloc(number_matrix * sizeof(int*));

	
	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
		a[iterator_1] = (int*)malloc(number_matrix * sizeof(int));
	}

	

	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
		for (iterator_2 = 0; iterator_2 < number_matrix; iterator_2++)
			fscanf(file_in, "%d", &a[iterator_1][iterator_2]);
	}

	topological_sort(number_matrix, a);

	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
		free(a[iterator_1]);
	}
	free(a);
}
