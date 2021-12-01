#include "MultisetInt.h"

#ifdef MULTISET_INT_IMP

struct NodoMultiSet {
	int dato;
	int ocurrencias;
	NodoMultiSet* sig;
	NodoMultiSet(int dato, int ocurrencias, NodoMultiSet* sig) { this->dato = dato; this->ocurrencias = ocurrencias; this->sig = sig; };
};

struct _cabezalMultisetInt {
	NodoMultiSet* principio;
	int cantidad;
	_cabezalMultisetInt(NodoMultiSet* principio, int cantidad) { this->principio = principio; this->cantidad = cantidad; }
};

//*******************Funciones auxiliares*******************

void agregarUnionConjutnos(int dato, int ocurrencias, NodoMultiSet*& nuevo, NodoMultiSet*& auxNuevo) {
	if (!nuevo) {
		nuevo = new NodoMultiSet(dato, ocurrencias, nullptr);
		auxNuevo = nuevo;
	}
	else {
		auxNuevo->sig = new NodoMultiSet(dato, ocurrencias, nullptr);
		auxNuevo = auxNuevo->sig;
	}

}

//*******************Fin funciones auxiliares*******************

MultisetInt crearMultisetInt() {
	return new _cabezalMultisetInt(NULL, 0);
}

void agregar(MultisetInt& s, int e, unsigned int ocurrencias) {
	NodoMultiSet* aux = s->principio;
	s->cantidad = s->cantidad + ocurrencias;
	NodoMultiSet* anterior = NULL;
	while (aux && aux->dato <= e) {
		anterior = aux;
		if (aux->dato == e) {
			aux->ocurrencias += ocurrencias;
			return;
		}
		aux = aux->sig;
	}
	if (anterior)
		anterior->sig = new NodoMultiSet(e, ocurrencias, aux);
	else
		s->principio = new NodoMultiSet(e, ocurrencias, aux);
}

void borrar(MultisetInt& s, int e) {
	NodoMultiSet* aux = s->principio;
	if (aux && aux->dato == e) {
		s->cantidad--;
		if (aux->ocurrencias > 1)
			aux->ocurrencias--;
		else {
			NodoMultiSet* borrar = aux;
			aux = aux->sig;
			s->principio = aux;
			delete borrar;
			borrar = NULL;
		}
	}
	else {
		while (aux->sig) {
			if (aux->sig->dato == e) {
				if (aux->sig->ocurrencias > 1)
					aux->sig->ocurrencias--;
				else {
					NodoMultiSet* borrar = aux->sig;
					aux->sig = aux->sig->sig;
					delete borrar;
					borrar = NULL;
				}
				s->cantidad--;
				return;
			}
			aux = aux->sig;
		}
	}
}

bool pertenece(MultisetInt s, int e) {
	NodoMultiSet* aux = s->principio;
	while (aux && aux->dato <= e) {
		if (aux->dato == e)
			return true;
		aux = aux->sig;
	}
	return false;
}

MultisetInt unionConjuntos(MultisetInt s1, MultisetInt s2) {
	NodoMultiSet* nuevo = NULL;
	NodoMultiSet* auxNuevo = NULL;
	MultisetInt retornar = new _cabezalMultisetInt(nuevo, 0);
	NodoMultiSet* auxs1 = s1->principio;
	NodoMultiSet* auxs2 = s2->principio;
	while (auxs1 && auxs2) {
		if (auxs1->dato < auxs2->dato) {
			retornar->cantidad += auxs1->ocurrencias;
			agregarUnionConjutnos(auxs1->dato, auxs1->ocurrencias, nuevo, auxNuevo);
			auxs1 = auxs1->sig;
		}
		else if (auxs1->dato > auxs2->dato) {
			retornar->cantidad += auxs2->ocurrencias;
			agregarUnionConjutnos(auxs2->dato, auxs2->ocurrencias, nuevo, auxNuevo);
			auxs2 = auxs2->sig;
		}
		else {
			int ocurrencias = auxs1->ocurrencias < auxs2->ocurrencias ? auxs2->ocurrencias : auxs1->ocurrencias;
			retornar->cantidad += ocurrencias;
			agregarUnionConjutnos(auxs1->dato, ocurrencias, nuevo, auxNuevo);
			auxs1 = auxs1->sig;
			auxs2 = auxs2->sig;
		}
	}
	while (auxs1) {
		retornar->cantidad += auxs1->ocurrencias;
		agregarUnionConjutnos(auxs1->dato, auxs1->ocurrencias, nuevo, auxNuevo);
		auxs1 = auxs1->sig;
	}
	while (auxs2) {
		retornar->cantidad += auxs2->ocurrencias;
		agregarUnionConjutnos(auxs2->dato, auxs2->ocurrencias, nuevo, auxNuevo);
		auxs2 = auxs2->sig;
	}
	retornar->principio = nuevo;
	return retornar;
}

