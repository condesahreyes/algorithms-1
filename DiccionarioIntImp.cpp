#include "DiccionarioInt.h"

#ifdef DICCIONARIO_INT_IMP

struct NLdic {
	int dato;
	NLdic* sig;
	NLdic(int dato, NLdic* sig) { this->dato = dato; this->sig = sig; };
};

struct _cabezalDiccionarioInt {
	NLdic** array;
	int tamaño;
	int cantElem;
	_cabezalDiccionarioInt(int tamaño) { this->array = new NLdic * [tamaño](); this->tamaño = tamaño; this->cantElem = 0; };
};
//*******************Funciones auxiliares*******************
unsigned int factorCargaDic(int cantElem, int tamaño) {
	return cantElem / tamaño;
}

unsigned int funHashDic(int dominio, int largoArrya) {
	return abs(dominio % largoArrya);
}

int numPrimoDic(int num) {
	for (int i = 2; i < num; i++)
		if ((num % i) == 0) {
			num++;
			i = 2;
		}
	return num;
}

void agregarAux(DiccionarioInt& d, int e) {
	unsigned int domHash = funHashDic(e, d->tamaño);
	NLdic* nuevo = new NLdic(e, nullptr);
	NLdic* aux = d->array[domHash];
	if (aux == NULL) {
		d->array[domHash] = nuevo;
		d->cantElem++;
	}
	else {
		NLdic* ant = NULL;
		while (aux) {
			if (aux->dato == e)
				return;
			ant = aux;
			aux = aux->sig;

		}
		ant->sig = nuevo;
		d->cantElem++;
	}
}

void agrandarDic(DiccionarioInt& d) {
	int tamAnt = d->tamaño;
	NLdic** ant = d->array;
	int tamaño = numPrimoDic(tamAnt * 2);
	NLdic** nuevo = new NLdic* [tamaño]();
	d->array = nuevo;
	d->cantElem = 0;
	d->tamaño = tamaño;
	for (int i = 0; i < tamAnt; i++) {
		NLdic* aux = ant[i];
		while (aux) {
			agregarAux(d, aux->dato);
			aux = aux->sig;
		}
	}

}

void agregarNLdic(int dato, NLdic*& agregarNL, NLdic*& agregarNLAux) {
	NLdic* nuevo = new NLdic(dato, nullptr);
	if (!agregarNL) {
		agregarNL = nuevo;
		agregarNLAux = nuevo;
	}
	else {
		agregarNLAux->sig = nuevo;
		agregarNLAux = agregarNLAux->sig;
	}
}

void destruirNLdic(NLdic* aux) {
	while (aux) {
		NLdic* borrar = aux;
		aux = aux->sig;
		delete borrar;
		borrar = NULL;
	}
}

//*******************Fin funciones auxiliares*******************

DiccionarioInt crearDiccionarioInt(unsigned int esperados) {
	return new _cabezalDiccionarioInt(esperados);

}

void agregar(DiccionarioInt& d, int e) {
	if (factorCargaDic(d->cantElem, d->tamaño) >= 1)
		agrandarDic(d);
	agregarAux(d, e);
}

void borrar(DiccionarioInt& d, int e) {
	int domHash = funHashDic(e, d->tamaño);
	NLdic* aux = d->array[domHash];
	if (aux && aux->dato == e) {
		NLdic* borrar = aux;
		if (aux->sig)
			d->array[domHash] = aux->sig;
		else
			d->array[domHash] = NULL;
		delete borrar;
		borrar = NULL;
		d->cantElem--;
	}
	else if (aux) {
		while (aux->sig) {
			if (aux->sig->dato == e) {
				NLdic* borrar = aux->sig;
				if (borrar->sig)
					aux->sig = borrar->sig;
				else
					aux->sig = NULL;
				delete borrar;
				borrar = NULL;
				d->cantElem--;
				return;
			}
			aux = aux->sig;
		}

	}
}

bool pertenece(DiccionarioInt d, int e) {
	int domHash = funHashDic(e, d->tamaño);
	NLdic* aux = d->array[domHash];
	while (aux) {
		if (aux->dato == e)
			return true;
		aux = aux->sig;
	}

}

int elemento(DiccionarioInt d) {
	int domHash = 0;
	for (int i = 0; i < d->tamaño; i++) {
		domHash = funHashDic(i, d->tamaño);
		if (d->array[domHash])
			return d->array[domHash]->dato;
	}

}

bool esVacio(DiccionarioInt d) {

	return d->cantElem==0;
}

unsigned int cantidadElementos(DiccionarioInt d) {

	return d->cantElem;
}

DiccionarioInt clon(DiccionarioInt d) {
	DiccionarioInt retornar = new _cabezalDiccionarioInt(d->tamaño);
	retornar->cantElem = d->cantElem;
	for (int i = 0; i < d->tamaño; i++) {
		NLdic* aux = d->array[i];
		if (aux != NULL) {
			NLdic* nuevo = NULL;
			NLdic* nuevoAux = NULL;
			while (aux) {
				agregarNLdic(aux->dato, nuevo, nuevoAux);
				aux = aux->sig;
			}
			if (nuevo) {
				retornar->array[i] = nuevo;
			}
		}
	}

	return retornar;

}

void destruir(DiccionarioInt& d) {
	for (int i = 0; i < d->tamaño; i++){
		NLdic* aux = d->array[i];
		if (aux)
			destruirNLdic(aux);
	}
	delete[] d->array;
	d->cantElem = 0;
	d->tamaño = 0;
}


#endif