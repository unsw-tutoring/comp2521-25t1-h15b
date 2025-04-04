#include <stdio.h>

void solveHanoi(int numDisks, char *fromRod, char *toRod, char *otherRod) {
    // base case
    if (numDisks == 0) return;
    // move n-1 disks fromRod->otherRod
    solveHanoi(numDisks - 1, fromRod, otherRod, toRod);
    // move nth disk fromRod->toRod
    printf("Move disk from %s to %s\n", fromRod, toRod);
    // move n-1 disks otherRod->toRod
    solveHanoi(numDisks - 1, otherRod, toRod, fromRod);
}

int main(void) {
    printf("Solving the Towers of Hanoi problem with 5 disks...\n");
    solveHanoi(5, "A", "C", "B");
    return 0;
}
