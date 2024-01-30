Algoritmo poker
	Escribir "Ingrese carta1: "
	Leer carta1
	Escribir "Ingrese carta2: "
	Leer carta2
	Escribir "Ingrese carta2: "
	Leer carta3
	Escribir "Ingrese carta2: "
	Leer carta4
	Escribir "Ingrese carta2: "
	Leer carta5
	
	validaCarta1 <- carta1 > 0 y carta1 <= 13
	validaCarta2 <- carta2 > 0 y carta2 <= 13
	validaCarta3 <- carta3 > 0 y carta3 <= 13
	validaCarta4 <- carta3 > 0 y carta3 <= 13
	validaCarta5 <- carta3 > 0 y carta3 <= 13

	
	Si validaCarta1 y validaCarta2 y validaCarta3 y validaCarta4 y validaCarta5 Entonces
		Si carta1 >= carta2 y carta1 >= carta3 y carta1 >= carta4 y carta1 >= carta5 Entonces
			cartaMayor <- carta1
		Sino 
			Si carta2 >= carta1 y carta2 >= carta3 y carta2 >= carta4 y carta2 >= carta5 Entonces
				cartaMayor <- carta2
			Sino 
				Si carta3 >= carta1 y carta3 >= carta2 y carta3 >= carta4 y carta3 >= carta5 Entonces
					cartaMayor <- carta3
				Sino 
					Si carta4 >= carta1 y carta4 >= carta2 y carta4 >= carta3 y carta4 >= carta5 Entonces
						cartaMayor <- carta4
					SiNo
						cartaMayor <- carta5
					FinSi
				FinSi
			FinSi
		FinSi
		hayAs <- carta1 = 1 o carta2 = 1 o carta3 = 1 o carta3 = 1 o carta3 = 1
		
		consecutivo1 <- carta1 = cartaMayor - 1 o carta2 = cartaMayor - 1 o carta3 = cartaMayor - 1 o carta4 = cartaMayor - 1 o carta5 = cartaMayor - 1 
		consecutivo2 <- carta2 = cartaMayor - 2 o carta1 = cartaMayor - 2 o carta3 = cartaMayor - 2 o carta4 = cartaMayor - 2 o carta5 = cartaMayor - 2 
		consecutivo3 <- carta2 = cartaMayor - 3 o carta1 = cartaMayor - 3 o carta3 = cartaMayor - 3 o carta4 = cartaMayor - 3 o carta5 = cartaMayor - 3
		consecutivo4 <- carta2 = cartaMayor - 4 o carta1 = cartaMayor - 4 o carta3 = cartaMayor - 4 o carta4 = cartaMayor - 4 o carta5 = cartaMayor - 4
		Si hayAs y consecutivo1 y consecutivo2 y consecutivo3 y cartaMayor = 13 Entonces
			Escribir "Hay escalera real"
		Sino 
			Si consecutivo1 y consecutivo2 y consecutivo3 y consecutivo4 Entonces
				Escribir "Hay escalera simple"
			SiNo
				Escribir "No hay escalera real ni simple"
			FinSi
		FinSi
	Sino 
		Escribir "El valor de alguna carta es incorrecto. "
	FinSi

	
	
	
FinAlgoritmo
