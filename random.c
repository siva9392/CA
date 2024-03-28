#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Interrupt handler function for Device 1
void device1_interrupt_handler(int signal) {
    printf("Device 1 Interrupt Handler\n");
	// Handle Device 1 interrupt
}

// Interrupt handler function for Device 2
void device2_interrupt_handler(int signal) {
    printf("Device 2 Interrupt Handler\n");
	// Handle Device 2 interrupt
}

// Enable interrupt for a device
void enable_interrupt(int device) {
	switch(device) {
    	case 1:
            signal(SIGINT, device1_interrupt_handler);
        	break;
    	case 2:
            signal(SIGINT, device2_interrupt_handler);
        	break;
    	default:
            printf("Invalid device\n");
        	break;
	}
}

// Disable interrupt for a device
void disable_interrupt(int device) {
	signal(SIGINT, SIG_DFL);
}

int main() {
	// Enable interrupts for both devices
    enable_interrupt(1);
    enable_interrupt(2);

    printf("Interrupts enabled for both devices. Press Ctrl+C to trigger interrupts.\n");

	// Loop indefinitely to simulate device operations
	while (1) {
    	// Perform other tasks or wait for interrupts
	}

	// Disable interrupts before exiting
    disable_interrupt(1);
    disable_interrupt(2);

	return 0;
}
