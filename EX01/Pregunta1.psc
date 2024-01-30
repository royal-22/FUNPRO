Algoritmo Pregunta1
	Escribir "Ingrese la ley a ingresar (B, C, G, A): "
	Leer opcionLey
	
	Si opcionLey = "B" o opcionLey = "C" o opcionLey = "G" o opcionLey = "A" Entonces
		Si opcionLey = "B" Entonces
			Escribir "Ingrese la presión incial (Pa): "
			Leer presionInicial
			Escribir "Ingrese el volumen inicial (L): "
			Leer volumenInicial
			Escribir "Ingrese la presión final (Pa): "
			Leer presionFinal
			Si presionInicial > 0 y volumenInicial > 0 y presionFinal > 0 Entonces
				volumenFinal <- presionInicial * volumenInicial / presionFinal
				Escribir "El volumen final es ", volumenFinal, " l"
			Sino 
				error<- Verdadero
			FinSi
		Sino 
			Si opcionLey = "C" Entonces
				Escribir "Ingrese el volumen inicial (L): "
				Leer volumenInicialC
				Escribir "Ingrese la temperatura inical (K): "
				Leer temperaturaInicialC
				Escribir "Ingrese el volumen final (L): "
				Leer volumenFinalC
				Si volumenInicialC > 0 y temperaturaInicialC > 0 y volumenFinalC > 0 Entonces
					temperaturaFinalC <- volumenFinal * temperaturaInicialC / volumenInicialC
					Escribir "La temperatura final es ", temperaturaFinalC, " K"
				Sino 
					error<- Verdadero
				FinSi
			Sino 
				Si opcionLey = "G" Entonces
					Escribir "Ingrese la presión inicial (Pa): "
					Leer presionInicialG
					Escribir "Ingrese la temperatura inicial (C): "
					Leer temperaturaInicialG
					Escribir "Ingrese la temperatura final (C): "
					Leer temperaturaFinalG
					temperaturaInicialG <- temperaturaInicialG + 273
					temperaturaFinalG <- temperaturaFinalG + 273
					Si temperaturaFinalG > 0 y temperaturaInicialG > 0 y presionInicialG > 0 Entonces
						presionFinalG <- presionInicialG * temperaturaFinalG / temperaturaInicialG
						Escribir "La presión final es ", presionFinalG, " Pa"
					Sino 
						error<- Verdadero
					FinSi
				Sino 
					Escribir "Ingrese el volúmen de gas de CO2 (L): "
					Leer volumenA
					Si volumenA > 0 Entonces
						moles <- volumenA * 1 / 22.4
						Escribir "La cantidad de moles es: ", moles, " moles"
					Sino 
						error<- Verdadero
					FinSi
				FinSi
				
			FinSi
		FinSi
		Si error = Verdadero Entonces
			Escribir "Al menos un de los datos no son correctos"
		FinSi
	Sino 
		Escribir "La la ley ingresada no es correcta."
	FinSi	
FinAlgoritmo
