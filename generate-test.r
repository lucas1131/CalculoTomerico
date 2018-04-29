#  
#  Trabalho 1 de Cálculo Numérico - SME0104
#  Professor: Murilo Francisco Tomé
#  
#  Lucas Alexandre Soares	9293265
#  Letícia Rina Sakurai		9278010
# 
#  Arquivo de geração de casos de teste
# 

gen_test <- function(n=50, epsilon=1e-10, itmax=1000){
	
	mat = matrix(data=rep(0, n*n), nrow=n, ncol=n)
	b = vector(mode="numeric", length=n)

	# Create matrix
	for(i in seq(n)){
		for(j in seq(n)){
			if(i == j) mat[i, j] = 4
			else if(j == i+1 || j+1 == i || j == i+3 || j+3 == i) mat[i, j] = -1
			else mat[i, j] = 0;
		}
	}

	# Create vector
	for (i in 1:n) {
		
		sum = 0
		for (j in 1:n)
			sum = sum + mat[i, j]
		
		b[i] = sum
	}

	# Write parameters to file
	
	sink(file = paste("test-n", n, ".in", sep=""), type = "output")
	cat(n, "\n")
	cat(mat, "\n")
	cat(b, "\n")
	cat(epsilon, "\n")
	cat(itmax, "\n")
	sink()
}

gen_validate_test <- function(n=50, epsilon=1e-10, itmax=1000){
	
	mat = matrix(data=rep(0, n*n), nrow=n, ncol=n)
	b = vector(mode="numeric", length=n)

	# Create matrix
	for(i in seq(n)){
		for(j in seq(n)){
			if(i == j) mat[i, j] = 4
			else if(j == i+1 || j+1 == i || j == i+3 || j+3 == i) mat[i, j] = -1
			else mat[i, j] = 0;
		}
	}

	# Create vector
	for (i in 1:n)
		b[i] = 1/i

	# Write parameters to file
	
	sink(file = paste("validate-input-n", n, ".in", sep=""), type = "output")
	cat(n, "\n")
	cat(mat, "\n")
	cat(b, "\n")
	cat(epsilon, "\n")
	cat(itmax, "\n")
	sink()
}
