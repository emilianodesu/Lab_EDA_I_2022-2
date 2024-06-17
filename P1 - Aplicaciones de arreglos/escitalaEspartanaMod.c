/*
*  Se le deberá agregar la opción 4) Mostrar mensajes cifrados, y si el usuario
*  selecciona esta opción, se deberán mostrar todos los mensajes cifrados que se
*  han hecho durante la ejecución del programa, es decir: Cada de que se crea
*  mensaje cifrado, éste se deberá almacenar en otro arreglo, y cuando se
*  seleccione la opción 4, se deberá mostrar el contenido de dicho arreglo.
*  Al seleccionar la opción 3, la información del arreglo se pierde.
*/

#include<stdio.h>

void crearMensaje();
void descifrarMensaje();
void mostrarMensajes();
char textoCifrado[200];
short flag = 0;
short palabras = 0;
int letras = 0;

int main(){
    short opcion=0;

    while (1){
        printf("\n\t*** ESCÍTALA ESPARTANA ***\n");
        printf("¿Qué desea realizar?\n");
        printf("1) Crear mensaje cifrado.\n");
        printf("2) Descifrar mensaje.\n");
        printf("3) Salir.\n");
        printf("4) Mostrar mensajes cifrados.\n");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                crearMensaje();
                break;
            case 2:
                descifrarMensaje();
                break;
            case 3:
                return 0;
            case 4:
                mostrarMensajes();
                break;
            default:
                printf("Opción no válida.\n");
        }
    }
    
    return 0;
}

void crearMensaje(){
    int ren, col, i, j, k=0;
    printf("Ingresar el tamaño de la escítala:\n");
    printf("\nRenglones:");
    scanf("%i",&ren);
    printf("\nColumnas:");
    scanf("%i",&col);
    char escitala[ren][col];
    char texto[ren*col];
    
    printf("Escriba el texto a cifrar:\n");
    scanf("%s", texto);

    for (i=0 ; i<ren ; i++)
        for (j=0 ; j<col ; j++)
            escitala[i][j] = texto[k++];
    
    printf("El texto en la tira queda de la siguiente manera:\n");
    k=0;
    for (i=0 ; i<col ; i++){
        for (j=0 ; j<ren ; j++){
            printf("%c", escitala[j][i]);
            textoCifrado[k+letras] = escitala[j][i];
            letras++;
        }
    } 
    textoCifrado[k+letras]='.';
    letras++;
    printf("\n");
    flag = 1;
    palabras++;
}

void descifrarMensaje(){
    int ren, col, i, j, k=0;
    printf("Ingresar el tamaño de la escítala:\n");
    printf("\nRenglones:");
    scanf("%i",&ren);
    printf("\nColumnas:");
    scanf("%i",&col);

    char escitala[ren][col];
    char texto[ren*col];
    
    printf("Escriba el texto a descifrar:\n");
    scanf("%s", texto);
    
    for (i=0 ; i<col ; i++)
        for (j=0 ; j<ren ; j++)
            escitala[j][i] = texto[k++];
    
    printf("El texto descifrado es:\n");
    for (i=0 ; i<ren ; i++)
        for (j=0 ; j<col ; j++)
            printf("%c", escitala[i][j]);
}

void mostrarMensajes(){
    int l=0,i,k=0;
    if (flag==1){
        printf("\nLos mensajes cifrados son:\n");
        for ( i = 0; i <palabras; i++){
            printf("%d) ",i+1);
            while (textoCifrado[k+l] != '.'){
                printf("%c", textoCifrado[k+l]);
                l++;
            }
            l++;
            printf("\n");
        }
    }
    else{
        printf("\nNo hay mensajes cifrados guardados.\n");
    }
}

/*
*  Se hicieron 4 modificaciones principales al programa original:
*  Primero: Se incluyeron 3 nuevas variables globales y un arreglo unidimensional
*  de caracteres en las líneas 11 a 14. La cadena textoCifrado, será donde se
*  almacenen los mensajes cifrados que se generen durante la ejecución del
*  programa. La variable flag, sirve como bandera para indicar cuando hay texto
*  almacenado en textoCifrado o no lo hay, por último, las variables palabras y
*  letras, sirven para tener el conteo de palabras y letras que se ha guardado en
*  textoCifrado.
*
*  Segundo: Se modificó la función crearMensaje(). Además de imprimir en pantalla
*  el mensaje cifrado, almacena cada caracter en el arreglo textoCifrado, llevando a
*  la vez el conteo de letras que se ha guardado. Al final de guardar la palabra
*  cifrada, se añade un ‘.’ al final de la palabra para identificar posteriormente
*  donde inician y terminan las palabras. Por último, incrementa en uno el conteo
*  de palabras y establece la bandera en 1.
*
*  Tercero: Se creó otra función con tipo de retorno void y 0 parámetros llamada
*  mostrarMensajes().
*  Si la bandera no cambió a 1: Imprime “No hay mensajes cifrados guardados”.
*  Si la bandera cambió a 1: Dentro del for externo imprime el índice o número de
*  palabra y con el while se imprimen las letras que se guardaron en textoCifrado
*  hasta encontrar un ‘.’, que indica que allí termina la palabra. El ciclo for itera para
*  cada palabra guardada en textoCifrado.
*
*  Cuarto: En el switch de la función main se añadió la opción case 4, que ejecuta
*  la función mostrarMensajes().
*/