Algoritmo gapfulNumber
	Escribir "Ingrese el valor del número a evaluar "
	Leer numero1
	valor1 <- trunc(numero1 / 100)
	valor3 <- (numero1 MOD 100) MOD 10
	divisor <- valor1*10 + valor3
	modulo <- numero1 MOD divisor
	esUnNumeroGapful <- modulo = 0
	Escribir "El número ", numero1, " es un numero gapful ", esUnNumeroGapful, " porque el residuo de dividir ", numero1, " entre ", divisor, " formado por ", valor1 " y ", valor3 " es ", modulo
	
FinAlgoritmo
