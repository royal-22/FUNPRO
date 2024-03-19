Algoritmo VAN
	Escribir "Cantidad de proyectos de inversión: "
	Leer proyectos
	Escribir "Ingresar la inversión inicial: "
	Leer inversionInicial
	Escribir "Cantidad de años: "
	Leer anos
	Si anos > 0 y inversionInicial > 0 y proyectos > 0 Entonces
		i <- 1
		mejorVan <- 0
		valorMejorVan <- 0
		Mientras i <= proyectos Hacer
			j <- 1 
			Escribir "Proyecto [", i, "]"
			Escribir "La tasa de retorno en %: "
			Leer tasaRetorno
			valorVan <- 0
			Mientras j <= anos Hacer
				Escribir "año [", j, "]"
				Escribir "flujo beneficio (+)"
				Leer flujoBeneficio
				Escribir "flujo costo (-)"
				Leer flujoCosto
				flujoNeto <- flujoBeneficio - flujoCosto 
				valorVan <- valorVan + flujoNeto / (1 + tasaRetorno/100)^j 
				Escribir valorVan
				j <- j + 1
			FinMientras
			valorVan <- valorVan - inversionInicial
			Escribir "El valor del VAN es: ", valorVan
			Si valorVan > valorMejorVan Entonces
				mejorVan <- i
				valorMejorVan <- valorVan
				tasaMejorVan <- tasaRetorno
			FinSi
			i <- i + 1
		FinMientras
		copiaMejorVan <- trunc(valorMejorVan) 
		Si mejorVan > 0 Entonces
			binario <- 0
			exponente <- 0
			Mientras copiaMejorVan > 0 Hacer
				dig <- copiaMejorVan MOD 4
				copiaMejorVan <- trunc(copiaMejorVan / 4)
				binario <- binario + dig * 10^(exponente)
				exponente <- exponente + 1
			FinMientras
			Escribir "El proyecto [", mejorVan, "] es el mejor con una tasa de ", tasaMejorVan / 100
			Escribir "El valor del VAN es ", binario
		SiNo
			Escribir "Mejor no invertir en ningún proyecto."
		FinSi
	Sino 
		Escribir "La cantidad de proyectos, años y la inversión incial deben mayor a cero"
	FinSi
	
FinAlgoritmo
