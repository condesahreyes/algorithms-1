#include "ListaPosInt.h"

#ifdef LISTA_POS_INT_IMP


struct _cabezalListaPosInt {
	int* arreglo;
	int tamaño;
	int cantidadEnArreglo;
	_cabezalListaPosInt(int tamaño) { this->tamaño = tamaño; this->arreglo = new int[tamaño]; this->cantidadEnArreglo = 0; }
};

ListaPosInt crearListaPosInt()
{
	return new _cabezalListaPosInt(10);
}

void agregar(ListaPosInt& l, int e, unsigned int pos)
{
	if (l->cantidadEnArreglo == l->tamaño) {
		int tamañoViejo = l->tamaño;
		int* nuevo = new int[tamañoViejo * 2];
		for (int i = 0; i < tamañoViejo; i++)
			nuevo[i] = l->arreglo[i];
		l->arreglo = nuevo;
		l->tamaño = tamañoViejo * 2;
	}
	if (l->cantidadEnArreglo<=pos) {
		l->arreglo[l->cantidadEnArreglo] = e;
		l->cantidadEnArreglo++;
	}
	else {
		int anterior = l->arreglo[pos];
		l->arreglo[pos] = e;
		for (int i = pos + 1; i < l->cantidadEnArreglo; i++) {
			int actual = l->arreglo[i];
			l->arreglo[i] = anterior;
			anterior = actual;
		}
		l->arreglo[pos + 1] = anterior;
		l->cantidadEnArreglo++;
	}
}

void borrar(ListaPosInt& l, unsigned int pos)
{
	if (l->cantidadEnArreglo > pos) {
		for (int i = pos; i < l->cantidadEnArreglo-1; i++) {
			l->arreglo[i] = l->arreglo[i + 1];
		}
		l->arreglo[l->cantidadEnArreglo] = NULL;
		l->cantidadEnArreglo--;
	}
}

int elemento(ListaPosInt l, unsigned int pos)
{

	return l->arreglo[pos];

}

bool esVacia(ListaPosInt l)
{

	return l->cantidadEnArreglo == 0;

}

unsigned int cantidadElementos(ListaPosInt l)
{
	return l->cantidadEnArreglo;

}

ListaPosInt clon(ListaPosInt l)
{

	int tamaño = l->tamaño;
	ListaPosInt ret = new _cabezalListaPosInt(tamaño);
	int* nuevo = ret->arreglo;
	for (int i = 0; i < l->cantidadEnArreglo; i++){
		nuevo[i] = l->arreglo[i];
	}
	ret->arreglo = nuevo;
	ret->cantidadEnArreglo = l->cantidadEnArreglo;
	return ret;

}

void destruir(ListaPosInt& l)
{
	delete[] l->arreglo;
	l->arreglo = NULL;
	l->tamaño = 0;
}


#endif