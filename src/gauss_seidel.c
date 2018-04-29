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
#include <math.h>

#include "gauss_seidel.h"

double *SolveGaussSeidel(double **mat, double *solution, int n, 
						double epsilon, int max_iterations){

	int iter;
	double *res = (double *) malloc(sizeof(double)*n);

	for(iter = 0; iter < max_iterations; iter++){
		
		// Compute iteration


		// Acceptable error
		if(InfinityNorm(res, n) < epsilon) break;
	}

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