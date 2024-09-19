#include <stdio.h>
#include <pthread.h>

// Función que simula el trabajo de un trabajador en la fábrica
void *trabajador(void *arg) {
    int id = *((int *) arg);  // ID del trabajador

    printf("Trabajador %d está comenzando su tarea.\n", id);
    
    printf("Trabajador %d ha terminado su tarea.\n", id);

    pthread_exit(NULL);  // Termina el hilo
}

int main() {
    pthread_t hilos[4];                      // Array para almacenar los identificadores de los hilos
    int ids[] = {1, 2, 3, 4};                // Array de IDs de los trabajadores

    // Crear hilos para cada trabajador
    for (int i = 0; i < 4; i++) {
        pthread_create(&hilos[i], NULL, trabajador, (void *) &ids[i]);  // Crear un nuevo hilo para cada trabajador
    }

    // Esperar a que los trabajadores terminen
    for (int i = 0; i < 4; i++) {
        pthread_join(hilos[i], NULL);  // Esperar a que el hilo con el ID correspondiente termine
    }

    printf("Todas las tareas han sido completadas.\n");

    return 0;
}
