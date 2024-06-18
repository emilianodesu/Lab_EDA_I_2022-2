"""Escribir funciones que dada una cadena de caracteres:
- Imprima los dos primeros caracteres.
- Imprima los tres últimos caracteres."""

def primeros_dos(cadena):
    """Imprime los dos primeros caracteres"""
    print(f"Los primeros dos caracteres son {cadena[:2]}")


def ultimos_tres(cadena):
    """Imprime los ultimos tres caracteres"""
    print(f"Los últimos tres caracteres son {cadena[len(cadena)-3:]}")

texto = input("Escribe algo: ")
primeros_dos(texto)
ultimos_tres(texto)
