Algoritmo AnguloEntreVectores
	Escribir "Ingrese primer vector: "
	Leer x1, y1
	Escribir "Ingrese segundo vector: "
	Leer x2, y2
	productoPunto <- x1 * x2 + y1 * y2
	moduloVector1 <- rc(x1^2 + y1^2)
	moduloVector2 <- rc(x2^2 + y2^2)
	angulo <- acos((productoPunto) / (moduloVector1 * moduloVector2))
	angulo <- angulo * 180 / PI
	Escribir "El angulo entre los vectores es: ", angulo
	Si angulo <= 90 Entonces
		Si angulo = 90 Entonces
			Escribir "El ángulo es recto"
		Sino 
			Escribir "El ángulo es agudo"
		FinSi
	Sino 
		Escribir "El ángulo es obtuso"
	FinSi
FinAlgoritmo
