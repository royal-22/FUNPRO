Algoritmo CaracolCoordenadasPolares
	Escribir "Ingrese el punto 1 (distancia, ángulo sexagesimal)"
	Leer distancia1, angulo1
	Escribir "Ingrese el punto 1 (distancia, ángulo sexagesimal)"
	Leer distancia2, angulo2
	Escribir "Ingrese el punto 1 (distancia, ángulo sexagesimal)"
	Leer distancia3, angulo3
	Escribir "Ingrese los datos para el caracol"
	Escribir "Coeficiente a: "
	Leer coeficienteA
	Escribir "Coeficiente b:"
	Leer coeficienteB
	Escribir "Ingrese la precisión: "
	Leer precision 
	
	coeficientesValidos <- coeficienteA <> 0 y coeficienteB <> 0
	precisionValida <- precision <= 0.1
	Si coeficientesValidos y precisionValida Entonces
		angulo1 <- angulo1 * PI / 180
		punto1 <- coeficienteA + coeficienteB * sen(angulo1)
		angulo2 <- angulo2 * PI / 180
		punto2 <- coeficienteA + coeficienteB * sen(angulo2)
		angulo3 <- angulo3 * PI / 180
		punto3 <- coeficienteA + coeficienteB * sen(angulo3)
		puntosEnCaracol <- 0
		Si abs(distancia1 - punto1) < precision Entonces
			puntosEnCaracol <- puntosEnCaracol + 1
			Escribir "El punto (", distancia1, ",", angulo1*180/PI, ") pertenece al caracol con ecuación r=", coeficienteA, " + ", coeficienteB, "sen(theta)"
		FinSi
		Si abs(distancia2 - punto2) < precision Entonces
			puntosEnCaracol <- puntosEnCaracol + 1 
			Escribir "El punto (", distancia2, ",", angulo2*180/PI, ") pertenece al caracol con ecuación r=", coeficienteA, " + ", coeficienteB, "sen(theta)"
		FinSi
		Si abs(distancia3 - punto3) < precision Entonces
			puntosEnCaracol <- puntosEnCaracol + 1 
			Escribir "El punto (", distancia3, ",", angulo3*180/PI, ") pertenece al caracol con ecuación r=", coeficienteA, " + ", coeficienteB, "sen(theta)"
		FinSi
		Si puntosEnCaracol >= 2 Entonces
			area <- PI * (coeficienteB^2 + coeficienteA^2 / 2)
			Escribir "El área del caracol es: ", area
			relacion <- coeficienteA / coeficienteB
			Si relacion = 1 Entonces
				Escribir "El caracol es cardioide porque a/b es: ", relacion
			Sino 
				Si relacion < 1 Entonces
					Escribir "El caracol tiene lazo porque a/b es: ", relacion
				Sino 
					Si relacion < 2 Entonces
						Escribir "El caracol tiene hendidura porque a/b es: ", relacion
					Sino 
						Escribir "El caracol es convexo porque a/b es: ", relacion
					FinSi
				FinSi
				
			FinSi
		Sino 
			Escribir "No se encuentran dos puntos que pertenecen al caracol"
		FinSi
		
	Sino 
		Si no coeficientesValidos Entonces
			Si coeficienteA = 0 Entonces
				Escribir "El coeficiente a ingresado para el caracol no es válido, debe ser diferente de 0."
			Sino 
				Escribir "El coeficiente b ingresado para el caracol no es válido, debe ser diferente de 0"
			FinSi
		Sino 
			Escribir "La precisión para realizar los cálculos deber ser menor o igual a 0.1"
		FinSi
	FinSi
	
	
FinAlgoritmo
