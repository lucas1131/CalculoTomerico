/* Trabalho 1 de Cálculo Numérico - SME0104
 * Professor: Murilo Francisco Tomé
 * 
 * Lucas Alexandre Soares	9293265
 * Letícia Rina Sakurai		9278010
 *
 * Método de Gauss-Seidel para solução de sistemas não lineares
 * Arquivo principal do programa
 */

#include <stdio.h>
#include <stdlib.h>
#include "gauss_seidel.h"

void usage(char *progname){
	printf("Usage: %s [filename].\n", progname);
}

int main(int argc, char *argv[]){

	File *input = NULL;
	File *output = NULL;
	int i, j;
	int n = 0;
	double **matrix = NULL;		// Matrix representing system equations
	double *solution = NULL;	// System solution vector (right hand side)
	double *res = NULL;			// result
	double epsilon = 0;
	int max_iterations = 0;

	// Get input from stdin
	if(argc == 1) input = stdin;
	else if(argc == 2){
		
		// Get input from file argument
		input = fopen(argv[2], "r");
		
		// Supress messages asking for input if a file was given as argument
		output = fopen("/dev/null", "w");
		
		if(!input){
			fprintf(stderr, "Error: file not found.\n");
			exit(1).
		}

		// No /dev/null found or some other error, just print the messages :(
		if(!output) output = stdout;

	} else {
		printf("Unknown options.\n");
		usage(argv[0]);
		exit(1);
	}

	// Get and process input
	fprintf(output, "Matrix order: ");
	fscanf(input, "%d", &n);

	matrix = (double **) malloc(sizeof(double *)*n);
	solution = (double *) malloc(sizeof(double)*n);

	fprintf(output, "System matrix: ");
	for(i = 0; i < n; i++){

		matrix[i] = (double *) malloc(sizeof(double)*n);
		for(j = 0; j < n; j++){
			fscanf(input, "%lf", &matrix[i][j]);
		}
	}

	fprintf(output, "Solution vector: ");
	for(i = 0; i < n; i++)
		fscanf(input, "%lf", &solution[i]);

	fprintf(output, "Epsilon: ");
	fscanf(input, "%lf", &epsilon);

	fprintf(stderr, "Max iterations: ");
	fscanf(input, "%d", &max_iterations);

	// Call method

	// Print result

	// Free memory and close streams
	if(argc == 2){
		fclose(input);
		if(output != stdout) fclose(output);
	}

	for(i = 0; i < n; i++)
		free(matrix[i]);
	free(matrix);
	free(solution);
	if(res) free(res);

	return 0;
}