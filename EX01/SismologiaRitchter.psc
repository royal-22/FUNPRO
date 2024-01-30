Algoritmo SismologiaRitchter
	Escribir "Indique en que unidad ingresará lel tiempo: segundos (E o e), milisegundos (M o m)"
	Leer opcionTiempo
	
	opcionTiempoEValida <- opcionTiempo = "e" o opcionTiempo = "E"
	opcionTiempoMValida <- opcionTiempo = "M" o opcionTiempo = "m"
	
	Si opcionTiempoEValida O opcionTiempoMValida Entonces
		Si opcionTiempoEValida Entonces
			Escribir "Ingrese el tiempo en segundos: "
			Leer segundosE
		Sino
			segundosFormula <- segundosE
			Escribir "Ingrese el tiempo en milisegundo: "
			Leer milisegundosE
			segundosFormula <- milisegundosE * 0.001 
		FinSi
		Si segundosFormula <= 30 y segundosFormula >= 0 Entonces
			Escribir "Indique en que unidad ingresará la amplitud : centímetros (C o c), milimetros (M o m)"
			Leer opcionAmplitud
			amplitudCentimetrosV <- opcionAmplitud = "c" o opcionAmplitud = "C"
			amplitudMilimetrosV <- opcionAmplitud = "m" o opcionAmplitud = "M"
			Si amplitudCentimetrosV O amplitudMilimetrosV Entonces
				Si amplitudCentimetrosV Entonces
					Escribir "Ingrese la amplitud en centímetros"
					Leer amplitudCentimetros 
					amplitud <- amplitudCentimetros * 10
				Sino 
					Escribir "Ingrese la ampplitud en milímetros"
					Leer amplitudMilimetros
					amplitud <- amplitudMilimetros
				FinSi
				Si amplitud >= 0 Y amplitud <= 750 Entonces
					segundosCubo <- segundosFormula
					argumento <- amplitud * segundosFormula^3 / 1.62
					Escribir argumento
					magnitud <- ln(argumento) / ln(10)
					Escribir amplitud
					Escribir segundosFormula
					Escribir "La magnitud es: ", magnitud
					Si magnitud >= 2 Entonces
						Si magnitud < 3.9 Entonces
							Escribir "Sismo menor"
						Sino 
							Si magnitud < 4.9 Entonces
								Escribir "Sismo ligero"
							Sino 
								Si magnitud < 5.9 Entonces
									Escribir "Sismo moderado"
								Sino 
									Si magnitud < 6.9 Entonces
										Escribir "Sismo fuerte"
									Sino 
										Escribir "Sismo mayor"
									FinSi
								FinSi
							FinSi
						FinSi
					Sino 
						Escribir "micro sismo"
					FinSi
				Sino 
					Escribir "Rango incorrecto par la amplitud"
				FinSi
			Sino 
				Escribir "Opción incorrecta para la amplitud"
			FinSi
		Sino 
			Escribir "Rango incorrecto para el tiempo"
		FinSi
	Sino 
		Escribir "Opción incorrecta para el tiempo"
	FinSi
FinAlgoritmo
