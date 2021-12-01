#include "ListaOrdInt.h"

#ifdef LISTA_ORD_INT_IMP_2

struct AB {
	AB* der;
	AB* izq;
	int dato;
	int cantidad;
	AB(int dato, int cantidad, AB* der, AB* izq) { this->der = der; this->izq = izq; this->dato = dato; this->cantidad = cantidad; }
};

struct _cabezalListaOrdInt {
	AB* cabeza;
	int largo;
	_cabezalListaOrdInt() { this->largo = 0; this->cabeza = nullptr; }
};

//*******************Funciones auxiliares*******************

AB*& ObtenerNodoMinimo(AB*& arb) {
	if (arb->izq) {
		ObtenerNodoMinimo(arb->izq);
	}
	return arb;
}

void EliminarRaiz(AB*& l) {
	if (l->cantidad == 1) {
		AB* borrar = l;
		if (l->der) {
			(ObtenerNodoMinimo(l->der))->izq = l->izq;
		}
		l = l->der;
		borrar->der = borrar->izq = NULL;
		delete borrar;
		borrar = NULL;
	}
	else {
		--l->cantidad;
	}
}

bool BorrarRec(AB*& l, int e) {
	if (l && l->dato == e) {
		EliminarRaiz(l);
		return true;
	}
	else if (l) {
		if (l->dato < e) {
			BorrarRec(l->der, e);
		}
		else {
			BorrarRec(l->izq, e);
		}
	}
	else {
		return false;
	}
}

void agregarAux(AB*& d, int e) {
	if (!d) 
		d = new AB(e, 1, nullptr, nullptr);
	else if (d->dato == e)
		d->cantidad++;
	else if (d->dato > e) 
		agregarAux(d->izq, e);
	else 
		agregarAux(d->der, e);
}

bool existeEnArbol(AB* a, int e) {
	if (!a) return false;
	if (a->dato == e)return true;
	if (a->dato < e)existeEnArbol(a->der, e);
	else if (a->dato > e) existeEnArbol(a->izq, e);
	else
		return false;
}

AB* clonArbol(AB* a) {
	if (!a) return NULL;
	AB* nuevo = new AB(a->dato, a->cantidad, clonArbol(a->der), clonArbol(a->izq));
	return nuevo;
}

void destruirArbol(AB*& a) {
	if (!a)return;
	if (a->der)
		destruirArbol(a->der);
	else if (a->izq)
		destruirArbol(a->izq);
	else {
		delete a;
		a = NULL;
	}
}
//*******************Fin funciones auxiliares*******************

ListaOrdInt crearListaOrdInt() {
	return new _cabezalListaOrdInt();
}

void agregar(ListaOrdInt& l, int e) {
	agregarAux(l->cabeza, e);
	l->largo++;
}

void borrarMinimo(ListaOrdInt& l) {
	if (!l || !l->cabeza)return;
	AB* aux = l->cabeza;
	AB* anterior = NULL;
	while (aux->izq) {
		anterior = aux;
		aux = aux->izq;
	}
	if (aux->cantidad > 1) {
		aux->cantidad--;
	}
	else {
		if (aux == l->cabeza) {
			l->cabeza = l->cabeza->der;
		}
		AB* borrar = aux;
		aux = aux->der;
		if (anterior) {
			anterior->izq = aux;
		}
		delete borrar;
		borrar = NULL;
	}
	l->largo--;
}

void borrarMaximo(ListaOrdInt& l) {
	if (!l || !l->cabeza)return;
	AB* aux = l->cabeza;
	AB* anterior = NULL;
	while (aux->der) {
		anterior = aux;
		aux = aux->der;
	}
	if (aux->cantidad > 1) {
		aux->cantidad--;
	}
	else {
		if (aux == l->cabeza) {
			l->cabeza = l->cabeza->izq;
		}
		AB* borrar = aux;
		aux = aux->izq;
		if (anterior) {
			anterior->der = aux;
		}
		delete borrar;
		borrar = NULL;
	}
	l->largo--;
}

void borrar(ListaOrdInt& l, int e) {
	bool borro = BorrarRec(l->cabeza, e);
	if (borro)l->largo--;
}

int minimo(ListaOrdInt l) {
	AB* aux = l->cabeza;
	while (aux->izq)
		aux = aux->izq;
	return aux->dato;
}

int maximo(ListaOrdInt l) {
	AB* aux = l->cabeza;
	while (aux->der)
		aux = aux->der;
	return aux->dato;
}

bool existe(ListaOrdInt l, int e) {
	return existeEnArbol(l->cabeza, e);
}

bool esVacia(ListaOrdInt l) {
	//return l->largo == 0;
	return !l || l->cabeza == NULL;
}

unsigned int cantidadElementos(ListaOrdInt l) {
	return l->largo;
}

ListaOrdInt clon(ListaOrdInt l) {
	if (!l || !l->cabeza)return NULL;
	ListaOrdInt retornar = new _cabezalListaOrdInt();
	retornar->cabeza = clonArbol(l->cabeza);
	retornar->largo = l->largo;
	return retornar;

}

void destruir(ListaOrdInt& l) {
	if (l && l->cabeza) {
		destruirArbol(l->cabeza);
		l->largo = 0;
	}
}



#endif