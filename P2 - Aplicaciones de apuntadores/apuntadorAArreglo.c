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

#include <stdio.h>
/*
Este programa crea un apuntador de tipo entero
que apunta al inicio de un arreglo.
*/
int main(){
    short arr[5], *apArr;
    apArr = &arr[0];
    // imprime la dirección de memoria del arreglo en la posición [0]
    printf("Direccion del arreglo en la primera posición: %x\n", &arr[0]);
    // imprime la dirección de memoria del arreglo
    // (el nombre del arreglo es un apuntador)
    printf("Direccion del arreglo: %x\n", &arr);
    // imprime la dirección de memoria del apuntador apArr
    printf("Direccion del apuntador: %x\n", apArr);

    return 0;
}