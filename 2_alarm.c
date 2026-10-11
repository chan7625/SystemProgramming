#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t current_count = 0;
volatile sig_atomic_t target_count = 0;
volatile sig_atomic_t interval_sec = 0;

void handler(int sig) {
    (void)sig;
    current_count++;

    if (current_count < target_count) {
        alarm(interval_sec);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "사용법: %s <간격초> <반복횟수>\n", argv[0]);
        fprintf(stderr, "예시: %s 2 3\n", argv[0]);
        return 1;
    }

    interval_sec = atoi(argv[1]);
    target_count = atoi(argv[2]);

    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    printf("타이머 시작 (간격: %d초, 반복: %d회)\n", interval_sec, target_count);
    alarm(interval_sec);

    while (current_count < target_count) {
        pause();
        printf("[%d/%d] %d초 경과\n", current_count, target_count, current_count * interval_sec);
    }

    printf("타이머 종료\n");
    return 0;
}