Algoritmo circunferencia
	Escribir "Ingrese las coordenadas del centro de la circunferencia: "
	Leer centrox, centroy
	Si centrox > 0 y centroy > 0 Entonces
		Escribir "Ingrese el radio: "
		Leer radio
		Si radio > 0 Entonces
			Escribir "Ingrese las coordenadas del punto A: "
			Leer xA, yA
			Escribir "Ingrese las coordenadas del punto B: "
			Leer xB, yB
			Escribir "Ingrese las coordenadas del punto O: "
			Leer xO, yO
			
			aParteCircunferencia <- abs(((centrox - xA)^2 + (centroy - yA)^2) - radio^2) < 0.01
			bParteCircunferencia <- abs(((centrox - xB)^2 + (centroy - yB)^2) - radio^2) < 0.01
			oCentroCircunferencia <- (centrox = xO) y (centroy = yO)
			Escribir aParteCircunferencia
			Escribir bParteCircunferencia
			Escribir oCentroCircunferencia
			Si aParteCircunferencia y bParteCircunferencia Entonces
				Si oCentroCircunferencia Entonces
					Escribir "El vértice O y los puntos A y B forman un ángulo central"
					Escribir "Ingrese el ángulo central AOB (sexagesimales): "
					Leer angulo
					angulo <- angulo * PI / 180
					Si angulo > 0 Entonces
						perimetro <- rc((xA - xB)^2 + (yA - yB)^2) + 2 * radio
						area <- radio^2 * sen(angulo)
						Escribir "Perímetro: ", perimetro
						Escribir "Área: ", area
					Sino 
						Escribir "El ángulo AOB ingresado no es correcto"
					FinSi
				Sino 
					Escribir "El vértice O y los puntos A y B forman un ángulo inscrito"
				FinSi
			Sino 
				Si aParteCircunferencia y no bParteCircunferencia y no oCentroCircunferencia Entonces
					Escribir "El vértice O y los puntos A y B forman un ángulo semi-inscrito."
					distanciaBO <- rc((xB - xO)^2 + (yB - yO)^2)
					Escribir "El lado OB pertenece a la recta tangente y el lado AO pertenece a la recta secante. La distancia del lado OB que pertenece a la recta tangente es: ", distanciaBO
				Sino 
					Si no aParteCircunferencia y  bParteCircunferencia y no oCentroCircunferencia Entonces
						Escribir "El vértice O y los puntos B y A forman un ángulo semi-inscrito."
						distanciaOA <- rc((xA - xO)^2 + (yA - yO)^2)
						Escribir "El lado OB pertenece a la recta tangente y el lado AO pertenece a la recta secante. La distancia del lado OA que pertenece a la recta tangente es: ", distanciaOA
					Sino 
						Escribir "El vértice O y los puntos A y B no forman un ángulo descrito"
					FinSi
				FinSi
			FinSi
		Sino 
			Escribir "El radio de la circunferencia ingresado no es correcto"
		FinSi
	Sino 
		Escribir "El centro de la circunferencia no pertenece al primer cuadrante."
	FinSi
	
FinAlgoritmo
