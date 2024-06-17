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
y modifica la información a través del mismo.
*/
int main(){
    short a = 5, b = 10;
    short *apEnt;
    apEnt = &a;
    // imprime el valor entero de a
    printf("a = %i\n", a);
    b = *apEnt; // b = 5
    // imprime el valor de lo que apunta apEnt
    printf("b = %i //*apEnt\n", b);
    b = *apEnt + 1; // b = 6
    // imprime el valor de lo que apunta apEnt + 1
    printf("b = %i //*apEnt+1\n", b);
    *apEnt = 0; // a = 0
    // le asigna el valor de 0 a la variable al que apunta apEnt
    printf("a = %i //*apEnt = 0\n", a);

    return 0;
}