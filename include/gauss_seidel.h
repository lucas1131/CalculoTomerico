/* Trabalho 1 de Cálculo Numérico - SME0104
 * Professor: Murilo Francisco Tomé
 * 
 * Lucas Alexandre Soares	9293265
 * Letícia Rina Sakurai		9278010
 *
 * Método de Gauss-Seidel para solução de sistemas
 * Arquivo de cabeçalho do método
 */

#ifndef _GAUSS_SEIDEL_H_
#define _GAUSS_SEIDEL_H_

double *SolveGaussSeidel(double **mat, double *solution, int n, 
						double epsilon, int max_iterations);
double InfinityNorm(double *v, int n);

#endif