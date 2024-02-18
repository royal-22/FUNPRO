Algoritmo NumerosImpares
	centinela <- Verdadero
	contadorImpares <- 0
	Repetir
		Escribir "Ingrese el número impar: "
		Leer num
		Si (num mod 2=0) Entonces
			centinela <- Falso
		SiNo
			contadorImpares <- contadorImpares + 1
		FinSi
	Mientras Que (centinela)
	Escribir "La cantidad de números impares leídos es: ", contadorImpares
FinAlgoritmo
