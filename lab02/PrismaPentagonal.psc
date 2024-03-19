Algoritmo PrismaPentagonal
	Escribir "Ingrese el lado en pulgadas: "
	Leer ladoPulgadas
	Escribir "Ingrese la altura en pulgadas: "
	Leer alturaPulgadas
	area <- 6 * alturaPulgadas * ladoPulgadas + (ladoPulgadas^2 / 2) * rc(25 + 10 * rc(5))
	
	areaMetros <- area/1550
	galonesPintura <- areaMetros / 17.5
	Escribir "Área en metros cuadrados: ", areaMetros
	Escribir "Galones de pintura: ", galonesPintura
	
FinAlgoritmo
