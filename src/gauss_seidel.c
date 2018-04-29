/* Trabalho 1 de Cálculo Numérico - SME0104
 * Professor: Murilo Francisco Tomé
 * 
 * Lucas Alexandre Soares	9293265
 * Letícia Rina Sakurai		9278010
 *
 * Método de Gauss-Seidel para solução de sistemas
 * Arquivo de implementação do método
 */

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "gauss_seidel.h"

double *SolveGaussSeidel(double **mat, double *rhs, int n, 
						double epsilon, int max_iterations){

	int iter, i, j;
	double sum1, sum2;
	double *res = (double *) calloc(sizeof(double), n); 
	double *prev = (double *) calloc(sizeof(double), n); // X(0) assumed to be 0

	for(iter = 0; iter < max_iterations; iter++){
		
		// Compute iteration
		for(i = 0; i < n; i++){

			sum1 = 0;
			for(j = 0; j < i; j++)
				sum1 += mat[i][j]*res[j];

			sum2 = 0;
			for(j = i; j < n; j++)
				sum2 += mat[i][j]*prev[j];

			res[i] = (rhs[i] - sum1 - sum2)/mat[i][i];
		}

		// Acceptable error
		if(InfinityNorm(res, n) < epsilon) break;
	}

	free(prev);

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