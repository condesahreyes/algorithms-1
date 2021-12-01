#include "ColaPrioridadInt.h"

#ifdef COLAPRIORIDAD_INT_IMP
struct DatoPrioridad {
	int dato;
	int prioridad;
};

struct ListaPrioridad {
	DatoPrioridad datos;
	ListaPrioridad* sig;
	ListaPrioridad(int dato, int prioridad, ListaPrioridad* sig) { this->datos.dato = dato; this->datos.prioridad = prioridad; this->sig = sig; }
};

struct _cabezalColaPrioridadInt {
	ListaPrioridad* ppo;
	int largo;
	_cabezalColaPrioridadInt() { this->largo = 0; this->ppo = NULL; }
};

//*******************Funciones auxiliares*******************

void encolarAux(ListaPrioridad*& l, int e, int p) {
	ListaPrioridad* aux = l;
	ListaPrioridad* anterior = NULL;
	while (aux) {
		if (p > aux->datos.prioridad) {
			if (!anterior) {
				ListaPrioridad* nuevo = new ListaPrioridad(e, p, l);
				l = nuevo;
			}
			else {
				ListaPrioridad* nuevo = new ListaPrioridad(e, p, aux);
				anterior->sig = nuevo;
			}
			return;
		}
		anterior = aux;
		aux = aux->sig;
	}
	if (!anterior)
		l = new ListaPrioridad(e, p, nullptr);
	else
		anterior->sig = new ListaPrioridad(e, p, nullptr);
}

//*******************Fin funciones auxiliares*******************

ColaPrioridadInt crearColaPrioridadInt() {
	return new _cabezalColaPrioridadInt();
}

void encolar(ColaPrioridadInt& c, int e, int p) {
	encolarAux(c->ppo, e, p);
	c->largo++;
}

int principio(ColaPrioridadInt c) {
	return c->ppo->datos.dato;
}

int principioPrioridad(ColaPrioridadInt c) {
	return c->ppo->datos.prioridad;
}

void desencolar(ColaPrioridadInt& c) {
	ListaPrioridad* borrar = c->ppo;
	c->ppo = c->ppo->sig;
	c->largo--;
	delete borrar;
	borrar = NULL;
}

bool esVacia(ColaPrioridadInt c) {
	return c->ppo == NULL;
}

unsigned int cantidadElementos(ColaPrioridadInt c) {
	return c->largo;
}

ColaPrioridadInt clon(ColaPrioridadInt c) {
	ColaPrioridadInt retornar = new _cabezalColaPrioridadInt();
	ListaPrioridad* aux = c->ppo;
	ListaPrioridad* ret = NULL;
	while (aux) {
		if (!retornar->ppo) {
			ret = new ListaPrioridad(aux->datos.dato, aux->datos.prioridad, nullptr);
			retornar->ppo = ret;
		}
		else {
			ret->sig = new ListaPrioridad(aux->datos.dato, aux->datos.prioridad, nullptr);
			ret = ret->sig;
		}
		aux = aux->sig;
	}
	retornar->largo = c->largo;

	return retornar;
}

void destruir(ColaPrioridadInt& c) {
	ListaPrioridad* aux = c->ppo;
	while (aux) {
		ListaPrioridad* borrar = aux;
		aux = aux->sig;
		delete borrar;
		borrar = NULL;
	}
	c->largo = 0;
}

#endif