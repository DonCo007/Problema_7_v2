#include "topsort.h"
#include <stdio.h>

void topological_sort(int number_matrix, int **a) {

	int iterator_1, iterator_2, iterator_3, indeg[10], flag[10], count = 0;

	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
		indeg[iterator_1] = 0;
		flag[iterator_1] = 0;
	}

	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++)
		for (iterator_2 = 0; iterator_2 < number_matrix; iterator_2++)
			indeg[iterator_1] = indeg[iterator_1] + a[iterator_2][iterator_1];


	printf("\nThe topological order is: ");

	while (count < number_matrix) {
		for (iterator_3 = 0; iterator_3 < number_matrix; iterator_3++) {
			if ((indeg[iterator_3] == 0) && (flag[iterator_3] == 0)) {
				printf("%d ", (iterator_3 + 1));
				flag[iterator_3] = 1;
			}

			for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
				if (a[iterator_1][iterator_3] == 1) {
					a[iterator_3][iterator_1] = 0;
					indeg[iterator_3]--;
				}
			}
		}

		count++;
	}
}

