Algoritmo NumerosImpares
	centinela <- Verdadero
	contadorImpares <- 0
	Mientras (centinela) Hacer
		Escribir "Ingrese el número impar: "
		Leer num
		Si (num mod 2=0) Entonces
			centinela <- Falso
		SiNo
			contadorImpares <- contadorImpares + 1
		FinSi
	FinMientras
	Escribir "La cantidad de números impares leídos es: ", contadorImpares
FinAlgoritmo
