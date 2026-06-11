#include <stdio.h>
#include <string.h>
#include "funciones.h"


void cargar_articulo(articulos_t *articulo){

    int i, articulo_index, sucursal;                              
    char desc[90];                                                //variabe para guardar la descripcion del articulo
    printf("Ingrese la descripcion del articulo: ");
        scanf("%s",desc);

        i=0;
        while (articulo[i].descripcion[0] && strcmp(desc, articulo[i].descripcion)) i++;
        articulo_index = i;
        strcpy(articulo[i].descripcion, desc);

        printf("\n%s, Indice: %d\n", articulo[articulo_index].descripcion, articulo_index);

        printf("Para que sucursal va a realizar la carga? (1,2,3)");
        scanf("%d", &sucursal);                                                                 //Selecciono la sucursal a editar

        printf("Ingrese la cantidad del articulo para la sucursal %d: ", sucursal);
        scanf("%d", &articulo[articulo_index].cantidad_sucursal[sucursal-1]);                   //Guardo el Stock de la sucursal Seleccionada

        articulo[articulo_index].total =0;
        for(i=0;i<3;i++) {                                                                      //Guardo el Total de Stock
            articulo[articulo_index].total += articulo[articulo_index].cantidad_sucursal[i];        
        }


}

void print_fichas(articulos_t *articulo){

    int i=0;
    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while(i< CANT_ARTICULOS && articulo[i].descripcion[0]){
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n", articulo[i].descripcion, articulo[i].cantidad_sucursal[SUCURSAL_1], articulo[i].cantidad_sucursal[SUCURSAL_2], articulo[i].cantidad_sucursal[SUCURSAL_3],articulo[i].total);
        i++;
    }
}



void sort_fichas(articulos_t *articulo){

        int cont, i, articulo_index;
        char desc[90];
    
       for ( cont = 1; cont < CANT_ARTICULOS; cont++)
    {
        for ( i = 0; i < CANT_ARTICULOS-1; i++)
        {
            if(articulo[i].total<articulo[i+1].total){
                strcpy (desc,articulo[i].descripcion);
                strcpy(articulo[i].descripcion,articulo[i+1].descripcion);
                strcpy(articulo[i+1].descripcion, desc);

                articulo_index = articulo[i].cantidad_sucursal[SUCURSAL_1];
                articulo[i].cantidad_sucursal[SUCURSAL_1] = articulo[i+1].cantidad_sucursal[SUCURSAL_1];
                articulo[i+1].cantidad_sucursal[SUCURSAL_1] = articulo_index;

                articulo_index = articulo[i].cantidad_sucursal[SUCURSAL_2];
                articulo[i].cantidad_sucursal[SUCURSAL_2] = articulo[i + 1].cantidad_sucursal[SUCURSAL_2];
                articulo[i + 1].cantidad_sucursal[SUCURSAL_2] = articulo_index;

                articulo_index = articulo[i].cantidad_sucursal[SUCURSAL_3];
                articulo[i].cantidad_sucursal[SUCURSAL_3] = articulo[i + 1].cantidad_sucursal[SUCURSAL_3];
                articulo[i + 1].cantidad_sucursal[SUCURSAL_3] = articulo_index;

                articulo_index = articulo[i].total;
                articulo[i].total = articulo[i + 1].total;
                articulo[i + 1].total = articulo_index;
            }
            
        }
        
    }
}