MultisetInt interseccionConjuntos(MultisetInt s1, MultisetInt s2) {
	NodoMultiSet* nuevo = NULL;
	NodoMultiSet* auxNuevo = NULL;
	MultisetInt retornar = new _cabezalMultisetInt(nuevo, 0);
	NodoMultiSet* auxs1 = s1->principio;
	NodoMultiSet* auxs2 = s2->principio;
	while (auxs1 && auxs2) {
		if (auxs1->dato < auxs2->dato) {
			auxs1 = auxs1->sig;
		}
		else if (auxs1->dato > auxs2->dato) {
			auxs2 = auxs2->sig;
		}
		else {
			int ocurrencias;
			auxs1->ocurrencias < auxs2->ocurrencias ? ocurrencias = auxs1->ocurrencias : ocurrencias = auxs2->ocurrencias;
			retornar->cantidad += ocurrencias;
			agregarUnionConjutnos(auxs1->dato, ocurrencias, nuevo, auxNuevo);
			auxs1 = auxs1->sig;
			auxs2 = auxs2->sig;
		}
	}
	retornar->principio = nuevo;
	return retornar;
}

MultisetInt diferenciaConjuntos(MultisetInt s1, MultisetInt s2) {
	NodoMultiSet* nuevo = NULL;
	NodoMultiSet* auxNuevo = NULL;
	MultisetInt retornar = new _cabezalMultisetInt(nuevo, 0);
	NodoMultiSet* auxs1 = s1->principio;
	NodoMultiSet* auxs2 = s2->principio;
	while (auxs1 && auxs2) {
		if (auxs1->dato < auxs2->dato) {
			retornar->cantidad += auxs1->ocurrencias;
			agregarUnionConjutnos(auxs1->dato, auxs1->ocurrencias, nuevo, auxNuevo);
			auxs1 = auxs1->sig;
		}
		else if (auxs1->dato > auxs2->dato) {
			auxs2 = auxs2->sig;
		}
		else {
			if (auxs1->ocurrencias > auxs2->ocurrencias) {
				int ocurrencias = auxs1->ocurrencias - auxs2->ocurrencias;
				retornar->cantidad += ocurrencias;
				agregarUnionConjutnos(auxs1->dato, ocurrencias, nuevo, auxNuevo);
			}
			auxs1 = auxs1->sig;
			auxs2 = auxs2->sig;
		}
	}
	while (auxs1) {
		retornar->cantidad += auxs1->ocurrencias;
		agregarUnionConjutnos(auxs1->dato, auxs1->ocurrencias, nuevo, auxNuevo);
		auxs1 = auxs1->sig;
	}
	retornar->principio = nuevo;
	return retornar;
}

bool contenidoEn(MultisetInt s1, MultisetInt s2) {
	NodoMultiSet* auxs1 = s1->principio;
	NodoMultiSet* auxs2 = s2->principio;
	while (auxs1 && auxs2) {
		if (auxs1->dato > auxs2->dato)
			auxs2 = auxs2->sig;
		else if (auxs1->dato < auxs2->dato)
			return false;
		else {
			if (auxs1->ocurrencias > auxs2->ocurrencias)
				return false;
			auxs1 = auxs1->sig;
			auxs2 = auxs2->sig;
		}
	}
	if (auxs1 && !auxs2)return false;
	return true;
}

int elemento(MultisetInt s) {
	return s->principio->dato;
}

bool esVacio(MultisetInt s) {

	return !s || s->principio == NULL;
}

unsigned int cantidadElementos(MultisetInt s) {

	return s->cantidad;
}

void destruir(MultisetInt& s) {
	NodoMultiSet* aux = s->principio;
	while (aux) {
		NodoMultiSet* borrar = aux;
		aux = aux->sig;
		delete borrar;
		borrar = NULL;
	}
	s->cantidad = 0;
}

MultisetInt clon(MultisetInt s) {
	MultisetInt retornar = new _cabezalMultisetInt(NULL, s->cantidad);
	NodoMultiSet* aux = s->principio;
	NodoMultiSet* nuevo = NULL;
	NodoMultiSet* nuevoAux = NULL;
	while (aux) {
		agregarUnionConjutnos(aux->dato, aux->ocurrencias, nuevo, nuevoAux);
		aux = aux->sig;
	}
	retornar->principio = nuevo;
	return retornar;
}

#endif