/* Trabalho 1 de Cálculo Numérico - SME0104
 * Professor: Murilo Francisco Tomé
 * 
 * Lucas Alexandre Soares	9293265
 * Letícia Rina Sakurai		9278010
 * Matheus Henrique Soares	8066349
 *
 * Método de Gauss-Seidel para solução de sistemas
 * Arquivo de implementação do método
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "gauss_seidel.h"

double *SolveGaussSeidel(double **mat, double *rhs, int n, 
						double epsilon, int max_iterations, double *error){

	int iter, i, j;
	double _error = 0;
	double sum;
	double *res = (double *) calloc(sizeof(double), n); 
	double *prev = (double *) calloc(sizeof(double), n); // X(0) assumed to be 0
	
	/* Norm variables */
	double max;
	double aux;
	double *norm = (double *) malloc(sizeof(double)*n);

	for(iter = 0; iter < max_iterations; iter++){
		
		// Compute iteration
		max = 0;
		for(i = 0; i < n; i++){

			sum = 0;

			for(j = 0; j < n; j++){
				if(i != j) {
					sum += mat[i][j]*prev[j];
				}
			}

			res[i] = (rhs[i] - sum)/mat[i][i];
			
			/* Calculate infinity norm here for performance */
			norm[i] = res[i] - prev[i]; // For infinity norm calculation
			aux = fabs(norm[i]);
			max = (aux > max) ? aux : max;
		}

		// Acceptable error
		// _error = InfinityNorm(norm, n);
		_error = max;
		if(_error < epsilon) {
			printf("Acceptable error reached.\n");
			break;
		}

		// Update previous values
		memcpy(prev, res, sizeof(double)*n);
	}
	if(iter >= max_iterations) printf("Max iterations exceeded.\n");

	// If user passed a value to error, return calculated error
	if(error != NULL)
		*error = _error;

	free(prev);
	free(norm);

	return res;
}

double InfinityNorm(double *v, int n){
	
	int i;
	double max = -1;

	for(i = 0; i < n; i++){
		double aux = fabs(v[i]);
		max = (aux > max) ? aux : max;
	}

	return max;
}