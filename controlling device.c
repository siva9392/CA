#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Define a signal handler function for the interrupt
void handle_interrupt(int signum) {
	printf("PCI Interrupt Received! Signal Number: %d\n", signum);
}

int main() {
	// Install the signal handler for SIGINT (you might need to use a different signal)
	if (signal(SIGINT, handle_interrupt) == SIG_ERR) {
        perror("Error setting up signal handler");
        exit(EXIT_FAILURE);
	}

	// Simulate some work in the main loop
	while (1) {
        printf("Main Loop: Working...\n");
    	sleep(1);
	}

    return 0;
}
