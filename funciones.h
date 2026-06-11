#ifndef FUNCIONES_H
#define FUNCIONES_H

#define CANT_ARTICULOS 60

#define SUCURSAL_1 0
#define SUCURSAL_2 1
#define SUCURSAL_3 2
#define TOTAL 4

typedef struct {
    char descripcion[90];
    int cantidad_sucursal[3]; // sucursal 1 2 3    
    int total;
}articulos_t;

//Prototipos de Funciones

void cargar_articulo(articulos_t *ficha); //Funcion para cargar fichas de articulos
void print_fichas(articulos_t *articulo); //Funcion para mostrar las fichas en pantalla
void sort_fichas(articulos_t *articulo); //Funcion para Ordenar las Fichas

/*Todas las funciones reciben un puntero a la ficha. Incrementar los punteros prmite desplazarse entre las distintas
fichas del arreglo.*/

#endif