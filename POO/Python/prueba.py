import socket

try:

    nombre_host = socket.gethostname()
    print("Nombre del host:", nombre_host)
    ip_host = socket.gethostbyname(nombre_host)
    print("Dirección IP del host:", ip_host)

except socket.gaierror as e:
    print("Error al obtener la dirección IP del host:", e)

except socket.error as e:
    print("Error al obtener información del host:", e)
