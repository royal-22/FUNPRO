Algoritmo IdentidadesAlgebraicas
	// Nombre: Luciana Carrrillo
	// Codigo: 20230558
	Escribir "Ingrese los valores para determinar si se cumple la Identidad 1: "
	Escribir "Ingrese a, b y c (en ese orden)"
	Leer a1, b1, c1
	Escribir "Ingrese los valores para determinar si se cumple la Identidad 2: "
	Escribir "Ingrese a, b, c y x (en ese orden)"
	Leer a2, b2, c2, x2
	Escribir "Ingrese los valores para determinar si se cumple la Identidad 3 "
	Escribir "Ingrese a, b y c (en ese orden)"
	Leer a3, b3, c3
	
	// Calcular para la identidad 1
	expresion1 <- (a1 + b1 + c1)^3 
	identidad1 <- a1^3 + b1^3 + c1^3 + 3 * (a1 + b1) * (b1 + c1) * (c1 + a1)
	
	// Calcular para la identidad 2
	expresion2 <- (x2 + a2) * (x2 + b2) * (x2 + c2)
	identidad2 <- x2^3 + (a2 + b2 + c2) * x2^2 + (a2 * b2 + b2 * c2 + a2 * c2) * x2 + a2 * b2 * c2
	
	// Calcular para la identidad 3
	expresion3 <- a3^3 * (b3 - c3) + b3^3 * (c3 -a3) + c3^3 * (a3 - b3)
	identidad3 <- -1 * (b3 - c3) * (c3 - a3) * (a3 - b3) * (a3+ b3 + c3)
	
	//Realizar las comparaciones
	identidad1Valida <- expresion1 = identidad1
	identidad2Valida <- expresion2 = identidad2
	identidad3Valida <- expresion3 = identidad3
	
	identidad1Mayor <- identidad1 > identidad2
	identidad3Mayor <- identidad3 > identidad1
	
	// Imprimir los resultados
	Escribir "La identidad 1 tiene como resultado: ", identidad1
	Escribir "La identidad 2 tiene como resultado: ", identidad2
	Escribir "La identidad 3 tiene como resultado: ", identidad3
	Escribir "Se cumple la identidad 1: ", identidad1Valida
	Escribir "Se cumple la identidad 3: ", identidad2Valida
	Escribir "Se cumple la identidad 3: ", identidad3Valida
	Escribir "El resultado obtenido en la identidad 1 es mayor que el obtenido en la identidad 2: ", identidad1Mayor
	Escribir "El resultado obtenido en la identidad 3 es mayor que el obtenido en la identidad 1: ", identidad3Mayor

FinAlgoritmo
