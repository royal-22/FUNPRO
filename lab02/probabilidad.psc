Algoritmo ProbabilidadP
	Escribir "Ingrese el valor de x: "
	Leer x
	Escribir "Ingrese el valor de mu: "
	Leer mu
	Escribir "Ingrese el valor de omega: "
	Leer omega
	
	probabilidad <- 1 /(omega * rc(2 * PI)) * Euler^(-1 * ((x - mu)^2 / (2 * omega^2)))
	
	Escribir "La probabilida es ", probabilidad
	
FinAlgoritmo
