#include <stdio.h>
int main() {
    int a = 5;
    int b = 10;
    int c;

    // Instruction 1: Compare 'a' and 'b' and set a flag if 'a' is greater than 'b'
    int flag = (a > b);

    // Instruction 2: If the flag is set, add 'a' and 'b' and store the result in 'c', else store 'b' in 'c'
    if (flag) {
        c = a + b;
    } else {
        c = b;
    }

    // Instruction 3: Multiply 'c' by 2 and store the result in 'c'
    c = c * 2;

    // Instruction 4: Print the value of 'c'
    printf("Result: %d\n", c);

    return 0;
}
