#include <iostream>
#include <csignal>
#include <cstdlib>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << argv[0] << " <signal_number> <PID>" << endl;
        return 1;
    }
    int signal_number = atoi(argv[1]);
    pid_t pid = atoi(argv[2]);
    if (kill(pid, signal_number) == -1)
    {
        perror("Error");
        return 1;
    }
    cout << "Signal " << signal_number << " sent to PID " << pid << endl;
    return 0;
}
