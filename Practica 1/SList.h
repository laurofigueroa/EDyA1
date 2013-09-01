#ifndef __SLIST_H__
#define __SLIST_H__

typedef void (*VisitorFuncInt) (int data, void *extra_data);
typedef int  (*CompareFunc) (const void *, const void *);
typedef int  (*CompareFuncInt) (int , int); 

/**
 * Los campos son privados, y no deberian ser accedidos
 * desde el código cliente.
 */
typedef struct _SList {
        int    data;
        struct _SList *next;
} SList;

#define slist_data(l)       (l)->data
#define slist_next(l)       (l)->next

/**
 * Agrega un elemento al final de la lista, en complejidad O(n).
 *
 * Nota: una lista vacia se representa con un (SList *) NULL.
 */
SList *slist_append(SList *list, int data);

/**
 * Agrega un elemento al inicio de la lista, en complejidad O(1).
 *
 * Nota: una lista vacia se representa con un (SList *) NULL.
 */
SList *slist_prepend(SList *list, int data);

/**
 * Destruccion de la lista.
 */
void  slist_destroy(SList *list);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void  slist_foreach(SList *list, VisitorFuncInt visit, void *extra_data);

/*
 * Muestra si un nodo tiene siguiente elemento.
 */
int slist_has_next(SList *list);

/*
 * Devuelve la longuitud de una lista.
 */
int slist_length(SList *list);

/*
 * Devuelve la conacatenacion de dos listas.
 */
SList *slist_concat(SList *list1, SList *list2);

/*
 * Inserta un dato  en una lista en una  posición arbiratraria.
 */
void slist_insert(SList *list,int data,int posicion);

/*
 * Remueve de una lista un dato apuntado en una posición arbitraria.
 */
void slist_remove(SList *lista,int posicion);

/*
 * Mustra si un elemento esta en una lista.
 */
int slist_contains(SList *list,int data);

/*
 * Devuelve la posición del elemto data si el mismo esta en la lista list.
 */
int slist_index(SList *list, const int data);

/*
 * Devuelve una lista con los elementos comunes independ. de la posición, de dos listas dadas.
 *
 * NOTA: Las listas originales no se modifican.
 */
SList *slist_intersect(SList *list1, SList *list2);

/*
 * Trabaja como slist_intersect pero recibe un parametro extra que permite definir la nocion de igualdad a se usada.
 */
SList *slist_intersect_custom(SList *list1, SList *list2, CompareFuncInt);

/*
 * Ordena una lista deacuerdo a una funcion de comparacio pasada por agumento.
 */
SList * slist_sort(SList *list, CompareFunc cmp);

// funcion slist_sort version guido :void slist_sort(SList *list, CompareFuncInt cmp)

#endif /* __SLIST_H__ */
