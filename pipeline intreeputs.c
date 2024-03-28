#include <stdio.h>
// Structure representing a single bus
typedef struct {
    int data;
    int address;
} Bus;
// Structure representing a CPU
typedef struct {
     Bus *bus;
} CPU;

// Structure representing a Memory
typedef struct {
    Bus *bus;
    int data[100]; // For simplicity, assuming memory size of 100 locations
} Memory;

// Function to read data from memory
int memory_read(Memory *mem, int address) {
    return mem->data[address];
}

// Function to write data to memory
void memory_write(Memory *mem, int address, int data) {
    mem->data[address] = data;
}

// Function to perform CPU operation (read from memory)
int cpu_operation(CPU *cpu, int address) {
    return memory_read(cpu->bus, address);
}

int main() {
    // Initialize bus, CPU, and memory
    Bus system_bus;
    CPU cpu;
    Memory memory;
    cpu.bus = &system_bus;
    memory.bus = &system_bus;

    // Write data to memory
    memory_write(&memory, 0, 10); // Writing value 10 at address 0

    // CPU reads data from memory
    int data_read = cpu_operation(&cpu, 0);
    printf("Data read by CPU: %d\n", data_read);

    return 0;
}
