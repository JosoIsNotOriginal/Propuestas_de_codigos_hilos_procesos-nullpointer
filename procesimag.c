#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>  // Para usar la función sleep()

// Función simulada para procesar una imagen grande
void *procesarImagen(void *arg) {
    int id = *((int *) arg);  // Obtener el ID del hilo
    printf("Hilo %d procesando imagen...\n", id);
    sleep(3);  // Simulación de procesamiento intensivo (3 segundos)
    printf("Hilo %d ha terminado de procesar la imagen.\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t hilos[3];  // Array para almacenar los identificadores de los hilos
    int ids[] = {1, 2, 3};  // Array de IDs para las imágenes

    // Crear hilos para procesar imágenes
    for (int i = 0; i < 3; i++) {
        if (pthread_create(&hilos[i], NULL, procesarImagen, (void *) &ids[i])) {
            printf("Error creando el hilo %d\n", i + 1);
            exit(1);
        }
    }

    // Esperar a que todos los hilos terminen
    for (int i = 0; i < 3; i++) {
        pthread_join(hilos[i], NULL);
    }

    printf("Todos los hilos han terminado de procesar las imágenes.\n");

    return 0;
}
