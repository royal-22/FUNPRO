Algoritmo TangentesExteriores
	Escribir "Ingrese las coordenadas x e y del centro de la circunferencia 1: "
	Leer x1, y1
	Escribir "Ingrese las coordenadas x e y del centro de la circunferencia 2: "
	Leer x2, y2
	Escribir "Ingrese el radio de la circunferencia 1:"
	Leer r1
	Escribir "Ingrese el radio de la circunferencia 2: "
	Leer r2
	
	area1 <- PI * r1^2
	longitud1 <- 2 * PI * r1
	area2 <- PI * r2^2
	longitud2 <- 2 * PI * r2
	
	distanciaR1R2 <- rc((x1- x2)^2 + (y1 - y2)^2)
	
	sonTangentes <- distanciaR1R2 = (r1 + r2)
	Escribir "Resultados de la circunferencia 1: "
	Escribir "El área es: ", area1
	Escribir "La longitud es: ", longitud1
	Escribir "Resultados de la circunferencia 2: "
	Escribir "El area es: ", area2
	Escribir "La longitud es: ", longitud2
	Escribir "¿Son circunferencias tangentes? ", sonTangentes
	
FinAlgoritmo
