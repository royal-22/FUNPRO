Algoritmo numerosBases
	Escribir "Ingrese el número a evaluar: "
	Leer num
	Escribir "Ingrese la base: "
	Leer base
	Si num >= 0 y base >= 2 y base <= 9 Entonces
		// Cambiar de base
		copiaNum <- num
		nuevoNum <- 0 
		exponente <- 0
		cantCifras <- 0
		Mientras num > 0 Hacer
			d <- num MOD base
			num <- trunc(num / base)
			nuevoNum <- nuevoNum + d * 10^exponente
			exponente <- exponente + 1
			cantCifras <- cantCifras + 1
		FinMientras
		Escribir "El número ", copiaNum, " en base ", base, "es : ", nuevoNum
		i <- 1
		Mientras i <= cantCifras Hacer
			Si cantCifras MOD i = 0 Entonces
				suma <- 0
				copiaNuevoNum <- nuevoNum
				j <- 0
				Escribir "Para grupos de ", i, " cifras: "
				Mientras copiaNuevoNum > 0 Hacer
					cifras <- copiaNuevoNum MOD trunc(10^(i))
					suma <- suma + cifras
					copiaNuevoNum <- trunc(copiaNuevoNum / (10^i))
					Si j = 0 Entonces
						Si copiaNuevoNum > 0 Entonces
							Escribir cifras, " +"
						Sino 
							Escribir cifras
						FinSi
					Sino 
						Escribir cifras
					FinSi
					j <- j + 1
				FinMientras
				Escribir "--------"
				Escribir suma
				copiaSuma <- suma
				cantCifrasSuma <- 0
				Mientras suma > 0 Hacer
					suma <- trunc(suma / 10)
					cantCifrasSuma <- cantCifrasSuma + 1
				FinMientras
				//Evaluar si es capicúa 
				copiaCopiaSuma <- copiaSuma
				esCapicua <- Verdadero
				Mientras copiaSuma >= 10 Hacer
					d1 <- copiaSuma MOD 10
					d2 <- trunc(copiaSuma /(10^(cantCifrasSuma - 1)))
					copiaSuma <- trunc(copiaSuma / 10)
					copiaSuma <- copiaSuma MOD (10^(cantCifrasSuma - 2))
					Si d1 <> d2 Entonces
						esCapicua <- Falso
					FinSi
					cantCifrasSuma <- cantCifrasSuma - 2
				FinMientras
				Si esCapicua Entonces
					Escribir "La suma ", copiaCopiaSuma, " es capicúa"
				Sino 
					Escribir "La suma ", copiaCopiaSuma, " no es capicúa"
				FinSi
			FinSi
			i <- i + 1 
		FinMientras
	Sino 
		Escribir "El número debe ser mayor que 0 y/o la base mayor a 1 y menor que 10"
	FinSi	
FinAlgoritmo