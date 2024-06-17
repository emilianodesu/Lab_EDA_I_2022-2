/*
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Jorge A. Solano
 *
 */
// Hacer las modificaciones necesarias para que el programa funcione con el
// operador flecha

#include <stdio.h>
#define TAM 2
#define NUM_DIR 2

struct pelicula{
    char nombre[20];
    char genero[20];
    short anio;
    short numDirectores;
    char directores[NUM_DIR][20];
};

void llenarArreglo(struct pelicula *);
void imprimirArreglo(struct pelicula *);

int main(){
    struct pelicula arreglo[TAM];
    llenarArreglo(arreglo);
    imprimirArreglo(arreglo);

    return 0;
}

void llenarArreglo(struct pelicula arreglo[TAM]){
    int iesimo, enesimo;
    for (iesimo = 0; iesimo < TAM; iesimo++){
        struct pelicula movie, *ap_movie;
        ap_movie = &movie;
        printf("####### Pelicula %d #######\n", iesimo + 1);
        printf("Ingrese nombre pelicula:");
        setbuf(stdin, NULL);
        scanf("%s", ap_movie->nombre);
        getchar();
        printf("Ingrese genero pelicula:");
        setbuf(stdin, NULL);
        scanf("%s", ap_movie->genero);
        getchar();
        printf("Ingrese anio pelicula:");
        setbuf(stdin, NULL);
        scanf("%d", &ap_movie->anio);
        movie.numDirectores = NUM_DIR;
        for (enesimo = 0; enesimo < NUM_DIR; enesimo++){
            printf("Ingrese director %d:", enesimo + 1);
            setbuf(stdin, NULL);
            scanf("%s", ap_movie->directores[enesimo]);
            getchar();
        }
        arreglo[iesimo] = movie;
    }
}

void imprimirArreglo(struct pelicula arreglo[TAM]){
    int iesimo, enesimo;
    struct pelicula *ap_arreglo;
    printf("####### Contenido del arreglo #######\n");
    for (iesimo = TAM - 1; iesimo >= 0; iesimo--){
        ap_arreglo = &arreglo[iesimo];
        printf("####### Pelicula %d #######\n", iesimo + 1);
        printf("PELICULA: %s\n", ap_arreglo->nombre);
        printf("GINERO: %s\n", ap_arreglo->genero);
        printf("ANIO: %d\n", ap_arreglo->anio);
        printf("DIRECTOR(ES):\n");
        for (enesimo = 0; enesimo < ap_arreglo->numDirectores; enesimo++){
            printf("%s\n", ap_arreglo->directores[enesimo]);
        }
    }
}