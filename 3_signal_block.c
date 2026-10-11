#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t got_sigint = 0;

void handler(int sig) {
    (void)sig;
    got_sigint = 1;
}

int main(void) {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    sigset_t set, old;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);

    printf("SIGINT 를 5초간 막습니다. Ctrl+C 를 여러 번 눌러 보세요.\n");

    sigprocmask(SIG_BLOCK, &set, &old);

    for (int i = 5; i > 0; i--) {
        printf("작업 중... (%d초 남음)\n", i);
        sleep(1);
    }

    printf("블록 해제!\n");
    sigprocmask(SIG_SETMASK, &old, NULL);

    if (got_sigint) {
        printf("시그널 2(SIGINT)를 받았습니다. (블록된 동안 대기하던 시그널이 한 번 전달됨)\n");
    }

    return 0;
}