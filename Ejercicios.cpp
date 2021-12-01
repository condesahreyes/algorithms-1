#include "Ejercicios.h"

void EnlistarAux(ListaOrdInt& lista, NodoABInt* a) {

	if (!a)return;
	agregar(lista, a->dato);
	EnlistarAux(lista, a->der);
	EnlistarAux(lista, a->izq);

}

ListaOrdInt Enlistar(NodoABInt* a)
{
	if (!a)return NULL;
	ListaOrdInt nuevo = crearListaOrdInt();
	EnlistarAux(nuevo, a);
	return nuevo;
}

void agregarPorMinimo(ListaOrdInt& nuevo, ListaOrdInt l) {
	while (!esVacia(l)) {
		agregar(nuevo, minimo(l));
		borrarMinimo(l);
	}
}

ListaOrdInt UnionListaOrd(ListaOrdInt l1, ListaOrdInt l2)
{
	ListaOrdInt nuevo = crearListaOrdInt();
	agregarPorMinimo(nuevo, l1);
	agregarPorMinimo(nuevo, l2);
	return nuevo;
}

MultisetInt pilaMultiSet(PilaInt p1) {
	MultisetInt nuevo = crearMultisetInt();
	while (!esVacia(p1)) {
		agregar(nuevo, top(p1), 1);
		pop(p1);
	}
	return nuevo;
}

bool EstaContenida(PilaInt p1, PilaInt p2)
{
	if (cantidadElementos(p1) > cantidadElementos(p2))return false;
	MultisetInt p1M = pilaMultiSet(p1);
	MultisetInt p2M = pilaMultiSet(p2);
	return contenidoEn(p1M, p2M);
}


ListaOrdInt ObtenerRepetidos(MultisetInt m)
{
	MultisetInt aux = clon(m);
	ListaOrdInt retornar = crearListaOrdInt();
	while (!esVacio(aux)) {
		int elem = elemento(aux);
		borrar(aux, elem);
		if (pertenece(aux, elem)) {
			agregar(retornar, elem);
			while (pertenece(aux, elem)) 
				borrar(aux, elem);
		}

	}
	return retornar;
}

MultisetInt Xor(MultisetInt m1, MultisetInt m2)
{
	MultisetInt unionAux = unionConjuntos(m1, m2);
	MultisetInt interseccionAux = interseccionConjuntos(m1, m2);
	return diferenciaConjuntos(unionAux, interseccionAux);
}

ColaPrioridadInt MenorPrioridad(ColaPrioridadInt c) {
	ColaPrioridadInt aux = clon(c);
	ColaPrioridadInt retornar = crearColaPrioridadInt();
	while (!esVacia(aux)) {
		int prioridad = principioPrioridad(aux);
		if (esVacia(retornar) || principioPrioridad(retornar) == prioridad) {
			encolar(retornar, principio(aux), prioridad);
			desencolar(aux);
		}
		else {
			while (!esVacia(retornar))
				desencolar(retornar);
			encolar(retornar, principio(aux), prioridad);
			desencolar(aux);
		}
	}
	return retornar;
}

