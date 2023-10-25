#ifndef ESTDLIB_DICTIONARY
#define ESTDLIB_DICTIONARY

#include <stdbool.h>

typedef struct dictionary dictionary;

/*
Funcion que aloca y genera un dictionario
@param freeOnDrop True para liberar la memoria de las claves y data al eliminar esta estructura, false para una eliminacion manual
@return Un puntero al diccionario o NULL en caso de fallo
*/
dictionary *newDictionary(bool freeOnDrop);
/*
Funcion que elimina un diccionario
@param dd El dicionario a eliminar
*/
void dropDictionary(dictionary *dd);
/*
Funcion que inserta un par clave valor
@param dd El dicionario al que insertar los datos
@param key La clave string de los datos
@param data Un puntero al dato que asignar a la clave
@return 0 en exito, !0 En caso de fallo
*/
int insertKeyPair(dictionary *dd, char *key, void *data);
/*
Funcion que obtiene los datos asignados a una clave
@param dd El diccionario en el que buscar
@param key La clave con la que buscar
@return Un puntero a los datos, NULL en caso de fallo o no exista
*/
void *getData(dictionary *dd, char *key);

#endif
