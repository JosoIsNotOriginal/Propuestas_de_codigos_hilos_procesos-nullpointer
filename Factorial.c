#include <stdio.h>
#include <pthread.h>

void* calcularFactorial(void* arg) {
    int n = *(int*)arg;
    long long factorial = 1;
    
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    
    printf("Factorial de %d es %lld\n", n, factorial);
    return NULL;
}

int main() {
    pthread_t hilo1, hilo2;
    int num1 = 5, num2 = 7;
    
    // Crear hilos para calcular factoriales
    pthread_create(&hilo1, NULL, calcularFactorial, &num1);
    pthread_create(&hilo2, NULL, calcularFactorial, &num2);
    
    // Esperar a que ambos hilos terminen
    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);
    
    printf("Programa principal: Cálculos de factorial finalizados\n");
    return 0;
}

