#include <iostream>
#include <csignal>
#include <unistd.h>
#include <sys/ucontext.h>

using namespace std;

void sigusr1_handler(int signum, siginfo_t *info, void *context) {
    cout << "Received SIGUSR1 signal" << endl;
    cout << "PID of the sender: " << info->si_pid << endl;

    ucontext_t *ucontext = (ucontext_t *)context;
    cout << "EIP " << ucontext->uc_mcontext.gregs[REG_EIP] << endl;
    cout << "EAX" << ucontext->uc_mcontext.gregs[REG_EAX] << endl;
    cout << "EBX" << ucontext->uc_mcontext.gregs[REG_EBX] << endl;
}

int main() {
    struct sigaction sa;
    sa.sa_sigaction = sigusr1_handler;
    sa.sa_flags = SA_SIGINFO;

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    cout << "My PID: " << getpid() << endl;
    cout << "Waiting for SIGUSR1 signal..." << endl;

    while (true) {
        sleep(10);
    }

    return 0;
}
