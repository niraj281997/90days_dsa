#include <iostream>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

sem_t semodd, semeven; // Declare semaphores

void* f_odd_function(void* arg) {
    int max = *(int*)arg;
    for (int i = 1; i <= max; i += 2) { // Process odd numbers only
        sem_wait(&semodd); // Wait for odd semaphore
        cout << "Odd number: " << i << endl;
        sem_post(&semeven); // Signal even semaphore
    }
    return NULL;
}

void* f_even_function(void* arg) {
    int max = *(int*)arg;
    for (int i = 2; i <= max; i += 2) { // Process even numbers only
        sem_wait(&semeven); // Wait for even semaphore
        cout << "Even number: " << i << endl;
        sem_post(&semodd); // Signal odd semaphore
    }
    return NULL;
}

int main() {
    pthread_t p1, p2;
    int max = 10;

    // Initialize semaphores
    sem_init(&semodd, 0, 1); // Allow odd thread to start first
    sem_init(&semeven, 0, 0); // Block even thread initially

    // Create threads
    pthread_create(&p1, NULL, f_odd_function, &max);
    pthread_create(&p2, NULL, f_even_function, &max);

    // Wait for threads to finish
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    // Destroy semaphores
    sem_destroy(&semodd);
    sem_destroy(&semeven);

    return 0;
}
