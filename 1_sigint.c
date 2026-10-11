#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t sigint_count = 0;

void handler(int sig) {
    (void)sig;
    sigint_count++;
}

int main(void) {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    printf("대기 중... (Ctrl+C를 3번 누르면 종료됩니다.)\n");

    while (sigint_count < 3) {
        pause();
    }

    printf("\nCtrl+C(SIGINT)를 3번 받았습니다. 정리하고 종료합니다.\n");
    return 0;
}