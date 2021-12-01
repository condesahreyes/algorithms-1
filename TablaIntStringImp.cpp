#include "TablaIntString.h"

#ifdef TABLA_INT_STRING_IMP

struct NLpares {
	int dominio;
	const char* rango;
	NLpares* sig;
	NLpares(int dominio, const char* rango, NLpares* sig) { this->dominio = dominio; this->rango = rango; this->sig = sig; };
};

struct _cabezalTablaIntString {
	NLpares** array;
	int cantElem;
	int tamaño;
	_cabezalTablaIntString(int tamaño) { this->tamaño = tamaño; this->array = new NLpares*[tamaño](); this->cantElem = 0; };
};

//*******************Funciones auxiliares*******************

unsigned int factorCarga(int cantElem, int tamaño) {
	return cantElem / tamaño;
}

unsigned int funHash(int dominio, int largoArrya) {
	return abs(dominio % largoArrya);
}

int numPrimo(int num) {
	for (int i = 2; i < num; i++)
		if ((num % i) == 0) {
			num++;
			i = 2;
		}
	return num;
}

int largoChar(const char* ch) {
	int i;
	for (i = 0; ch[i] != '\0'; i++);
	return i;
}

void agregarAux(TablaIntString& t, int d, const char* r) {
	unsigned int domHash = funHash(d, t->tamaño);
	NLpares* nuevo = new NLpares(d, r, nullptr);
	NLpares* aux = t->array[domHash];
	if (aux == NULL) {
		t->array[domHash] = nuevo;
		t->cantElem++;
	}
	else {
		NLpares* ant = NULL;
		while (aux) {
			if (aux->dominio == d)
				return;
			ant = aux;
			aux = aux->sig;

		}
		ant->sig = nuevo;
		t->cantElem++;
	}
}

void agrandar(TablaIntString& t) {
	int tamAnt = t->tamaño;
	NLpares** ant = t->array;
	int tamaño = numPrimo(tamAnt * 2);
	NLpares** nuevo = new NLpares * [tamaño]();
	t->array = nuevo;
	t->cantElem = 0;
	t->tamaño = tamaño;
	for (int i = 0; i < tamAnt; i++) {
		NLpares* aux = ant[i];
		while (aux) {
			agregarAux(t, aux->dominio, aux->rango);
			aux = aux->sig;
		}
	}


}

char* copiaChar(const char* ant) {
	int largo = largoChar(ant);
	char* nuevo = new char[largo + 1]();
	for (int i = 0; i < largo + 1; i++)
		nuevo[i] = ant[i];
	return nuevo;
}

void destruirNLtab(NLpares* aux) {
	while (aux) {
		NLpares* borrar = aux;
		aux = aux->sig;
		delete borrar;
		borrar = NULL;
	}
}
//agregarNLpares, la uso para clonar (podria usar agregarAux)
void agregarNLpares(int dominio, const char* rango, NLpares*& agregarNL, NLpares*& agregarNLAux) {
	NLpares* nuevo = new NLpares(dominio, rango, nullptr);
	if (!agregarNL) {
		agregarNL = nuevo;
		agregarNLAux = nuevo;
	}
	else {
		agregarNLAux->sig = nuevo;
		agregarNLAux = agregarNLAux->sig;
	}
}
//*******************Fin funciones auxiliares*******************

TablaIntString crearTablaIntString(unsigned int esperados) {
	return new _cabezalTablaIntString(esperados);
}

void agregar(TablaIntString& t, int d, const char* r) {
	if (factorCarga(t->cantElem, t->tamaño) > 1)
		agrandar(t);
	agregarAux(t, d, r);
}

bool estaDefinida(TablaIntString t, int d) {
	int domHash = funHash(d, t->tamaño);
	NLpares* aux = t->array[domHash];
	while (aux) {
		if (aux->dominio == d)
			return true;
		aux = aux->sig;
	}
	return false;
}

char* recuperar(TablaIntString t, int d) {
	int domHash = funHash(d, t->tamaño);
	NLpares* aux = t->array[domHash];
	while (aux){
		if (aux->dominio == d) {
			return copiaChar(aux->rango);
		}
		aux = aux->sig;
	}
}

void borrar(TablaIntString& t, int d) {
	int domHash = funHash(d, t->tamaño);
	NLpares* aux = t->array[domHash];
	if (aux && aux->dominio == d) {
		NLpares* borrar = aux;
		if (aux->sig)
			aux = aux->sig;
		else
			t->array[domHash] = NULL;
		delete borrar;
		borrar = NULL;
		t->cantElem--;
	}
	else if (aux){
		while (aux->sig) {
			if (aux->sig->dominio == d) {
				NLpares* borrar = aux->sig;
				aux->sig = borrar->sig;
				delete borrar;
				borrar = NULL;
				t->cantElem--;
				return;
			}
			aux = aux->sig;
		}
		
	}
		


}

int elemento(TablaIntString t) {
	int domHash = 0;
	for (int i = 0; i < t->tamaño; i++) {
		domHash = funHash(i, t->tamaño);
		if (t->array[domHash])
			return t->array[domHash]->dominio;
	}

}

bool esVacia(TablaIntString t) {
	return t->cantElem == 0;
}

unsigned int cantidadElementos(TablaIntString t) {
	return t->cantElem;
}

void destruir(TablaIntString& t) {
	for (int i = 0; i < t->tamaño; i++) {
		NLpares* aux = t->array[i];
		if (aux)
			destruirNLtab(aux);
	}
	delete[] t->array;
	t->cantElem = 0;
	t->tamaño = 0;
}

TablaIntString clon(TablaIntString t) {
	TablaIntString retornar = new _cabezalTablaIntString(t->tamaño);
	retornar->cantElem = t->cantElem;
	for (int i = 0; i < t->tamaño; i++) {
		NLpares* aux = t->array[i];
		if (aux != NULL) {
			NLpares* nuevo = NULL;
			NLpares* nuevoAux = NULL;
			while (aux) {
				agregarNLpares(aux->dominio, aux->rango, nuevo, nuevoAux);
				aux = aux->sig;
			}
			if (nuevo) {
				retornar->array[i] = nuevo;
			}
		}
	}
	return retornar;
}	

#endif