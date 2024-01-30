Algoritmo sin_titulo
	Escribir "Ingrese coordenadas punto A: "
	Leer xA, yA
	Escribir "Ingrese coordenadas punto B: "
	Leer xB, yB
	Escribir "Ingrese coordenadas punto C: "
	Leer xC, yC
	mAB <- (yA- yB) / (xA - xB)
	mBC <- (yC - yB) / (xC - xB)
	perpendicularesAB_BC <- mAB = mBC
	Si perpendicularesAB_BC Entonces
		Escribir "Ingrese coodernadas punto D: "
		Leer xD, yD
		mCD <- (yD - yC) / (xD - xC)
		mDA <- (yA - yD) / (xA - xD)
		
		paralelasAB_CD <- mAB = mCD
		paralelasBC_DA <- mBC = mDA
		Si paralelasAB_CD y paralelasBC_DA Entonces
			Escribir"Los puntos forman un rectángulo"
		Sino 
			Escribir "Las rectas (AB, CD) o (BC, DA) no son perpendiculares"
		FinSi
	Sino 
		Escribir "Las rectas AB y BC no son perpendiculares"
	FinSi
	
	
	
	
	
	
	perpendicularesBC_CD <- 
FinAlgoritmo
