Algoritmo MenuFormulas
	Escribir "Ingrese el tema cuyas fórmulas requiere"
	Escribir "1: Movimiento ondulatorio"
	Escribir "2: Densidad, elasticidad"
	Escribir "3: Rotación de un cuerpo rígido"
	Leer opcion_
	Si opcion_ >= 1 y opcion_<= 3 Entonces
		Si opcion_ = 1 Entonces
			Escribir "Seleccione la fórmula que requiere utilizar"
			Escribir "T: Calcular periodo de vibración"
			Escribir "L: Calcular Longitud de onda"
			Escribir "V: Calcular velocidad"
			Leer variable
			Si variable <> "T" o variable <> "L" o variable <> "V" Entonces
				Escribir "La opción indicada no es valida"
			Sino 
				Si variable = "T" Entonces
					Escribir "Ingrese la frecuencia de vibración: "
					Leer vibracion
				SiNo
					Si variable = "L" Entonces
						Escribir "Ingrese la velocidad m/s"
						Leer velocidad
						Escribir "Ingrese el periodo de vibración en s"
						Leer periodoDeVibracion
					Sino 
						Escribir "Ingrese "
					FinSi
				FinSi
			FinSi
		Sino 
			Si opcio_ = 2 Entonces
				Escribir "Seleccione la fórmula que requiere utilizar"
				Escribir "D: Densidad"
				Escribir "P: Presión"
				Escribir "V: Volumen"
				Leer variable
			Sino 
				Escribir "Seleccione la fórmula que requiere utilizar"
				Escribir "I: Calcular el Momento de inercia"
				Escribir "E: Calcular energía cinética de rotación"
				Escribir "P: Calcular Potencia"
				Leer variable
			FinSi
			
		FinSi
		
	Sino 
		Escribir "La opción ingresada no es válida"
	FinSi
FinAlgoritmo
