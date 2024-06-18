"""Programa que lee un nombre completo y lo separa en nombre, apellidos e iniciales"""

nombre_completo = input("Ingrese su nombre completo: ")
nombre_secciones = nombre_completo.split(' ')

nombre = ''.join(nombre_secciones[:1])
ap_pa = ''.join(nombre_secciones[1:2])
ap_ma = ''.join(nombre_secciones[2:])

iniciales = nombre[0] + ap_pa[0] + ap_ma[0]

print("Nombre: " + nombre)
print("Apellido paterno: " + ap_pa)
print("Apellido materno: " + ap_ma)
print("Iniciales: " + iniciales)

print("La posicion del nombre es: ")
print(nombre_completo.find(nombre))
print("La posicion del apellido paterno es: ")
print(nombre_completo.find(ap_pa))
print("La posicion del apellido materno es: ")
print(nombre_completo.find(ap_ma))
