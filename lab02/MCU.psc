Algoritmo MCU
	Escribir "Ingrese la distancia (en metros) de la pista circular: "
	Leer distancia
	Escribir "Ingrese el timepo (en segundos) que se demoró en recorrer la distancia de la pista circular el auto 1: "
	Leer tiempo1
	Escribir "Ingrese el tiempo (en segundos) que se demoró en recorrer la distancia de la pista circular el auto 2: "
	Leer tiempo2
	Escribir "Ingrese la masa (en kg) del auto 1: "
	Leer masa1
	Escribir "Ingrese la masa (en kg) del auto 2: "
	Leer masa2
	
	radio <- distancia / ( 2 * PI)
	aceleracion1 <- (distancia/tiempo1)^2 / radio
	aceleracion2 <- (distancia/tiempo2)^2 / radio
	fuerza1 <- masa1 * aceleracion1
	fuerza2 <- masa2 * aceleracion2
	auto1Mayor <- fuerza1 > fuerza2 o fuerza1 = fuerza2
	auto2Mayor <- fuerza2 > fuerza1
	Escribir "La fuerza central para el auto 1 es: ", fuerza1
	Escribir "La fuerza central para el auto 2 es ", fuerza2
	Escribir "¿Fuerza central del auto1 es mayor que el auto 2? ", auto1Mayor
	Escribir "¿Fuerza central del auto2 es mayor que el auto 1? ", auto2Mayor
	
FinAlgoritmo
