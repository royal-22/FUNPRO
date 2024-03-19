Algoritmo EcuacionDeLaRecta
	Escribir "Ingrese el valor de la pendiente y el valor del punto de intersección: "
	Leer m, b
	Escribir "Ingrese los valores de la abcisa x y la ordenada y: "
	Leer x, y_
	
	Si x * m + b = y_ Entonces
		Escribir "El punto forma parte de la recta."
	Sino 
		Escribir "El punto no forma parte de la recta."
	FinSi
	
FinAlgoritmo
