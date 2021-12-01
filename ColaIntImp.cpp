#include "ColaInt.h"

#ifdef COLA_INT_IMP
struct Lista {
	int dato;
	Lista* sig;
	Lista(int dato, Lista* sig) { this->dato = dato; this->sig = sig; }
};

struct _cabezalColaInt {
	int largo;
	Lista* ppo;
	Lista* fin;
	_cabezalColaInt(int largo, Lista* ppo, Lista* fin) { this->largo = largo; this->ppo = ppo; this->fin = fin; }
};

ColaInt crearColaInt() {
	return new _cabezalColaInt(0, NULL, NULL);
}

void encolar(ColaInt& c, int e) {
	Lista* nuevo = new Lista(e, NULL);

	if (c->ppo) {
		c->fin->sig = nuevo;
		c->fin = nuevo;
	}
	else {
		c->ppo = nuevo;
		c->fin = nuevo;
	}
	c->largo++;
}

int principio(ColaInt c) {
	return c->ppo->dato;
}

void desencolar(ColaInt& c) {
	Lista* borrar = c->ppo;
	if (!borrar->sig) {
		c->fin = nullptr;
	}
	c->ppo = c->ppo->sig;
	c->largo--;
	delete borrar;
	borrar = NULL;
}

bool esVacia(ColaInt c) {
	return c->largo == 0;;
}

unsigned int cantidadElementos(ColaInt c) {
	return c->largo;
}

ColaInt clon(ColaInt c) {
	ColaInt retornar = NULL;
	Lista* retAux = NULL;
	Lista* aux = c->ppo;
	while (aux) {
		Lista* nuevo = new Lista(aux->dato, NULL);
		if (!retornar) {
			retornar = new _cabezalColaInt(1, nuevo, nuevo);
			retAux = nuevo;
			retornar->ppo = retAux;
		}
		else {
			retAux->sig = nuevo;
			retAux = retAux->sig;
			retornar->fin = nuevo;
		}
		aux = aux->sig;
	}
	retornar->largo = c->largo;
	return retornar;
}

void destruir(ColaInt& c) {
	Lista* aux = c->ppo;
	while (aux) {
		Lista* borrar = aux;
		aux = aux->sig;
		delete borrar;
		borrar = NULL;
	}
	c->largo = 0;
}
#endif