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
Este programa crea un apuntador de tipo carácter.
*/
int main(){
    char *ap, c;
    c = 'x';
    ap = &c;
    // imprime el carácter de la localidad a la que apunta
    printf("Caracter: %c\n", *ap);
    // imprime el código ASCII de la localidad a la que apunta
    printf("Codigo ASCII: %d\n", *ap);
    // imprime la dirección de memoria de la localidad a la que apunta
    printf("Direccion de memoria: %d\n", ap);

    return 0;
}