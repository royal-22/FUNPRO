Algoritmo AreasFigurasPlanas
	Escribir "Ingrese los lados del triangulo escaleno (a, b, c) y el lado del hex�gono regular: "
	Leer a, b, c, l
	s <- (a + b + c) / 2
	areaTriangulo <- rc(s * (s - a) * (s - b) * (s - c))
	areaHexagono <- (3 * l^2) / (2 * tan(30 * PI / 180))
	Si areaTriangulo > areaHexagono Entonces
		Escribir "El tri�ngulo posee mayor area."
	Sino 
		Escribir "El hex�gono posee mayor area. "
	FinSi
	
FinAlgoritmo
