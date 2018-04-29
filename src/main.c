/* Trabalho 1 de Cálculo Numérico - SME0104
 * Professor: Murilo Francisco Tomé
 * 
 * Lucas Alexandre Soares	9293265
 * Letícia Rina Sakurai		9278010
 *
 * Método de Gauss-Siedel para solução de sistemas
 */

#include <stdio.h>
#include <stdlib.h>
#include "gauss_seidel.h"

void usage(char *progname){
	printf("Usage: %s [filename].\n", progname);
}

int main(int argc, char *argv[]){

	if(argc == 1){
		// Get input from stdin
	} else if(argc == 2){
		// Get input from file argument
	} else {
		usage(argv[0]);
		exit(1);
	}

	// Call method

	// Print result

	return 0;
}