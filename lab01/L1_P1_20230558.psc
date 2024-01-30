Algoritmo MRUV
	// Nombre: Luciana Carrillo Pe�a
	// C�digo: 20230558
	VelocidadInicial <- 50.6 
	tiempo <- 12
	VelocidadFinal <- 85.4 
	// VelocidadInicial y VelocidadFinal en km/h pasar a m/s
	VelocidadFinal_m <- VelocidadFinal / 3600  * 1000
	VelocidadInicial_m <- VelocidadInicial / 3600 * 1000
	// Hallar la aceleraci�n y la distancia total recorrida
	aceleracion <- (VelocidadFinal_m - VelocidadInicial_m) / tiempo
	distanciaTotal <- VelocidadInicial_m * tiempo + 0.5 * aceleracion * tiempo^2
	Escribir "La aceleraci�n es: ", aceleracion, " m/s y la distancia es: ", distanciaTotal, " metros"
FinAlgoritmo

