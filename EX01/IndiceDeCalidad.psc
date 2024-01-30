Algoritmo  IndiceDeCalidad
	Escribir "Ingrese una opcion (M o F): "
	Leer opcionMF
	MPTuExistente <- 0
	Si opcionMF = "M" o opcionMF = "F" Entonces
		Si opcionMF = "M" Entonces
			Escribir "Ingrese una opción para ingresar MPT en su unidad de medida (G o N): "
			Leer opcionGN
			Si opcionGN = "G" o opcionGN = "N" Entonces
				Si opcionGN = "G" Entonces
					Escribir "Ingrese el microparticulado total en gramos: "
					Leer MPTgramos 
					MPTu <- MPTgramos / (10^(-1*6))
				Sino 
					Escribir "Ingrese el microparticulado total en nanogramos"
					Leer MPTnano
					MPTu <- MPTnano * (10^(-1*9)) / (10^(-1*6))
				FinSi
				MPTuExistente <- 1
			Sino 
				Escribir "Opción inválida. Debe ingresar G o N para MPT en su unidad de medida."
				
			FinSi
		Sino 
			Escribir "Ingrese los parámetros de la función lineal: "
			Leer parametroA, parametroB
			Escribir "Ingrese el índice de calidad del aire: "
			Leer indice
			Si indice > 0 Entonces
				MPTu <- (indice - parametroB) / parametroA
				MPTuExistente <- 1
			Sino 
				Escribir "El índice de calidad del aire debe ser mayor que 0"
			FinSi
		FinSi
	Sino 
		Escribir "Opción inválida. Debe ingresar M o F"
	FinSi
	MPTuValido <- MPTuExistente = 1 y MPTu >= 1 y MPTu <= 845
	Si MPTuExistente = 1 Entonces
		Si MPTuValido Entonces
			Si MPTu > 60 Entonces
				Si MPTu <= 100 Entonces
					Escribir "Calidad Buena"
				Sino 
					Si MPTu <= 150 Entonces
						Escribir "Calidad Aceptable"
					Sino 
						Si MPTu <= 375 Entonces
							Escribir "Calidad Inadecuada"
						Sino 
							Si MPTu <= 563 Entonces
								Escribir "Calidad Mala"
							Sino 
								Escribir "Calidad muy mala"
							FinSi
						FinSi
					FinSi
				FinSi
			Sino 
				Escribir "Calidad muy buena"
			FinSi
		Sino 
			Escribir "El microparticulado total debe estar entre 1 y 845 ug/m^3"
		FinSi
		
	FinSi

FinAlgoritmo