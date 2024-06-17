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

struct pelicula{
    char *nombre;
    char *genero;
    short anio;
    short numDirectores;
    char *directores[10];
};

void imprimirDatosPelicula(struct pelicula);
struct pelicula llenarDatosPelicula(char *, char *, short, short, char *[10]);

int main(){
    char *directores[10];
    directores[0] = "Lana Wachowski";
    directores[1] = "Andy Wachowski";
    struct pelicula matrix = llenarDatosPelicula("The matrix", "Ciencia ficcion", 1999, 2, directores);
    imprimirDatosPelicula(matrix);

    return 0;
}

struct pelicula llenarDatosPelicula(char *nombre, char *genero, short anio, short numDirectores, char *directores[10]){
    struct pelicula *ap_movie, movie;
    ap_movie = &movie;
    ap_movie->nombre = nombre;
    ap_movie->genero = genero;
    ap_movie->anio = anio;
    ap_movie->numDirectores = numDirectores;
    int cont = 0;
    for (; cont < ap_movie->numDirectores; cont++){
        ap_movie->directores[cont] = directores[cont];
    }

    return movie;
}

void imprimirDatosPelicula(struct pelicula movie){
    struct pelicula *ap_movie = &movie;
    printf("PELICULA: %s\n", ap_movie->nombre);
    printf("GENERO: %s\n", ap_movie->genero);
    printf("ANIO: %d\n", ap_movie->anio);
    printf("DIRECTOR(ES):\n");
    int cont = 0;
    for (; cont < ap_movie->numDirectores; cont++){
        printf("%s\n", ap_movie->directores[cont]);
    }
}