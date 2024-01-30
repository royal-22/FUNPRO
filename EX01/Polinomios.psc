Algoritmo Polinomios
	Escribir "Ingrese los coeficientes de la forma (coefA)x^expA + (coefB)x^expB + (coefC)x^expC: "
	Escribir "Ingrese el coeficiente A y su exponente: "
	Leer coeficienteA, exponenteA
	Escribir "Ingrese el coeficiente B y su exponente: "
	Leer coeficienteB, exponenteB
	Escribir "Ingrese el coeficiente C y su exponente: "
	Leer coeficienteC, exponenteC
	
	exponentesPositivos <- exponenteA >= 0 y exponenteB >= 0 y exponenteC >= 0
	exponentesDiferentes <- exponenteA <> exponenteB y exponenteB <> exponenteC y exponenteC <> exponenteA
	
	Si exponentesDiferentes y exponentesPositivos Entonces
		// calcular polinomio
		Escribir "Ingrese el valor de x para evaluar el polinomio : "
		Leer x
		Si coeficienteA <> 0 o coeficienteB <> 0 o coeficienteC <> 0 Entonces
			resultado <- coeficienteA * x^exponenteA + coeficienteB * x^exponenteB + coeficienteC * x^exponenteC
			exponenteAMayor <- (exponenteA > exponenteB y exponenteA > exponenteC y coeficienteA <> 0)
			exponenteBMayor <- (exponenteB > exponenteA y exponenteB > exponenteC y coeficienteB <> 0)
			exponenteCMayor <- (exponenteC > exponenteA y exponenteC > exponenteA y coeficienteC <> 0)
			
			Si exponenteAMayor Entonces
				grado <- exponenteA
			Sino 
				Si exponenteBMayor Entonces
					grado <- exponenteB
				Sino 
					grado <- exponenteC
				FinSi
			FinSi
			Escribir "El valor númerico del polinomio es: ", resultado
			Escribir "El polinomio es de grado: ", grado
		Sino 
			Escribir "El valor númerico del polinomio es 0"
			Escribir "Todos los coeficientes del polinomio son cero, no se puede calcular su grado"
		FinSi
		completo <- (exponenteA = 1 o exponenteB = 1 o exponenteC = 1) y (exponenteA = 2 o exponenteB = 2 o exponenteC = 2) y (exponenteA = 3 o exponenteB = 3 o exponenteC = 3)
		Si completo Entonces
			Escribir "Es un polinomio completo"
		Sino 
			Escribir "Es un polinomio incompleto"
		FinSi
	Sino 
		Si no exponentesDiferentes Entonces
			Escribir "Los exponentes deben ser diferentes"
		Sino 
			Escribir "Los exponentes no pueden ser números negativos"
		FinSi
	FinSi
	
FinAlgoritmo
