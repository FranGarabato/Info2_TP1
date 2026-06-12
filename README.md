# Trabajo Práctico Nº1


## Consigna

Hacer el refactor del código de "Resolucion_Final_Informatica_1" utilizando estructuras, funciones y separacion de archivos. [ver código](https://github.com/DamRCorba/Informatica-2/blob/main/02_Estructuras/ejemplos/Ejemplo3/main.c)

- Crear archivos funciones.c y funciones.h.
  - En funciones.c se deberan desarrollar las funciones.
  - En funciones.h se deberan agregar los prototipos, definiciones y demas constantes.
- Modificar el codigo para el uso de estructuras
- Entregar el codigo y un readme explicativo en un repositorio git nuevo.

La separacion de codigo queda a criterio del alumno, aunque se debe intentar separar en la mayor cantidad de funciones posibles para la legibilidad del codigo.


---

## Estructura del Proyecto

```text
.
├── main.c
├── funciones.c
├── funciones.h
└── README.md
```

### main.c

Contiene la función principal del programa y coordina el flujo general de ejecución:

* Inicialización de las estructuras.
* Carga de artículos.
* Impresión de los datos cargados.
* Ordenamiento de los registros.
* Impresión de los resultados ordenados.

### funciones.h

Contiene:

* Definiciones de constantes.
* Declaración de la estructura `articulos_t`.
* Prototipos de las funciones utilizadas.

### funciones.c

Implementa las funciones principales del sistema:

* `cargar_articulo()`
* `print_fichas()`
* `sort_fichas()`

---

## Estructura Utilizada

```c
typedef struct {
    char descripcion[90];
    int cantidad_sucursal[3];
    int total;
} articulos_t;
```

La estructura permite almacenar toda la información correspondiente a un artículo:

* Descripción.
* Cantidad disponible en cada sucursal.
* Stock total.

---

## Funcionamiento General

1. El usuario ingresa la descripción de un artículo.
2. Selecciona la sucursal correspondiente.
3. Ingresa la cantidad disponible para dicha sucursal.
4. El sistema actualiza automáticamente el stock total.
5. El proceso puede repetirse para múltiples artículos.
6. Se muestran todos los registros cargados.
7. Los artículos son ordenados según su stock total.
8. Se muestran nuevamente los registros ordenados.

---

## Criterio de Ordenamiento

El programa implementa un algoritmo de ordenamiento tipo Bubble Sort para reorganizar los artículos según su cantidad total de stock.

El orden resultante es descendente, mostrando primero los artículos con mayor cantidad total disponible.

---

## Decisiones de Diseño

Durante la refactorización se buscó dividir el programa en funciones que representaran tareas concretas y claramente identificables:

* `cargar_articulo()`: responsable de la carga y actualización de los datos de un artículo.
* `print_fichas()`: encargada de mostrar la información almacenada.
* `sort_fichas()`: responsable del ordenamiento de los registros.

El criterio utilizado fue separar únicamente aquellas partes del código que aportaban una mejora real en la organización y reutilización del programa, evitando crear funciones excesivamente pequeñas o con una única instrucción.

Por este motivo, algunas acciones simples permanecieron dentro de `main()`, como la impresión del mensaje de bienvenida y el ciclo principal de carga de artículos. Estas operaciones forman parte del flujo general del programa y trasladarlas a funciones independientes no aportaba una mejora significativa en la legibilidad.


---

## Compilación

Se compilo utilizando GCC:

```bash
gcc -Wall -Wextra main.c funciones.c -o tp1
```
> No se encontraron Warnings al compilar el programa


Se ejecuta:

```bash
./tp1
```

---

## Nota
Se encontro un error en el codigo en el cual al calcular el total de stock se sumaban valores historicos.
> Se soluciono inicializando previamente el campo de la estructura correspondiente en "0".


## Correcciones Realizadas

Tras la revisión del trabajo práctico se realizaron modificaciones relacionadas con el uso de punteros dentro de las funciones del programa.

Si bien los prototipos de las funciones recibían correctamente punteros a estructuras (`articulos_t *`), la implementación utilizaba principalmente notación de arreglo para acceder a los distintos registros, mediante expresiones del tipo:

```c
articulo[i]
```

A fin de adecuar el código al uso explícito de punteros, se refactorizaron las funciones para recorrer las estructuras mediante aritmética de punteros y acceso utilizando el operador `->`.

Por ejemplo, los recorridos de registros pasaron a realizarse mediante el desplazamiento de punteros:

```c
ptr++;
```

y el acceso a los campos de la estructura mediante:

```c
ptr->campo
```

en lugar de utilizar índices sobre el arreglo.

Además, teniendo en cuenta que es posible igualar estructuras de un mismo tipo, en la función de ordenamiento se implementó el intercambio completo de estructuras utilizando variables auxiliares del mismo tipo, simplificando el código y evitando intercambios individuales de cada uno de los campos.

Estas modificaciones mantienen el comportamiento original del programa, pero permiten utilizar los punteros de forma explícita, cumpliendo con los criterios solicitados en la corrección.



## Autor

Trabajo realizado para la materia Informática 2 por el alumno:

`Feanco Garabato Sinic.`

`Legajo: 120298`

