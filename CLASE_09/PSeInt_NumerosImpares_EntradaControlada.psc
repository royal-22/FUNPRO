Algoritmo NumerosImpares
	centinela <- Verdadero
	contadorImpares <- 0
	Mientras (centinela) Hacer
		Escribir "Ingrese el n�mero impar: "
		Leer num
		Si (num mod 2=0) Entonces
			centinela <- Falso
		SiNo
			contadorImpares <- contadorImpares + 1
		FinSi
	FinMientras
	Escribir "La cantidad de n�meros impares le�dos es: ", contadorImpares
FinAlgoritmo
