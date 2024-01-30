Algoritmo IntegralesDerivadas
	Escribir "Quiere calcular la integral (I) o la derivada (D): "
	Leer opcionDI
	
	Si opcionDI = "D" o opcionDI = "d" o opcionDI = "i" o opcionDI = "I"Entonces
		existeDerivada <- Falso 
		existeIntegral <- Falso
		Escribir "Ingrese los valores k, x, n, b: "
		Leer k, x, n, b
		Si opcionDI = "I" o opcionDI = "i"  Entonces
			Escribir "Ingrese la constante: "
			Leer C
			Si k = 0 y b <> 0 Entonces
				integral <- b * x + C
				existeIntegral <- Verdadero
			Sino 
				Si k = 1 y n <> -1 Entonces
					integral <- x^(n + 1) / (n + 1) + C
					Si b <> 0 Entonces
						integral <- integral + b * x 
					FinSi
					existeIntegral <- Verdadero
				Sino 
					Si k = 1 y n = -1 Entonces
						integral <- ln(x) + C
						Si b <> 0 Entonces
							integral <- integral + b * x
						FinSi
						existeIntegral <- Verdadero
					Sino 
						Escribir "No se conoce  esta integral"
					FinSi
				FinSi
			FinSi
		Sino 
			Si k <> 0 y n = 1 y b <> 0 Entonces
				derivada <- k
				existeDerivada <- Verdadero
			Sino 
				Si k <> 0 y n <> 0 Entonces
					derivada <- k * n * x^(n-1)
					existeDerivada <- Verdadero
				Sino 
					Si k <> 0 y n = 1/2 Entonces
						derivada <- 1/(2 * rc(x))
						existeDerivada <- Verdadero
					FinSi
				FinSi
			FinSi
			Si existeDerivada Entonces
				Escribir "El valor de la derivada es: ", derivada
			Sino 
				Si existeIntegral Entonces
					Escribir "El valor de la integral es: ", integral
				FinSi
			FinSi
		FinSi
	SiNo
		Escribir "Ingrese una opción válida"
	FinSi
	
FinAlgoritmo
