Algoritmo contrasena
	centinela <- Verdadero
	Mientras centinela Hacer
		Escribir "Ingrese la contraseña: "
		Leer passw
		Si passw < 1 Entonces
			Escribir "Fin de la ejecución"
			centinela <- Falso
		SiNo
			Si contraseña >= 10^9 Entonces
				Escribir "La contraseña tiene más de 10 dígitos"
			Sino 
				exponente <- 0
				nuevoPassw <- 0
				Mientras passw > 0 Hacer
					Si passw < 10 y passw > 0 Entonces
						digito1 <- 0 
						digito1 <- passw mod 10;
						passw <- trunc(passw/10)
					Sino 
						digito1 <- passw mod 10
						passw <- trunc(passw/10)
						digito2 <- passw mod 10
						passw <- trunc(passw/10)
					FinSi
					//digitos en binario
					exponente1 <- 0
					exponente2 <- 4
					cifra <- 0
					Mientras digito1 > 0 Hacer
						d1 <- digito1 mod 2
						digito1 <- trunc(digito1 / 2)
						Si d1 = 1 Entonces
							cifra <- cifra + 2^exponente1
						FinSi
						exponente1 <- exponente1 + 1
					FinMientras
					Mientras digito2 > 0 Hacer
						d2 <- digito2 mod 2
						digito2 <- trunc(digito2 / 2)
						Si d2 = 1 Entonces
							cifra <- cifra + 2^exponente2
						FinSi
						exponente2 <- exponente2 + 1
					FinMientras
					nuevoPassw <- nuevoPassw + cifra * 10^exponente
					Si cifra > 99 Entonces
						exponente <- exponente + 3
					Sino 
						exponente <- exponente + 2
					FinSi
					Escribir "La contraseña nueva es: ", nuevoPassw
				FinMientras
				
			FinSi
		FinSi
	FinMientras
	
FinAlgoritmo
