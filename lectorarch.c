#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Función que leerá un archivo
void *leerArchivo(void *arg) {
    char *nombreArchivo = (char *) arg;  // El nombre del archivo pasado como argumento
    FILE *archivo = fopen(nombreArchivo, "r");  // Abrir el archivo en modo lectura

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombreArchivo);
        pthread_exit(NULL);
    }

    printf("Leyendo archivo: %s\n", nombreArchivo);

    // Buffer para leer líneas del archivo
    char linea[256];
    while (fgets(linea, sizeof(linea), archivo)) {
        printf("%s", linea);  // Imprimir cada línea leída
    }

    printf("Lectura del archivo %s finalizada.\n", nombreArchivo);
    fclose(archivo);  // Cerrar el archivo
    pthread_exit(NULL);
}

int main() {
    pthread_t hilos[2];  // Array para almacenar los identificadores de los hilos ligeros
    char *archivos[] = {"prueba1.txt", "prueba2.txt"};  // Nombres de los archivos a leer

    // Crear hilos ligeros para leer los archivos en paralelo
    for (int i = 0; i < 2; i++) {
        if (pthread_create(&hilos[i], NULL, leerArchivo, (void *) archivos[i])) {
            printf("Error creando el hilo %d\n", i + 1);
            exit(1);
        }
    }

    // Esperar a que los hilos terminen
    for (int i = 0; i < 2; i++) {
        pthread_join(hilos[i], NULL);
    }

    printf("Todos los archivos han sido leídos.\n");

    return 0;
}
