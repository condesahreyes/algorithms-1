#include "PilaInt.h"

#ifdef PILA_INT_IMP

struct Lista {
	int dato;
	Lista* sig;
	Lista(int dato, Lista* sig) { this->dato = dato; this->sig = sig; }
};

struct _cabezalPilaInt {
	int largo;
	Lista* ppo;
	_cabezalPilaInt() { this->largo = 0; this->ppo = NULL; }
};


PilaInt crearPilaInt() {
	return new _cabezalPilaInt();
}

void push(PilaInt& p, int e) {
	Lista* nuevo = new Lista(e, p->ppo);
	p->ppo = nuevo;
	p->largo++;
}

int top(PilaInt p) {
	return p->ppo->dato;
}

void pop(PilaInt& p) {
	Lista* borrar = p->ppo;
	p->ppo = p->ppo->sig;
	p->largo--;
	delete borrar;
	borrar = NULL;
}

unsigned int cantidadElementos(PilaInt p) {
	return p->largo;
}

bool esVacia(PilaInt p) {
	return p->largo == 0;
}

PilaInt clon(PilaInt p) {
	PilaInt ret = new _cabezalPilaInt();
	Lista* retAux = NULL;
	Lista* aux = p->ppo;
	while (aux) {
		Lista* nuevo = new Lista(aux->dato, nullptr);
		if (!retAux) {
			retAux = nuevo;
			ret->ppo = nuevo;
			ret->largo = p->largo;
		}
		else {
			retAux->sig = nuevo;
			retAux = retAux->sig;
		}
		aux = aux->sig;
	}
	return ret;
}

void destruir(PilaInt& p) {
	Lista* aux = p->ppo;
	while (aux) {
		Lista* borrar = aux;
		aux = aux->sig;
		delete borrar;
		borrar = NULL;
	}
	p->largo = 0;
}


#endif