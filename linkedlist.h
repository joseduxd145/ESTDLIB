#ifndef ESTDLIB_LINKEDLIST
#define ESTDLIB_LINKEDLIST

//Estructura que representa una lista enlazada
typedef struct linkedList linkedList;
//Un nodo de la lista
typedef struct node node;

/*
Funcion que devuelve un puntero a una lista
@return El puntero a la lista o NULL en caso de fallo
*/
linkedList *ESTDLIB_newLinkedList(void);
/*
Funcion que libera los nodos y la lista, no elimina los datos que contienen los nodos
@param ll La lista enlazada sobre la que efectuar la accion
*/
void ESTDLIB_dropLinkedList(linkedList *ll);
/*
Funcion que incluye un elemento al final de la lista
@param ll La lista a la que se incluye el nodo
@param data Un puntero a los datos que almacenara el nodo
@return 0 en exito, !0 en caso de que ocurra un error
*/
int ESTDLIB_insertElement(linkedList *ll, void *data);
/*
Funcion que inserta un elemento en la cabeza de la lista
@param ll La lista en la que incluir el elemento
@param data El puntero a los datos
@return 0 en exito, !0 en caso de fallo
*/
int ESTDLIB_insertHead(linkedList *ll, void *data);
/*
Funcion que permite iterar la lista, cada llamada devuelve los datos del nodo siguiente.
El iterador es modificado por el resto de funciones
@param ll La lista que iterar
@return Un puntero al dato contenido en el nodo o NULL si no queda elementos por iterar
*/
void *ESTDLIB_getNext(linkedList *ll);
/*
Funcion que reinicia el iterador a la cabeza del la lista
@param ll La lista a la que reiniciar el iterador
*/
void ESTDLIB_resetIterator(linkedList *ll);
/*
Funcion que busca el la lista por el elemento data y elimina su nodo y modifica el nodo anterior
@param ll La lista en la que buscar
@param data El dato con el que comparar
@return Un puntero a el dato que contenia o null si no se encontro el elemento o hay un error
*/
void *ESTDLIB_removeElement(linkedList *ll, void *data);
/*
Funcion que devuelve el numero de elementos contenidos en la lista
@param ll La lista de la que obtener los datos
@return La cantidad de elementos
*/
unsigned long ESTDLIB_getElements(linkedList *ll);

#endif
