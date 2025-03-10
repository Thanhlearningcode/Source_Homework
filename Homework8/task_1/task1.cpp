#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <csignal>

void allocate_on_stack_until_crash() {
    const int KiB = 1024;
    int size = 0;

    while (true) {
        size += 100 * KiB;  //< Tăng mỗi lần 100KiB
        std::cerr << size / KiB << " KiB allocated on stack" << std::endl;

        char arr[size]; //< Cấp phát trên stack, gây tràn stack sau một thời gian

        arr[0] = 'a'; //< Giả lập để compiler không bỏ qua
    }
}

int main() {
    pid_t pid = fork();

    if (pid == 0) { 
        std::cout << "Child process started. PID: " << getpid() << std::endl;
        while (true) {
            sleep(1);
            std::cout << "Child process (" << getpid() << ") is still running..." << std::endl;
        }
    } else if (pid > 0) { 
        std::cout << "Parent process started. PID: " << getpid() << ", Child PID: " << pid << std::endl;
        sleep(2); 
        allocate_on_stack_until_crash(); // Cố tình gây crash

        wait(nullptr); // Đợi con 
    } else {
        std::cerr << "Fork failed!" << std::endl;
    }

    return 0;
}
