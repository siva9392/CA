#include <stdio.h>
int main() {
    int a = 5;
    int b = 10;
    int c;

    // Instruction 1: Load the value of 'a' into a register
    int temp_a = a;

    // Instruction 2: Load the value of 'b' into a register
    int temp_b = b;

    // Instruction 3: Add the values stored in the two registers and store the result in 'c'
    c = temp_a + temp_b;

    // Instruction 4: Multiply 'c' by 2 and store the result in 'c'
    c = c * 2;

    // Instruction 5: Print the value of 'c'
    printf("Result: %d\n", c);

    return 0;
}
