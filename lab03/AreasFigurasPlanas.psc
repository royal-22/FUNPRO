Algoritmo AreasFigurasPlanas
	Escribir "Ingrese los lados del triangulo escaleno (a, b, c) y el lado del hexágono regular: "
	Leer a, b, c, l
	s <- (a + b + c) / 2
	areaTriangulo <- rc(s * (s - a) * (s - b) * (s - c))
	areaHexagono <- (3 * l^2) / (2 * tan(30 * PI / 180))
	Si areaTriangulo > areaHexagono Entonces
		Escribir "El triángulo posee mayor area."
	Sino 
		Escribir "El hexágono posee mayor area. "
	FinSi
	
FinAlgoritmo
