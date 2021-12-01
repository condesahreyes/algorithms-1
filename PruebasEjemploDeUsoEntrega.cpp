
#include "PruebasEjemploDeUsoEntrega.h"

PruebasEjemploDeUsoEntrega::PruebasEjemploDeUsoEntrega(ConductorPrueba* conductor)
:Prueba(conductor)
{

}

PruebasEjemploDeUsoEntrega::~PruebasEjemploDeUsoEntrega()
{
	
}

const char* PruebasEjemploDeUsoEntrega::getNombre() const
{
	return "PruebasEjemploDeUsoEntrega";
}

void PruebasEjemploDeUsoEntrega::correrPruebaConcreta()
{
	PruebasEjerciciosTAD();

	pruebasListaOrdInt(this);
	pruebasListaPosInt(this);
	pruebasPilaInt(this);
	pruebasColaInt(this);
	pruebasDiccionarioInt(this);
	pruebasTablaIntString(this);
	pruebasMultisetInt(this);
	pruebasColaPrioridadInt(this);

	//pruebasTablaIntInt(this);
	//pruebasSetInt(this);
}

void PruebasEjemploDeUsoEntrega::PruebasEjerciciosTAD()
{

	// Pruebas Enlistar
	this->mImpresion.iniciarSeccion("PRUEBAS Enlistar");
	pruebaEnlistar("{2,1,5}");
	ver3("Prueba de pasar ABB a ListaOrd 1");

	pruebaEnlistar("{1,#,2,#,5}");
	ver3("Prueba de pasar ABB a ListaOrd 2");

	pruebaEnlistar("{1,#,2,#,15,10,20,8,#,16,30,7,9,#,18}");
	ver3("Prueba de pasar ABB a ListaOrd 3");
	this->mImpresion.cerrarSeccion("PRUEBAS Enlistar");


	// Pruebas UnionListaOrd
	this->mImpresion.iniciarSeccion("PRUEBAS UnionListaOrd");
	pruebaUnionListaOrd("(1,3,5,7,9)", "(2,4,6,8)");
	ver3("Prueba union de dos listas ordenadas 1");
	
	pruebaUnionListaOrd("(100,200,300,400)", "(100,200,300,400)");
	ver3("Prueba union de dos listas ordenadas 2");

	pruebaUnionListaOrd("()", "(-1,0,1,5)");
	ver3("Prueba union de dos listas ordenadas 3");
	this->mImpresion.cerrarSeccion("PRUEBAS UnionListaOrd");


	// Pruebas EstaContenida
	this->mImpresion.iniciarSeccion("PRUEBAS EstaContenida");
	pruebaEstaContenida("(1,7,4,2)", "(7,3,2,1)");
	ver3("Prueba de pila contenida 1");
	
	pruebaEstaContenida("(1,7,4,2)", "(7,3,2,1,4,8)");
	ver3("Prueba de pila contenida 2");

	pruebaEstaContenida("(1,7,4,2,7,4,4,7)", "(7,3,7,2,4,1,4,8)");
	ver3("Prueba de pila contenida 3");

	pruebaEstaContenida("(1,7,4,2,7,4,4,7)", "(7,3,7,2,4,4,4,7,1,4,8)");
	ver3("Prueba de pila contenida 4");
	this->mImpresion.cerrarSeccion("PRUEBAS EstaContenida");



	// Pruebas ObtenerRepetidos
	this->mImpresion.iniciarSeccion("PRUEBAS ObtenerRepetidos");
	pruebaObtenerRepetidos("(1, 1, 2)");
	ver3("Prueba ObtenerRepetidos 1");
	pruebaObtenerRepetidos("()");
	ver3("Prueba ObtenerRepetidos 2");
	pruebaObtenerRepetidos("(1, 2, 3, 2, 1)");
	ver3("Prueba ObtenerRepetidos 3");
	pruebaObtenerRepetidos("(10, 4, 6, 1, 1, 10, 5, 8)");
	ver3("Prueba ObtenerRepetidos 4");
	pruebaObtenerRepetidos("(4)");
	ver3("Prueba ObtenerRepetidos 5");
	pruebaObtenerRepetidos("(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)");
	ver3("Prueba ObtenerRepetidos 6");
	pruebaObtenerRepetidos("(1, 1, 1, 1, 1, 1)");
	ver3("Prueba ObtenerRepetidos 7");
	pruebaObtenerRepetidos("(1, 10, 100, 1000)");
	ver3("Prueba ObtenerRepetidos 8");
	pruebaObtenerRepetidos("(4, 6, 4, 6, 4, 6, 4, 6)");
	ver3("Prueba ObtenerRepetidos 9");
	pruebaObtenerRepetidos("(1, 2, 1, 4, 2, 1, 4, 2, 7)");
	ver3("Prueba ObtenerRepetidos 10");
	pruebaObtenerRepetidos("(6, 6)");
	ver3("Prueba ObtenerRepetidos 11");
	pruebaObtenerRepetidos("(6, 6, 6, 7, 7, 7)");
	ver3("Prueba ObtenerRepetidos 12");
	this->mImpresion.cerrarSeccion("PRUEBAS ObtenerRepetidos");


	// Pruebas Xor
	this->mImpresion.iniciarSeccion("PRUEBAS Xor de multisets");
	pruebaXor("()", "()");
	ver3("Prueba Xor de multisets 1");  //()
	pruebaXor("(1,2,3)", "(3,2,1)");
	ver3("Prueba Xor de multisets 2");  //()
	pruebaXor("(1,2,3)", "()");
	ver3("Prueba Xor de multisets 3");  //(1,2,3)
	pruebaXor("()", "(3,2,1)");
	ver3("Prueba Xor de multisets 4");  //(3,2,1)
	pruebaXor("(1,3,4,7)", "(8,1,2,3)");  //(4,7,8,2)
	ver3("Prueba Xor de multisets 5");
	pruebaXor("(1,1,2)", "(1,2)");  //(1)
	ver3("Prueba Xor de multisets 6");
	pruebaXor("(1,1,2,3,3,3)", "(1,3)");  //(1,2,3,3)
	ver3("Prueba Xor de multisets 7");
	pruebaXor("(1,1,1)", "()");  //(1,1,1)
	ver3("Prueba Xor de multisets 8");
	pruebaXor("(1,1,1)", "(5)");  //(1,1,1,5)
	ver3("Prueba Xor de multisets 9");
	pruebaXor("(1,1,1,0)", "(1,1,1)");  //(0)
	ver3("Prueba Xor de multisets 10");
	this->mImpresion.cerrarSeccion("PRUEBAS Xor de multisets");

	this->mImpresion.iniciarSeccion("PRUEBAS pruebaMenorPrioridad");
	pruebaMenorPrioridad("()", "()");
	ver3("Prueba pruebaMenorPrioridad 1");
	pruebaMenorPrioridad("(4,2,3,1)", "(1,3,2,4)");
	ver3("Prueba pruebaMenorPrioridad 2");
	pruebaMenorPrioridad("(5,9,2,-3,5,7,9,-2,1,-1)", "(5,6,2,3,8,2,4,-4,2,-1)");
	ver3("Prueba pruebaMenorPrioridad 3");
	pruebaMenorPrioridad("(6,30,4,-10,9)", "(-1,0,7,-1,9)");
	ver3("Prueba pruebaMenorPrioridad 4");
	pruebaMenorPrioridad("(15,-4,3,-3,-2,12,5,7,6,9,-3,-5,1)", "(5,4,4,3,2,2,2,1,2,4,3,5,1)");
	ver3("Prueba pruebaMenorPrioridad 5");
	pruebaMenorPrioridad("(2,2,4,4)", "(4,4,4,4)");
	ver3("Prueba pruebaMenorPrioridad 6");
	pruebaMenorPrioridad("(2,1,7,6,8)", "(4,4,5,4,4)");
	ver3("Prueba pruebaMenorPrioridad 7");
	pruebaMenorPrioridad("(9,8,7,5,3,2,5,4,1,3)", "(-1,-2,-3,-4,-5,-6,-7,-8,-9,-10)");
	ver3("Prueba pruebaMenorPrioridad 8");
	pruebaMenorPrioridad("(1)", "(-1)");
	ver3("Prueba pruebaMenorPrioridad 9");
	pruebaMenorPrioridad("(1,2,3,4,5,6,7,8,9)", "(1,-1,-2,1,-1,-2,-2,-1,1)");
	ver3("Prueba pruebaMenorPrioridad 10");
	this->mImpresion.cerrarSeccion("PRUEBAS pruebaMenorPrioridad");





/*
	// Pruebas ContarOcurrencias
	this->mImpresion.iniciarSeccion("PRUEBAS ContarOcurrencias");
	pruebaContarOcurrencias("(1, 1, 2)");
	ver3("Prueba ContarOcurrencias 1");
	pruebaContarOcurrencias("()");
	ver3("Prueba ContarOcurrencias 2");
	pruebaContarOcurrencias("(1, 2, 3, 2, 1)");
	ver3("Prueba ContarOcurrencias 3");
	pruebaContarOcurrencias("(10, 1, 1, 1, 1, 10, 5, 8)");
	ver3("Prueba ContarOcurrencias 4");
	pruebaContarOcurrencias("(1)");
	ver3("Prueba ContarOcurrencias 5");
	pruebaContarOcurrencias("(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)");
	ver3("Prueba ContarOcurrencias 6");
	pruebaContarOcurrencias("(1, 1, 1, 1, 1, 1)");
	ver3("Prueba ContarOcurrencias 7");
	pruebaContarOcurrencias("(1, 10, 100, 1000)");
	ver3("Prueba ContarOcurrencias 8");
	pruebaContarOcurrencias("(4, 6, 4, 6, 4, 6, 4, 6)");
	ver3("Prueba ContarOcurrencias 9");
	pruebaContarOcurrencias("(1, 2, 1, 4, 2, 1, 4, 2, 7)");
	ver3("Prueba ContarOcurrencias 10");
	this->mImpresion.cerrarSeccion("PRUEBAS ContarOcurrencias");

	this->mImpresion.iniciarSeccion("PRUEBAS pruebaSimetricas");
	pruebaSimetricas("(1,2,3)", "(5,4,6)", "(4,5,6)", "(1,3,2)");
	ver3("Prueba pruebaSimetricas 1");
	pruebaSimetricas("(1)", "(2)", "(1)", "(2)");
	ver3("Prueba pruebaSimetricas 2");
	pruebaSimetricas("(1,2,3,4)", "(5,6,7,8)", "(6,7,8,5)", "(4,3,2,1)");
	ver3("Prueba pruebaSimetricas 3");
	pruebaSimetricas("(2)", "(1)", "(1)", "(2)");
	ver3("Prueba pruebaSimetricas 4");
	pruebaSimetricas("(1)", "(2)", "(3,2)", "(1,2)");
	ver3("Prueba pruebaSimetricas 5");
	pruebaSimetricas("()", "()", "()", "()");
	ver3("Prueba pruebaSimetricas 6");
	pruebaSimetricas("(1,2,3,4)", "(1,2,3,4)", "(1)", "(2)");
	ver3("Prueba pruebaSimetricas 7");
	pruebaSimetricas("(1)", "(1)", "()", "()");
	ver3("Prueba pruebaSimetricas 8");
	pruebaSimetricas("(1)", "(1)", "(1)", "(1)");
	ver3("Prueba pruebaSimetricas 9");
	pruebaSimetricas("(1,2,3,4)", "(5,6,7,8)", "(5,6,7,8)", "(1,2,3,4)");
	ver3("Prueba pruebaSimetricas 10");
	pruebaSimetricas("(1,2)", "(3,4)", "(4,3)", "(2,1)");
	ver3("Prueba pruebaSimetricas 11");
	this->mImpresion.cerrarSeccion("PRUEBAS pruebaSimetricas");

	// Pruebas CantidadDeHojas
	this->mImpresion.iniciarSeccion("PRUEBAS CantidadDeHojas");
	pruebaCantidadDeHojas("{1,5,2}");
	ver3("Prueba contar hojas AB iterativo 1");

	pruebaCantidadDeHojas("{1,#,2,#,5}");
	ver3("Prueba contar hojas AB iterativo 2");

	pruebaCantidadDeHojas("{1,2,3,1,#,#,#,#,3,1,2,1,1,#,#,#,#,#,4,1,#,2,2}");
	ver3("Prueba contar hojas AB iterativo 3");
	this->mImpresion.cerrarSeccion("PRUEBAS CantidadDeHojas");


	// Pruebas ImprimirPorNiveles
	this->mImpresion.iniciarSeccion("PRUEBAS ImprimirPorNiveles");
	pruebaImprimirPorNiveles("{1,5,2}");
	ver3("Prueba imprimir AB por niveles 1");

	pruebaImprimirPorNiveles("{1,#,2,#,5}");
	ver3("Prueba imprimir AB por niveles 2");

	pruebaImprimirPorNiveles("{1,2,3,1,#,#,#,#,3,1,2,1,1,#,#,#,#,#,4,1,#,2,2}");
	ver3("Prueba imprimir AB por niveles 3");
	this->mImpresion.cerrarSeccion("PRUEBAS ImprimirPorNiveles");

	// Pruebas parentesisBalanceados
	this->mImpresion.iniciarSeccion("PRUEBAS Paréntesis Balanceados");
	pruebaParentesisBalanceados("{(1,3),(4,5)}++{[1,3,4]}");
	ver3("Prueba parentesisBalanceados 1");
	pruebaParentesisBalanceados("((5*2)+(2-a)+b)");
	ver3("Prueba parentesisBalanceados 2");
	pruebaParentesisBalanceados("((a&&b)||((!c)&&(d&&!e)))");
	ver3("Prueba parentesisBalanceados 3");
	pruebaParentesisBalanceados("((a&&b)||((!c)&&(d&&!e))");
	ver3("Prueba parentesisBalanceados 4");
	pruebaParentesisBalanceados("((a&&b)||((!c)))&&)(d&&!e");
	ver3("Prueba parentesisBalanceados 5");
	pruebaParentesisBalanceados("())(");
	ver3("Prueba parentesisBalanceados 6");
	pruebaParentesisBalanceados("{(1,3),(4,5)}++1,3,4]}");
	ver3("Prueba parentesisBalanceados 7");
	pruebaParentesisBalanceados("[(1+3){]}");
	ver3("Prueba parentesisBalanceados 8");
	pruebaParentesisBalanceados("[(13)+{1,2,3}]");
	ver3("Prueba parentesisBalanceados 9");
	pruebaParentesisBalanceados("{[((({}+{})))]()})");
	ver3("Prueba parentesisBalanceados 10");
	this->mImpresion.cerrarSeccion("PRUEBAS Paréntesis Balanceados");

	// Pruebas ImprimirPorNiveles
	this->mImpresion.iniciarSeccion("PRUEBAS ImprimirPorNiveles AG");
	pruebaImprimirPorNivelesAG("{{}}");
	ver3("Prueba imprimir AG por niveles 1");

	pruebaImprimirPorNivelesAG("{{1,-7,5,#,15,#,#,3,#,4,8,34}}");
	ver3("Prueba imprimir AG por niveles 2");

	pruebaImprimirPorNivelesAG("{{1,-7,5,1,#,#,15,#,#,3,#,4,8,34,#,#,7,24,13,#,7,1,#,#,#,#,2}}");
	ver3("Prueba imprimir AG por niveles 3");

	this->mImpresion.cerrarSeccion("PRUEBAS ImprimirPorNiveles AG");
*/
}


