#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void signal_handler(int sig) {
  printf("Proceso hijo recibió la señal %d\n", sig);
}

int main() {
  pid_t pid;

  pid = fork();

  if (pid == -1) {
    perror("Error al crear proceso hijo");
    exit(1);
  } else if (pid == 0) {
    // Proceso hijo
    printf("Proceso hijo creado con éxito (PID=%d)\n", getpid());
    signal(SIGUSR1, signal_handler); // Manejador de señal
    pause(); // Esperar señal
  } else {
    // Proceso padre
    printf("Proceso padre creado con éxito (PID=%d)\n", getpid());
    sleep(1); // Esperar un segundo
    printf("Enviando señal SIGUSR1 al proceso hijo\n");
    kill(pid, SIGUSR1); // Enviar señal
    printf("Proceso hijo terminó, proceso padre terminando\n");
  }

  return 0;
}