Algoritmo curiosidadMatematica
	// Nombre: Luciana Carrillo
	// Codigo: 20230558
	Escribir "Ingrese el número a encontrar: "
	Leer num
	Si num > 0 Entonces
		// Calcular cifras
		copiaNum <- num
		cantCifras <- 0
		numMayor <- 0
		// Calcular cantidad de cifras y el dígito mayor en el número
		Mientras num > 0 Hacer
			d <- num MOD 10
			Si d > numMayor Entonces
				numMayor <- d
			FinSi
			num <- trunc(num/10)
			cantCifras <- cantCifras + 1
		FinMientras
		Escribir "El número ", copiaNum, " tiene ", cantcifras, " cifras"  
		// Ordenar cifras de mayor a menor
		num <- copiaNum
		numOrdenado <- 0
		Mientras num > 0 Hacer
			aux <- num
			auxNuevo <- 0
			Mientras aux > 0 Hacer
				d <- aux MOD 10
				Si d = numMayor Entonces
					numOrdenado <- numOrdenado * 10 + d
				Sino 
					auxNuevo <- auxNuevo * 10 + d
				FinSi
				aux <- trunc(aux / 10)
			FinMientras
			numMayor <- numMayor - 1
			num <- auxNuevo
		FinMientras
		Escribir "El número ", copiaNum, " ordenado con sus cifras de mayor a menor es: ", numOrdenado
		copiaNumOrdenado <- numOrdenado
		i <- 0
		esNumeroValido <- Verdadero
		// Validar si cumple con que las cifras sean consecutivas e inicie con 9
		Mientras i < cantCifras Hacer
			d <- trunc(numOrdenado / (10^(cantCifras - 1 - i)))
			Si i = 0 Entonces
				Si d <> 9 Entonces
					esNumeroValido <- Falso
				FinSi
			Sino 
				Si dAnterior - d <> 1 Entonces
					esNumeroValido <- Falso
				FinSi
			FinSi
			dAnterior <- d
			numOrdenado <- numOrdenado MOD (10^(cantCifras - 1 - i))
			i <- i + 1
		FinMientras
		Si esNumeroValido Entonces
			Escribir "El número ordenado ", copiaNumOrdenado, " sí cumple con el requisito de iniciar en 9 y que sus cifras sean consecutivas"
			// Calcular curiosidad matemática
			valorSuma <- 9 - cantCifras - 1
			curiosidad <- copiaNumOrdenado * 9 + valorSuma
			Escribir "La curiosidad matemática es: ", copiaNumOrdenado, " x ", 9, " + ", valorSuma " = ", curiosidad
		SiNo
			Escribir "El número ordenado ", copiaNumOrdenado, " no cumple con el requisito de iniciar en 9 y que sus cifras sean consecutivas" 
		FinSi
	Sino 
		Escribir "El número debe ser mayor que cero"
	FinSi
FinAlgoritmo