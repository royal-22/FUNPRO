Algoritmo primoHonaker
	Escribir "Ingrese la opcion: 1)Hallar n�meros honaker 2) Imprimir n�mero Honaker"
	Leer opc
	Si opc = 1 Entonces
		Escribir "Ingrese el rango de valores a evaluar"
		Leer inicio, final
		Si final > inicio Entonces
			i <- inicio
			Mientras i <= final Hacer 
				j <- 1
				posPrimos <- 0
				Mientras j <= i Hacer
					contadorDivisores <- 0
					k <- 1 
					Mientras k <= j Hacer
						Si j MOD k = 0 Entonces
							contadorDivisores <- contadorDivisores + 1
						FinSi
						k <- k + 1
					FinMientras
					Si contadorDivisores == 2 Entonces
						posPrimos <- posPrimos + 1
					FinSi
					j <- j + 1
				FinMientras
				Si contadorDivisores = 2 Entonces
					copiaNum <- i
					sumaNum <- 0
					Mientras copiaNum > 0 Hacer
						d <- copiaNum MOD 10
						copiaNum <- trunc(copiaNum / 10)
						sumaNum <- sumaNum + d
					FinMientras
					copiaPos <- posPrimos
					sumaPos <- 0
					Mientras posPrimos > 0 Hacer
						d1 <- posPrimos MOD 10
						posPrimos <- trunc(posPrimos / 10)
						sumaPos <- sumaPos + d1
					FinMientras
					Si sumaPos = sumaNum Entonces
						Escribir i " es el primo en la posici�n ", copiaPos, " y es un n�mero Honaker"
					FinSi
					
				FinSi
				i <- i + 1
			FinMientras
		Sino 
			Escribir "L�mites inv�lidos"
		FinSi
	SiNo
		Escribir "Ingrese le n�mero Honaker a imprimir (se asume que el n�mero cumple la condici�n)"
		Leer numeroHonaker
		Si numeroHonaker > 0 Entonces
			suma <- 0
			Mientras numeroHonaker > 0 Hacer
				d <- numeroHonaker MOD 10
				numeroHonaker <- trunc(numeroHonaker / 10)
				suma <- suma + d
				Escribir d
				Si numeroHonaker > 0 Entonces
					Escribir "+"
				FinSi
			FinMientras
			Escribir "=", suma
		Sino 
			Escribir "Ingres� un valor negativo"
		FinSi
		
	FinSi
FinAlgoritmo
