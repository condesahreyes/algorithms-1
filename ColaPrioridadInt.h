#pragma once

// Elegir la implementacion a usar (solo 1 a la vez):
#define COLAPRIORIDAD_INT_IMP
//#define COLAPRIORIDAD_INT_IMP_2

#if defined(COLAPRIORIDAD_INT_IMP)
#include "ColaPrioridadIntImp.h"
#elif defined(COLAPRIORIDAD_INT_IMP_2)
#include "ColaPrioridadIntImp2.h"
#endif

// PRE: -
// POS: retorna una nueva cola de prioridad vacia
ColaPrioridadInt crearColaPrioridadInt();

// PRE: -
// POS: inserta un elemento e con prioridad p a la cola de prioridad. Los elementos con
//      igual prioridad se agregan en orden FIFO. 
void encolar(ColaPrioridadInt& c, int e, int p);

// PRE: !esVacia()
// POS: retorna el elemento del principio de la cola de prioridad (con mayor prioridad)
int principio(ColaPrioridadInt c);

// PRE: !esVacia()
// POS: retorna la mayor prioridad
int principioPrioridad(ColaPrioridadInt c);

// PRE: !esVacia()
// POS: elimina el elemento del principio de la cola de prioridad
void desencolar(ColaPrioridadInt& c);

// PRE: -
// POS: retorna true si y solo si la cola de prioridad esta vacia
bool esVacia(ColaPrioridadInt c);

// PRE: -
// POS: retorna la cantidad de elementos presentes en la cola de prioridad
unsigned int cantidadElementos(ColaPrioridadInt c);

// PRE: -
// POS: retorna una copia de la cola de prioridad c sin compartir memoria
ColaPrioridadInt clon(ColaPrioridadInt c);

// PRE: -
// POS: libera la memoria de la cola de prioridad
void destruir(ColaPrioridadInt& c);


