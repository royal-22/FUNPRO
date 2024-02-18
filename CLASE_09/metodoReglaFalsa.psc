Algoritmo metodoReglaFalsa
	Escribir "Ingrese los coeficientes: "
	Leer coeficienteA, coeficienteB, coeficienteC, coeficienteD
	Escribir "Ingrese el error máximo: "
	Leer errorMaximo
	Escribir "Ingrese el intervalo [a, b]: "
	Leer a, b 
	
	Si errorMaximo <= 0.1 Entonces
		Si a < b Entonces
			fA <- coeficienteA * a^3 + coeficienteB * a^2 + coeficienteC * a + coeficienteD
			fB <- coeficienteA * b^3 + coeficienteB * b^2 + coeficienteC * b + coeficienteD
			
			Si (fA > 0 y fB < 0) o (fB > 0 y fA < 0) Entonces
				Escribir "Iteración       a           b       f(a)      f(b)     c       f(c)     error"
				iteracion <- 0
				centinela <- Verdadero 
				Mientras (centinela) Hacer
					iteracion <- iteracion + 1
					fA <- coeficienteA * a^3 + coeficienteB * a^2 + coeficienteC * a + coeficienteD
					fB <- coeficienteA * b^3 + coeficienteB * b^2 + coeficienteC * b + coeficienteD
					c <- a - fA * (b - a) / (fB - fA)
					fC <- coeficienteA * c^3 + coeficienteB * c^2 + coeficienteC * c + coeficienteD
					
					error <- abs(fA - fC)
					Escribir iteracion, "     ", a, "      ", b, "     ", fA, "     ", fB, "     ", c, "   ",fC,  "   ", error 
					Si (fC > 0 y fA < 0) o (fA > 0 y fC < 0) Entonces
						b <- c
					Sino 
						a <- c
					FinSi
					
					Si error < errorMaximo Entonces
						centinela <- Falso
					FinSi
				FinMientras
				Escribir "La raíz calculada es ", c, ", con un error de ", error, " y en ", iteracion, " iteraciones."
			Sino 
				Escribir "f(a) y f(b) no tienen signos diferentes, por lo tanto no se puede hallar una raíz para la ecuación en el intervalo ingresado"
			FinSi
		Sino 
			Escribir "Los valores del intervalo no son válidos"
		FinSi
	Sino 
		Escribir "El valor del error no es válido"
	FinSi
	
	
FinAlgoritmo
