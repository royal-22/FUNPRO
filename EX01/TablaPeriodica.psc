Algoritmo TablaPeriodica
	Escribir "Ingrese el número atómico y número másico del elemento: "
	Leer numeroAtomico, numeroMasico
	numeroAtomicoValido <- numeroAtomico <= 120 y numeroAtomico >= 1
	numeroMasicoValido <- numeroMasico > numeroAtomico y numeroMasico > 0
	Escribir numeroMasicoValido
	
	Si numeroAtomicoValido y numeroMasicoValido Entonces
		Escribir "Ingrese la masa atómica del isótopo 1: "
		Leer masaAtomica1
		Escribir "Ingrese la abundancia relativa del isótopo 1: "
		Leer abundanciaIsotopo1
		Escribir "Ingrese la masa atómica del isótopo 2: "
		Leer masaAtomica2
		Escribir "Ingrese la abundancia relativa del isótopo 2: "
		Leer abundanciaIsotopo2
		Si abundanciaIsotopo1 + abundanciaIsotopo2 = 100 Entonces
			// Clasificacion 1
			liquido <- numeroAtomico = 35 o numeroAtomico = 80
			gas <- (numeroAtomico >= 7 y numeroAtomico <= 10) o numeroAtomico = 1 o numeroAtomico = 2 o numeroAtomico = 17 o numeroAtomico = 18 o numeroAtomico = 36 o numeroAtomico = 54 o  numeroAtomico = 86
			sintetico <- (numeroAtomico >= 93 y numeroAtomico <= 120) o numeroAtomico = 43 o numeroAtomico = 61
			
			// clasificacion 2
			metales <- (numeroAtomico >= 3 y numeroAtomico <= 4) o (numeroAtomico >= 11 y numeroAtomico <= 13) o (numeroAtomico >= 19 y numeroAtomico <= 31) o (numeroAtomico >= 37 y numeroAtomico <= 50) o (numeroAtomico >= 55 y numeroAtomico <= 56) o (numeroAtomico >= 72 y numeroAtomico <= 83) o (numeroAtomico >= 87 y numeroAtomico <= 88) o (numeroAtomico >= 104 y numeroAtomico <= 116)
			noMetales <- numeroAtomico = 1 o numeroAtomico = 6 o numeroAtomico = 7 o numeroAtomico = 8 o numeroAtomico = 15 o numeroAtomico = 16 o numeroAtomico = 34
			gasesNobles <-  numeroAtomico = 2 o numeroAtomico = 10 o numeroAtomico = 18 o numeroAtomico = 36 o numeroAtomico = 54 o numeroAtomico = 86 o numeroAtomico = 118
			lantanidos <- (numeroAtomico >= 57 y numeroAtomico <= 71)
			
			Escribir "Clasificación 1:"
			Si liquido Entonces
				Escribir "Líquidos"
			Sino 
				Si gas EntoNces
					Escribir "Gases"
				Sino 
					Si sintetico Entonces
						Escribir "Sintéticos"
					Sino 
						Escribir "Sólidos"
					FinSi
				FinSi
			FinSi
			Escribir "Clasificación 2:"
			Si metales Entonces
				Escribir "Metales"
			Sino 
				Si noMetales Entonces
					Escribir "No metales"
				Sino 
					Si gasesNobles Entonces
						Escribir "Gases nobles"
					Sino 
						Si lantanidos Entonces
							Escribir "lantanidos"
						Sino 
							Escribir "Otros"
						FinSi
					FinSi
				FinSi
			FinSi
			nNeutrones <- numeroMasico - numeroAtomico
			masaAtomicaTotal <- (masaAtomica1 * abundanciaIsotopo1 + masaAtomica2 * abundanciaIsotopo2) / 100
			Escribir "La cantidad de neutrones es: ", nNeutrones
			Escribir "La masa atómica es: ", masaAtomicaTotal
		Sino 
			Escribir "La abundancia relativas de los isótopos no suman 100"
		FinSi
	Sino 
		Si no numeroAtomicoValido Y no numeroMasicoValido Entonces
			Escribir "El número atómico y número másico ingresados no son correctos"
		SiNo
			Si no numeroAtomicoValido Entonces
				Escribir "El número atómico no pertenece a un elemento químico de la tabla periódica"
			Sino 
				Escribir "El número másico ingresado es incorrecto"
			FinSi
			
		FinSi
	FinSi	
FinAlgoritmo
