Algoritmo NumerosImpares
	centinela <- Verdadero
	contadorImpares <- 0
	Repetir
		Escribir "Ingrese el n�mero impar: "
		Leer num
		Si (num mod 2=0) Entonces
			centinela <- Falso
		SiNo
			contadorImpares <- contadorImpares + 1
		FinSi
	Mientras Que (centinela)
	Escribir "La cantidad de n�meros impares le�dos es: ", contadorImpares
FinAlgoritmo
