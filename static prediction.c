#include <stdio.h>
#define TAKEN 1
#define NOT_TAKEN 0

// Function to simulate static prediction
int static_prediction(int instruction_address) {
    // Implement a simple strategy based on the instruction address
    if (instruction_address % 2 == 0) {
        // Predict taken for even instruction addresses
        return TAKEN;
    } else {
        // Predict not taken for odd instruction addresses
        return NOT_TAKEN;
    }
}

int main() {
    // Example instruction addresses
    int instruction_addresses[] = {100, 101, 102, 103, 104};
    int num_instructions = sizeof(instruction_addresses) / sizeof(instruction_addresses[0]);

    printf("Static prediction results:\n");
    for (int i = 0; i < num_instructions; i++) {
        int prediction = static_prediction(instruction_addresses[i]);
        printf("Instruction at address %d: Prediction = %s\n", instruction_addresses[i],
               prediction == TAKEN ? "Taken" : "Not Taken");
    }

    return 0;
}
