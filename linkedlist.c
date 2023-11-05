#include "linkedlist.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct node
{
    void *data;     //Puntero a los datos
    node *next;     //Puntero al siguiente nodo
}node;

linkedList *ESTDLIB_newLinkedList(void)
{
    //Alocar una estructura de lista enlazada
    linkedList *ll = malloc(sizeof(linkedList));
    //Comprobar que su creacion fue exitosa
    if(!ll)
    {
        return NULL;
    }

    //Inicializar los campos
    ll->head = NULL;
    ll ->iterator = NULL;

    return ll;
}

void ESTDLIB_dropLinkedList(linkedList *ll)
{
    //Comprobar que la lista es un puntero valido
    if(!ll)
    {
        return;
    }

    //Colocar el iterador en la cabeza de la lista
    ll->iterator = ll->head;

    //Elemento que almacena un nodo temporalmente
    node *tmp = NULL;

    //Bucle que se ejecuta mientras el iterador no se nulo
    while(ll->iterator)
    {
        //Asignar al nodo temporal la direccion del siguiente elemento de la lista
        tmp = ll->iterator->next;
        //Asignar la memoria del nodo a 0
        memset(ll->iterator, 0, sizeof(node));
        //Liberar el nodo
        free(ll->iterator);
        //Avanzar el iterador al siguiente nodo
        ll->iterator = tmp;
    }

    //Asignar 0 a la estructura de la linkedlist
    memset(ll, 0, sizeof(linkedList));
    //Liberar la memoria de la lista
    free(ll);
}

int ESTDLIB_insertElement(linkedList *ll, void *data)
{
    //Comprobar si la lista y data son punteros validos
    if(!ll || !data)
    {
        return 1;
    }

    //Alocar un nodo
    node *element = malloc(sizeof(node));
    //Comprobar que se pudo crear
    if(!element)
    {
        return 2;
    }

    //Asignar los datos y el siguiente nodo
    //El siguiente nodo es null porque este metodo crea elementos al final de la lista
    element->data = data;
    element->next = NULL;

    //Asignar el iterador a la cabeza
    ll->iterator = ll->head;

    //Comprobar si el iterador es un puntero valido
    if(ll->iterator)
    {
        //Avanzar en los iteradores hasta encontrar la cola de la lista
        while(ll->iterator->next != NULL)
        {
            ll->iterator = ll->iterator->next;
        }

        //Asignar el siguiente elemento
        ll->iterator->next = element;
        //Se asigna el iterador a la cabeza
        ll->iterator = ll->head;
    }
    else
    {
        //En caso de que no ubiese ningun elemento se asigna a la cabeza
        ll->head = element;
    }

    return 0;
}

int ESTDLIB_insertHead(linkedList *ll, void *data)
{
    //Comprobar si ll y data son punteros validos
    if(!ll || !data)
    {
        return 1;
    }

    //Alocar un nodo
    node *element = malloc(sizeof(node));
    //Comprobar su correcta alocacion
    if(!element)
    {
        return 2;
    }

    //Asignar los datos
    element->data = data;
    //Establecer el siguiente elemento como la cabeza actual
    element->next = ll->head;

    //Asignar la cabeza al nuevo elemento
    ll->head = element;
    //Reiniciar el iterador a la cabeza
    ll->iterator = ll->head;

    return 0;
}

void *ESTDLIB_getNext(linkedList *ll)
{
    //Comprobar que ll es valido
    if(!ll)
    {
        return NULL;
    }

    //Comprobar si iterador es valido, si iterador no es valido, o se alcanzo el final de la lista o no hay elementos en la lista
    if(!ll->iterator)
    {
        return NULL;
    }

    //Crear un puntero a los datos del nodo
    void *data = ll->iterator->data;
    //Avanzar el iterador
    ll->iterator = ll->iterator->next;

    return data;
}

void ESTDLIB_resetIterator(linkedList *ll)
{
    //Comprobar que la ll es un puntero valido
    if(!ll)
    {
        return;
    }

    //Asignar el iterador a la cabeza
    ll->iterator = ll->head;
}

void *ESTDLIB_removeElement(linkedList *ll, void *data)
{
    //Comprobar si ll y data son punteros validos
    if(!ll || !data)
    {
        return NULL;
    }

    //Asignar el iterador a la cabeza
    ll->iterator = ll->head;
    //Crear un nodo temporal para almacenar el nodo anterior
    node *tmp = ll->iterator;
    //Crear un puntero para la salida
    void *salida = NULL;

    //Avanzar por la lista mientras data no coincida y no se llegue al final de la lista
    while(ll->iterator->data != data && ll->iterator->next != NULL)
    {
        tmp = ll->iterator;
        ll->iterator = ll->iterator->next;
    }

    //Si el iterador llego al puntero a data
    if(ll->iterator->data == data)
    {
        //Asignar la salida a los datos
        salida = ll->iterator->data;
        //Enlazar los nodos
        tmp->next = ll->iterator->next;
        //Liberar el nodo
        free(ll->iterator);
    }

    //Devolver el iterador a la cabeza
    ll->iterator = ll->head;

    return salida;
}
