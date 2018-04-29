/* Trabalho 1 de Cálculo Numérico - SME0104
 * Professor: Murilo Francisco Tomé
 * 
 * Lucas Alexandre Soares	9293265
 * Letícia Rina Sakurai		9278010
 *
 * Método de Gauss-Seidel para solução de sistemas
 * Arquivo principal do programa
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "gauss_seidel.h"

void usage(char *progname){
	printf("Usage: %s [filename].\n", progname);
}

int main(int argc, char *argv[]){

	FILE *input = stdin;
	FILE *output = stdout;
	int i, j;
	int n = 0;
	double **matrix = NULL;		// Matrix representing system equations
	double *rhs = NULL;			// System right hand side vector
	double *res = NULL;			// result
	double epsilon = 0;
	double error;
	int max_iterations = 0;

	// if(argc == 1) Get input from stdin
	if(argc == 2){
		
		// Get input from file argument
		input = fopen(argv[1], "r");
		
		// Supress messages asking for input if a file was given as argument
		output = fopen("/dev/null", "w");
		
		if(!input){
			fprintf(stderr, "Error: file not found.\n");
			exit(1);
		}

		// No /dev/null found or some other error, just print the messages :(
		if(!output) output = stdout;

	} else if(argc > 2){
		printf("Unknown options.\n");
		usage(argv[0]);
		exit(1);
	}

	// Get and process input
	fprintf(output, "Matrix order: ");
	fscanf(input, "%d", &n);

	matrix = (double **) malloc(sizeof(double *)*n);
	rhs = (double *) malloc(sizeof(double)*n);

	fprintf(output, "System matrix: ");
	for(i = 0; i < n; i++){

		matrix[i] = (double *) malloc(sizeof(double)*n);
		for(j = 0; j < n; j++){
			fscanf(input, "%lf", &matrix[i][j]);
		}
	}

	fprintf(output, "Solution vector: ");
	for(i = 0; i < n; i++)
		fscanf(input, "%lf", &rhs[i]);

	fprintf(output, "Epsilon: ");
	fscanf(input, "%lf", &epsilon);

	fprintf(output, "Max iterations: ");
	fscanf(input, "%d", &max_iterations);

	// Call method
	clock_t t1 = clock();
	res = SolveGaussSeidel(matrix, rhs, n, epsilon, max_iterations, &error);
	clock_t t2 = clock();

	// Print result
	printf("Result = (");
	for(i = 0; i < n-1; i++)
		printf("%lf, ", res[i]);
	printf("%lf)\n", res[i]);

	printf("Result error: %.10lf.\n", error);
	printf("Execution time: %lf.\n", (double) (t2-t1)/(CLOCKS_PER_SEC));

	// Free memory and close streams
	if(argc == 2){
		fclose(input);
		if(output != stdout) fclose(output);
	}

	for(i = 0; i < n; i++)
		free(matrix[i]);
	free(matrix);
	free(rhs);
	if(res) free(res);

	return 0;
}