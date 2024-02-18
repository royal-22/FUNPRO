Algoritmo codificacionJMB2
	centinela <- Verdadero
	Mientras centinela Hacer
		Escribir "Menú de opciones: "
		Escribir "1. Cifrar"
		Escribir "2. Descifrar"
		Escribir "3. Salir"
		Escribir "Ingrese su opcion: "
		Leer opc
		Si (opc <= 3 y opc >= 1) Entonces
			Si opc = 3 Entonces
				centinela <- Falso
			Sino 
				Escribir "Si la opción no es 3 entonces ingrese la contraseña: "
				Leer contrasena
				existeCero <- Falso
				cantCifras <- 0
				copiaContrasena <- contrasena
				Mientras contrasena > 0 Hacer
					digito <- contrasena MOD 10
					contrasena <- trunc(contrasena / 10)
					Si digito = 0 Entonces
						existeCero <- Verdadero
					FinSi
					cantCifras <- cantCifras + 1
				FinMientras
				
				Si opc = 1 Entonces
					// Cifrar contraseña
					Si cantCifras >= 4 y cantCifras <= 6 y existeCero = Falso Entonces
						i <- 1
						contrasena <- copiaContrasena
						Mientras i <= cantCifras Hacer
							digito <- trunc(contrasena/10^(cantCifras - i))
							contrasena <- contrasena MOD 10^(cantCifras - i)
							Si i = 1 Entonces
								menorDigito <- digito 
								posDigito <- i
							Sino 
								Si digito < menorDigito Entonces
									menorDigito <- digito 
									posDigito <- i
								FinSi
							FinSi
							i <- i + 1
						FinMientras
						j <- 1
						contrasena <- copiaContrasena
						nuevoNum <- 0
						Mientras j <= cantCifras Hacer
							digito <- trunc(contrasena/10^(cantCifras - j))
							contrasena <- contrasena MOD 10^(cantCifras - j)
							escribir digito
							Si j <> posDigito Entonces
								digito <- digito - menorDigito
							FinSi
							nuevoNum <- nuevoNum + digito * 10^(cantCifras - j)
							j <- j + 1
						FinMientras
						nuevoNum <- nuevoNum + posDigito * 10^cantCifras
						Escribir nuevoNum
					Sino 
						Escribir "La contraseña es incorrecta"
					FinSi
				Sino
					// Descifrar contraseña
					Si cantCifras >= 5 y cantCifras <= 7 Entonces
						contrasena <- copiaContrasena
						i <- 1
						posMenor <- trunc(contrasena / 10^(cantCifras - 1))
						Mientras i <= posMenor+1 Hacer
							digito <- trunc(contrasena / 10^(cantCifras - i))
							contrasena <- contrasena MOD 10^(cantCifras - i)
							i <- i + 1
						FinMientras
						menorDigito <- digito
						contrasena <- copiaContrasena
						j <- 1
						Mientras j <= cantCifras Hacer
							digito <- trunc(contrasena / 10^(cantCifras - j))
							contrasena <- contrasena MOD 10^(cantCifras - j)
							Si j <> 1 y j <> posMenor + 1 Entonces
								escribir j
								digito <- digito + menorDigito
							FinSi
							
							Si j <> 1 Entonces
								nuevoNum <- nuevoNum + digito * 10^(cantCifras - j)
							FinSi
							j <- j + 1
						FinMientras
						Escribir nuevoNum
					Sino 
						Escribir "La contraseña es incorrecta"
					FinSi
				FinSi
			FinSi
		Sino 
			Escribir "Opción inválida"
		FinSi
	FinMientras
	
FinAlgoritmo
