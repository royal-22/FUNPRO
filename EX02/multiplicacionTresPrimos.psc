Algoritmo multiplicacion
	Escribir "Ingrese el número a encontrar: "
	Leer num
	Si num < 0 Entonces
		Escribir "El número debe ser mayor que cero"
	Sino 
		Si num < 1000 Entonces
			Escribir "La cantidad de cifras del número debe ser mayor que 3"
		SiNo
			existeCombinacionValida <- 0
			Escribir "La cantidad de cifras que tiene el número ", num, " es:"
			Leer cantCifras
			i <- 2
			centinela1 <- Verdadero
			Mientras centinela1 Hacer
				j <- 2
				centinela2 <- Verdadero
				Mientras centinela2 Hacer
					k <- 2
					centinela3 <- Verdadero
					Mientras centinela3 Hacer
						Si k * j * i = num Entonces
							// Validar si son primos
							divisor <- 1
							contDivisoresK <- 0
							contDivisoresJ <- 0
							contDivisoresI <- 0
							Mientras divisor <= k o divisor <= j o divisor <= i Hacer
								Si k MOD divisor = 0 Entonces
									contDivisoresK <- contDivisoresK + 1
								FinSi
								Si j MOD divisor = 0 Entonces
									contDivisoresJ <- contDivisoresJ + 1
								FinSi
								Si i MOD divisor = 0 Entonces
									contDivisoresI <- contDivisoresI + 1
								FinSi
								divisor <- divisor + 1
							FinMientras
							Si contDivisoresI = 2 y contDivisoresJ = 2 y contDivisoresI = 2 Entonces
								existeCombinacionValida <- existeCombinacionValida + 1
								Escribir i, " x ", j, " x ", k " = ", num
							FinSi
						FinSi
						Si j * i * k > num Entonces
							centinela3 <- Falso
						FinSi
						k <- k + 1
					FinMientras
					Si j * i > num Entonces
						centinela2 <- Falso
					FinSi
					j <- j + 1
				FinMientras
				Si i > num Entonces
					centinela1 <- Falso
				FinSi
				i <- i + 1
			FinMientras
			Si existeCombinacionValida > 0 Entonces
				Escribir "Existen ", existeCombinacionValida, " combinaciones"
			Sino 
				Escribir "Existen 0 combinaciones"
			FinSi
		FinSi
	FinSi
FinAlgoritmo
