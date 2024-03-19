Algoritmo raizCuadradaNumero
	Escribir "Ingrese el radicando"
	Leer num
	Si num <1000000000 y num > 0 Entonces
		Escribir "Ingrese la cantidad de decimales: "
		Leer cantDecimales
		Si cantDecimales <= 4 y cantDecimales > 0 Entonces
			cantCifras <- 0
			copiaNum <- num
			Mientras num > 0 Hacer
				num <- trunc(num / 10)
				cantCifras <- cantCifras + 1
			FinMientras
			Si cantCifras % 2 = 0 Entonces
				num2 <- copiaNum MOD trunc(10^(cantCifras/2))
				num1 <- trunc(copiaNum / trunc(10^(cantCifras/2)))
				
			Sino 
				num1 <- trunc(copiaNum / trunc(10^(cantCifras - 1)))
				num2 <- copiaNum MOD trunc(10^(cantCifras - 1))
			FinSi
			parteEntera <- 0
			i <- 1
			Mientras i^2 < num1 Hacer
				i <- i + 1
			FinMientras
			rootParteEntera <- i
			siguiente <- i * 2
			j <- 1
			centinela2 <- Verdadero
			exponente <- 1
			rootGeneral <- rootParteEntera
			
			Si num2 > 0 Entonces
				Mientras centinela2  Hacer
					j <- j + 1
					Si (siguiente * (10^exponente) + j) * j > num2 Entonces
						j <- j - 1
						centinela2 <- Falso
					FinSi
					Si j > 10^exponente Entonces
						exponente <- exponente + 1
					FinSi
				FinMientras
				rootParteEntera <- rootParteEntera * (10^exponente) + j
				num2 <- num2 - (siguiente * (10^exponente) + j) * j
				rootGeneral <- rootParteEntera
				siguiente <- rootGeneral * 2

				decimales <- 0
				Si num2 <> 0 Entonces
					Mientras decimales < cantDecimales Hacer
						k <- 1
						exponente <- 1
						num2 <- num2 * 100
						Escribir num2, " " ,siguiente
						centinela3 <- Verdadero
						Mientras centinela3 Hacer
							k <- k + 1
							Si (siguiente * (10^exponente) + k) * k > num2 Entonces
								k <- k - 1
								centinela3 <- Falso
							FinSi
							Si k > 10^exponente Entonces
								exponente <- exponente + 1
							FinSi
						FinMientras
						Escribir k
						Escribir "Dividendo", (siguiente * (10^exponente) + k)
						decimales <- decimales + 1
						rootParteEntera <- rootParteEntera * (10^exponente) + k
						num2 <- num2 - (siguiente * (10^exponente) + k) * k
						rootGeneral <- rootParteEntera
						siguiente <- rootGeneral * 2
						Escribir rootGeneral
					FinMientras
				FinSi
			FinSi
			
			Escribir "La raiz cuadrada de ", copiaNum, " con ", cantDecimales " es ", rootGeneral
		FinSi
	Sino 
		Escribir "El número debe ser mayor que 0 y menor o igual a 999999999"
	FinSi
	
FinAlgoritmo
