Algoritmo moles
	Escribir "Ingrese el número de átomos del primer elemento de la solución: "
	Leer numeroAtomos1
	Escribir "Ingrese el número de átomos del segundo elemento de la solución: "
	Leer numeroAtomos2
	Escribir "Ingrese el número de átomos del tercer elemento de la solución: "
	Leer numeroAtomos3
	Escribir "Ingrese el peso atómico del primer elemento de la solución: "
	Leer pesoAtomico1
	Escribir "Ingrese el peso atómico del segundo elemento de la solución: "
	Leer pesoAtomico2
	Escribir "Ingrese el peso atómico del tercer elemento de la solución: "
	Leer pesoAtomico3
	
	Escribir "********* Experimento 1 **********"
	Escribir "Ingrese la masa del soluto de la solución en gramos: "
	Leer masaSoluto1
	Escribir "Ingrese el volumen de disolución en mililitros: "
	Leer volumen1
	
	volumen1 <- volumen1 * 0.001
	pesoMolar <- numeroAtomos1 * pesoAtomico1 + numeroAtomos2 * pesoAtomico2 + numeroAtomos3 * pesoAtomico3
	moles1 <- masaSoluto1 / pesoMolar
	molaridad1 <- moles1 / volumen1
	Escribir "Resultados del Experimento 1: "
	Escribir "Masa del soluto de la solución (en gramos): ", masaSoluto1
	Escribir "Volumen de la disolución (en litros): ", volumen1
	Escribir "Peso molecular (gramos/mol): ", pesoMolar
	Escribir "Numero de moles de la solución (moles): ", moles1
	Escribir "Molaridad de la solución (moles/Litros): ", molaridad1
	
	Escribir "********* Experimento 2 **********"
	Escribir "Ingrese la molaridad de la solución en moles/Litros: "
	Leer molaridad2
	Escribir "Ingrese el volumen de disolución en mililitros: "
	Leer volumen2
	
	volumen2 <- volumen2 * 0.001
	moles2 <- molaridad2 * volumen2
	masaSoluto2 <- moles2 * pesoMolar
	
	Escribir "Masa del soluto de la solución (en gramos): ", masaSoluto2
	Escribir "Volumen de la disolución (en litros): ", volumen2
	Escribir "Peso molecular (gramos/mol): ", pesoMolar
	Escribir "Numero de moles de la solución (moles): ", moles2
	Escribir "Molaridad de la solución (moles/Litros): ", molaridad2
	
	experimento1Mayor2 <- moles1 > moles2
	
	Escribir "¿El número de moles del experimento 1 es mayor que del experimento 2? ", experimento1Mayor2
FinAlgoritmo
