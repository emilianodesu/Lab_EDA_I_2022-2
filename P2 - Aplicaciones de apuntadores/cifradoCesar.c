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

#include<stdio.h> 
/* 
*  Programa que realiza la implementación del cifrado César 
*/ 
#define TAM_PALABRA 20 
#define TAM_ABC 26 

char abecedarioEnClaro[TAM_ABC] = 
{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T' ,'U','V','W','X','Y','Z'}; 
char abecedarioCifrado[TAM_ABC] = 
{'D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W' ,'X','Y','Z','A','B','C'}; 

void cifrar(char *textoEnClaro); 
void descifrar(char *textoCifrado); 

int main(){ 
    short opcion = 0, contador; 
    char palabra[TAM_PALABRA]; 

    while (1){ 
        printf("\n\t*** CIFRADO CESAR ***\n"); 
        for (contador=0 ; contador<26; contador++) 
            printf("%c", *(abecedarioEnClaro+contador)); 
        printf("\n"); 
        for (contador=0 ; contador<26; contador++) 
            printf("%c", *(abecedarioCifrado+contador)); 
        printf("\nElegir una opcion:\n"); 
        printf("1) Cifrar\n"); 
        printf("2) Descifrar.\n"); 
        printf("3) Salir.\n"); 
        scanf("%d", &opcion); 
        
        switch(opcion){ 
            case 1: 
                printf("Ingresar la palabra a cifrar (en mayusculas): ");  
                scanf("%s", palabra); 
                cifrar(palabra); 
                break; 
            case 2: 
                printf("Ingresar la palabra a descifrar (en mayusculas): ");  
                scanf("%s", palabra);
                descifrar(palabra); 
                break; 
            case 3: 
                return 0; 
            default: 
                printf("Opción no valida."); 
        } 
    } 

    return 0; 
} 

void cifrar(char *textoEnClaro){ 
    printf("El texto %s cifrado es: ", textoEnClaro); 
    int contadorAbcedario, contadorPalabra, indice = 0; 
    for (contadorPalabra=0 ; contadorPalabra<textoEnClaro[contadorPalabra] ; contadorPalabra++) 
        for (contadorAbcedario=0 ; contadorAbcedario<TAM_ABC ; contadorAbcedario++) 
            if (abecedarioEnClaro[contadorAbcedario] == textoEnClaro[contadorPalabra]){ 
                printf("%c", abecedarioCifrado[contadorAbcedario]);  
                contadorAbcedario = 26; 
            } 
    printf("\ncP = %d, cA = %d\n",contadorPalabra,contadorAbcedario); 
} 

void descifrar(char *textoCifrado){ 
    printf("El texto %s descifrado es: ", textoCifrado); 
    int contadorAbcedario, contadorPalabra, indice = 0; 
    for (contadorPalabra=0 ; contadorPalabra<textoCifrado[contadorPalabra] ; contadorPalabra++) 
        for (contadorAbcedario=0 ; contadorAbcedario<TAM_ABC ; contadorAbcedario++) 
            if (abecedarioCifrado[contadorAbcedario] == textoCifrado[contadorPalabra]){ 
                printf("%c", abecedarioEnClaro[contadorAbcedario]);  
                contadorAbcedario = 26; 
            } 
    printf("\n"); 
}