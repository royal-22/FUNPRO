Algoritmo DistanciaEntreDosPuntosGeograficos
	// Nombre: Luciana Carrillo
	// Codigo: 20230558
	Escribir "Ingrese la opción del grado de la latitud y la longitud"
	Escribir "D: Grado decimal"
	Escribir "S: Grado sexagesimal"
	Leer opcionGrado
	
	radioE <- 6378
	radioP <- 6357
	radioV <- 6371
	// Cuando se halle una respuesto rspt tendrá el valor de 1 para que pueda imprimir el resultado
	rspt <- 0
	Si opcionGrado = "D" o opcionGrado = "S" Entonces
		
		Si opcionGrado = "D" Entonces
			// Para grados decimales
			Escribir "Punto 1:"
			Escribir "-------------------------------------------------"
			Escribir "Ingrese la latitud del punto 1 (en grado decimal)"
			Leer latitud1
			Escribir "Ingrese la longitud del punto 1 (en grado decimal)"
			Leer longitud1
			Escribir "Punto 2:"
			Escribir "-------------------------------------------------"
			Escribir "Ingrese la latitud del punto 2 (en grado decimal)"
			Leer latitud2
			Escribir "Ingrese la longitud del punto 2 (en grado decimal)"
			Leer longitud2
			// Como la longitud y latitud se miden en grados sexagesimales se debe validar 
			// que los ángulos en grados decimales sean válidos
			longitudesValidas <- (-180 <= longitud1 y longitud1 <= 180) y (-180 <= longitud2 y longitud2 <= 180)
			latitudesValidas <- (-90<= latitud1 y latitud1 <= 90) y (-90<= latitud2 y latitud2 <= 90)
			Si latitudesValidas y longitudesValidas Entonces
				Escribir "Ingrese la opción del radio terrestres"
				Escribir "E: Radio ecuatorial"
				Escribir "V: radio volumétrico"
				Escribir "P: Radio polar"
				Leer opcionRadioD
				Si opcionRadioD = "E" o opcionRadioD = "V" o opcionRadioD = "P" Entonces
					argumentoAcosD <- sen(latitud1* PI / 180) * sen(latitud2* PI / 180) + cos(latitud1* PI / 180) * cos(latitud2* PI / 180) * cos((longitud1 - longitud2)* PI / 180) 
					Si opcionRadioD = "E" Entonces
						distanciaPuntos <- radioE * acos(argumentoAcosD)
						rspt <- 1
					Sino 
						Si opcionRadioD = "P" Entonces
							distanciaPuntos <- radioP * acos(argumentoAcosD)
							rspt <- 1
						Sino 
							distanciaPuntos <- radioV *  acos(argumentoAcosD)
							rspt <- 1
						FinSi
					FinSi
				Sino 
					Escribir "Opción radio invalida"
				FinSi
			Sino
				Escribir "Algún valor ingresado del punto 1 o 2 no son válidos"
			FinSi
		Sino 
			Escribir "Punto 1:"
			Escribir "-------------------------------------------------"
			Escribir "Ingrese la latitud del punto 1 (en grado decimal)"
			Leer latitudGrado1
			Leer latitudMinutos1
			Leer latitudSegundos1
			Escribir "Ingrese el punto cardinal (N o S)"
			Leer PuntoCardinalLat1
			Escribir "Ingrese la longitud del punto 1 (en grado decimal)"
			Leer longitudGrado1
			Leer longitudMinutos1
			Leer longitudSegundos1
			Escribir "Ingrese el punto cardinal (E o O)"
			Leer puntoCardinalLon1
			Escribir "Punto 2:"
			Escribir "-------------------------------------------------"
			Escribir "Ingrese la latitud del punto 2 (en grado decimal)"
			Leer latitudGrado2
			Leer latitudMinutos2
			Leer latitudSegundos2
			Escribir "Ingrese el punto cardinal (N o S)"
			Leer PuntoCardinalLat2
			Escribir "Ingrese la longitud del punto 2 (en grado decimal)"
			Leer longitudGrado2
			Leer longitudMinutos2
			Leer longitudSegundos2
			Escribir "Ingrese el punto cardinal (E o O)"
			Leer PuntoCardinalLon2
			// Grados sexagesimales a decimales
			longitudGradoDecimal1 <- longitudGrado1 + longitudMinutos1/60 + longitudSegundos1 / 3600
			longitudGradoDecimal2 <- longitudGrado2 + longitudMinutos2/60 + longitudSegundos2 / 3600
			latitudGradoDecimal1 <- latitudGrado1 + latitudMinutos1/60 + latitudSegundos1 / 3600
			latitudGradoDecimal2 <- latitudGrado2 + latitudMinutos2/60 + latitudSegundos2 / 3600
			Si puntoCardinalLat1 = "S" Entonces
				latitudGradoDecimal1 <- -1 * latitudGradoDecimal1 
			FinSi
			Si PuntoCardinalLon1 = "O" Entonces
				longitudGradoDecimal1 <- -1 * longitudGradoDecimal1 
			FinSi
			Si puntoCardinalLat1 = "S" Entonces
				latitudGradoDecimal2 <- -1 * latitudGradoDecimal2 
			FinSi
			Si PuntoCardinalLon2 = "O" Entonces
				longitudGradoDecimal2 <- -1 * longitudGradoDecimal2 
			FinSi
			
			Escribir "La latitud del punto 1 : ", latitudGradoDecimal1
			Escribir "La longitud del punto 1 : ", longitudGradoDecimal1
			Escribir "La latitud del punto 2 : ", latitudGradoDecimal2
			Escribir "La longitud del punto 2 : ", longitudGradoDecimal2

			Escribir "Ingrese la opción del radio terrestres"
			Escribir "E: Radio ecuatorial"
			Escribir "V: radio volumétrico"
			Escribir "P: Radio polar"
			Leer opcionRadioS
			Si opcionRadioS = "E" o opcionRadioS = "V" o opcionRadioS = "P" Entonces
				argumentoAcos <- sen(latitudGradoDecimal1 * PI / 180) * sen(latitudGradoDecimal2 * PI / 180) + cos(latitudGradoDecimal1 * PI / 180) * cos(latitudGradoDecimal2* PI / 180) * cos((longitudGradoDecimal1 - longitudGradoDecimal2) * * PI / 180)
				Si opcionRadioS = "E" Entonces
					distanciaPuntos <- radioE * acos(argumentoAcos)
					rspt <- 1
				Sino 
					Si opcionRadioS = "P" Entonces
						distanciaPuntos <- radioP * acos(argumentoAcos)
						rspt <- 1
					Sino 
						distanciaPuntos <- radioV *  acos(argumentoAcos)
						rspt <- 1
					FinSi
				FinSi
			Sino 
				Escribir "Opción radio invalida"
			FinSi
		FinSi
		
	FinSi
	Si rspt = 1 Entonces
		Escribir "La distancia entre los dos puntos es: ", distanciaPuntos, "km."
	FinSi
FinAlgoritmo
