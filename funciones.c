#include <stdio.h>
#include <string.h>
#include "funciones.h"


void cargar_articulo(articulos_t *articulo){

    int i, articulo_index, sucursal;                              
    char desc[90];                                                //variabe para guardar la descripcion del articulo
    articulos_t *ptr = articulo;                                  //Creo un puntero auxiliar que apunta a las fichas

    printf("Ingrese la descripcion del articulo: ");
        scanf("%s",desc);

        i=0;
        while (ptr->descripcion[0] && strcmp(desc, ptr->descripcion)) {         //Recorro las fichas con el puntero hasta encontrar la que corresponde a la descripcion, o una vacia.
            
            ptr++;
            i++;
        }

        articulo_index = i;

        strcpy(ptr->descripcion, desc);                                         //guardo la descripcion en la ficha

        printf("\n%s, Indice: %d\n", ptr->descripcion, articulo_index);

        printf("Para que sucursal va a realizar la carga? (1,2,3)");
        scanf("%d", &sucursal);                                                                 //Selecciono la sucursal a editar

        printf("Ingrese la cantidad del articulo para la sucursal %d: ", sucursal);
        scanf("%d", &ptr->cantidad_sucursal[sucursal-1]);                                       //Guardo el Stock de la sucursal Seleccionada

        ptr->total =0;
        for(i=0;i<3;i++) {                                                                      //Guardo el Total de Stock
            ptr->total += ptr->cantidad_sucursal[i];        
        }


}

void print_fichas(articulos_t *articulo){

    int i=0;
    articulos_t *ptr = articulo;                                  //Creo un puntero auxiliar que apunta a las fichas
    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while(i< CANT_ARTICULOS && ptr->descripcion[0]){                //Recorro todas las fichas hasta encontrar una vacia, o si alcanzo el limite de articulos
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n", ptr->descripcion, ptr->cantidad_sucursal[SUCURSAL_1], ptr->cantidad_sucursal[SUCURSAL_2], ptr->cantidad_sucursal[SUCURSAL_3],ptr->total);
        i++;
        ptr++;
    }
}



void sort_fichas(articulos_t *articulo){

        int cont, i;
        articulos_t aux;
        articulos_t *ptr;

        for(cont = 1 ; cont < CANT_ARTICULOS ; cont++){

            ptr = articulo;

            for(i=0 ; i < CANT_ARTICULOS - 1 ; i++){

                if(ptr->total < (ptr + 1)->total){

                    aux = *ptr;
                    *ptr = *(ptr + 1);
                    *(ptr + 1) = aux;
                }

                ptr++;
                
            }
        }
}