Algoritmo DinamicaCinematica
	Escribir "�Desea resolver problemas de din�mica (D) o cinem�tica (C)?"
	Leer opcionDoC
	Si opcionDoC = "D" o opcionDoC = "C" Entonces
		Si opcionDoC = "D" Entonces
			Escribir "Ingrese las masas en kg y la aceleraci�n en m/s^2"
			Leer masa1, masa2, aceleracionD
			Escribir "Ingrese la Fuerza en newtons, la velocidad en m/s y el coef. de rozamiento"
			Leer fuerza, velocidadD, coeficienteRozamiento
			gravedad <- 9.80665
			
			Si masa1 <> 999.99 y aceleracionD <> 999.99 y masa2 = 999.99 y aceleracionD = 999.99 y fuerza = 999.99 y coeficienteRozamiento = 999.99 Entonces
				fuerza <- masa1 * (aceleracionD + gravedad)
				Escribir "La tensi�n de la cuerda es: ", fuerza, " N"
			SiNo
				Si masa1 <> 999.99 y masa2 <> 999.99 y fuerza <> 999.99 y masa2 = 999.99 y aceleracionD = 999.99 y velocidadD = 999.99  y coeficienteRozamiento = 999.99 Entonces
					aceleracionD <- fuerza / (masa1 + masa2)
					Escribir "La aceleraci�n es: ", aceleracionD, " m/s^2"
				Sino 
					Si masa1 <> 999.99 y velocidadD <> 999.99 y coeficienteRozamiento <> 999.99 Entonces
						fuerza <- coeficienteRozamiento * masa1 * gravedad
						aceleracionD <- fuerza / masa1
						tiempoD <- velocidadD / aceleracionD
						Escribir "La fuerza de rozamiento es: ", fuerza, " N"
						Escribir "La aceleraci�n es: ", aceleracionD, " m/s^2"
						Escribir "El tiempo es:", tiempoD, " s"
					Sino 
						Escribir "Los datos ingresados no corresponden a ning�n problema de cinem�tica."
					FinSi
				FinSi
			FinSi
			
		Sino 
			Escribir "�Qu� desea calcular?"
			Escribir "1. Tiempo"
			Escribir "2. Velocidad final y espacio recorrido"
			Escribir "3. Velocidad inicial y desaceleraci�n"
			Leer opcionCinematica
			Si opcionCinematica>=1 y opcionCinematica <= 3 Entonces
				Si opcionCinematica = 1 Entonces
					Escribir "Ingrese la aceleraci�n en Km/h2 y la velocidad final m/s"
					Leer aceleracionC, velocidadFinalC
					velocidadFinalC <- velocidadFinalC * 3600 / 1000
					tiempoC <- velocidadFinalC / aceleracionC
					Escribir "Tard� ", tiempoC, " horas"
				SiNo
					Si opcionCinematica = 2 Entonces
						Escribir "Ingrese la aceleraci�n m/s^2 y el tiempo en minutos"
						Leer aceleracionC, tiempoC
						tiempoC <- tiempoC * 60
						velocidadFinalC <- aceleracionC * tiempoC
						espacioRecorrido <- 0.5 * aceleracionC * tiempoC^2
						Escribir "La velocidad final es: ", velocidadFinalC, " m/s"
						Escribir "El espacio recorrido es: ", espacioRecorrido, " m"
					Sino 
						Escribir "Ingrese la distancia en metros y el tiempo en minutos"
						Leer espacioRecorrido, tiempoC
						tiempoC <- tiempoC * 60
						velocidadInicialC <- (2 * espacioRecorrido) / tiempoC
						aceleracionC <- (-1 * velocidadInicialC) / tiempoC
						Escribir "La velocidad inicial es: ", velocidadInicialC, " m/s"
						Escribir "La aceleraci�n es: ", aceleracionC, " m/s^2"
					FinSi
				FinSi
			Sino 
				Escribir "Ingres� una opci�n inv�lida para cinem�tica."
			FinSi
		FinSi
	Sino 
		Escribir "Ha seleccionado un tipo equivocado de ejercicio."
	FinSi
FinAlgoritmo
