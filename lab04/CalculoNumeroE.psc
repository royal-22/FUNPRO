Algoritmo CalculoNumeroE
	i <- 0
	suma <- 0
	factorial <- 1
	Mientras i<10 Hacer
		Si i = 0 Entonces
			suma <- suma + 1
		Sino 
			factorial <- factorial * i
			suma <- suma + 1 / factorial
			Escribir i, "  ", factorial
		FinSi
		i <- i + 1
	FinMientras
	Escribir "suma = ", suma
FinAlgoritmo
