Algoritmo MenuFormulas
	Escribir "Ingrese el tema cuyas f�rmulas requiere"
	Escribir "1: Movimiento ondulatorio"
	Escribir "2: Densidad, elasticidad"
	Escribir "3: Rotaci�n de un cuerpo r�gido"
	Leer opcion_
	Si opcion_ >= 1 y opcion_<= 3 Entonces
		Si opcion_ = 1 Entonces
			Escribir "Seleccione la f�rmula que requiere utilizar"
			Escribir "T: Calcular periodo de vibraci�n"
			Escribir "L: Calcular Longitud de onda"
			Escribir "V: Calcular velocidad"
			Leer variable
			Si variable <> "T" o variable <> "L" o variable <> "V" Entonces
				Escribir "La opci�n indicada no es valida"
			Sino 
				Si variable = "T" Entonces
					Escribir "Ingrese la frecuencia de vibraci�n: "
					Leer vibracion
				SiNo
					Si variable = "L" Entonces
						Escribir "Ingrese la velocidad m/s"
						Leer velocidad
						Escribir "Ingrese el periodo de vibraci�n en s"
						Leer periodoDeVibracion
					Sino 
						Escribir "Ingrese "
					FinSi
				FinSi
			FinSi
		Sino 
			Si opcio_ = 2 Entonces
				Escribir "Seleccione la f�rmula que requiere utilizar"
				Escribir "D: Densidad"
				Escribir "P: Presi�n"
				Escribir "V: Volumen"
				Leer variable
			Sino 
				Escribir "Seleccione la f�rmula que requiere utilizar"
				Escribir "I: Calcular el Momento de inercia"
				Escribir "E: Calcular energ�a cin�tica de rotaci�n"
				Escribir "P: Calcular Potencia"
				Leer variable
			FinSi
			
		FinSi
		
	Sino 
		Escribir "La opci�n ingresada no es v�lida"
	FinSi
FinAlgoritmo
