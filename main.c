#include <stdio.h>

typedef struct _Reg {
    int* f1;
    int** f2;
    struct _Reg* f3;
} Reg;

int main() {
    Reg myReg;
    Reg myRegR2;

    int i = 0;  // Only thing I will assign a value
    int b;
    int d;
    int* c;
    int array[3];

    myReg.f1 = &b;
    *(myReg.f1) = 10;

    myReg.f2 = &c;  // Pointing to the pointer of C
    *(myReg.f2) = &d;
    *(*(myReg.f2)) = 30;

    myReg.f3 = &myRegR2;

    for (i = 0; i < 3; i++) {
        myReg.f3->f1 = &array[i];
        *(myReg.f3->f1) = i;
    }
    myReg.f3->f2 = &c;

    myReg.f3->f3 = NULL;

    printf("\nVALUES:\n");
    printf("Value of B: %d\n", b);
    printf("Value of D: %d\n", d);
    printf("Value of position 0 of array: %d\n", array[0]);
    printf("Value of position 1 of array: %d\n", array[1]);
    printf("Value of position 2 of array: %d\n", array[2]);

    printf("\nDEREFERENCE VALUES FROM THE STRUCT REGISTER 1\n\n");
    printf("Deref value of myReg.f1: %d\n", *myReg.f1);
    printf("Deref value of myReg.f2: %d\n\n", *(*myReg.f2));

    for (i = 0; i < 3; i++) {
        myReg.f3->f1 = &array[i];
        printf("Deref value of myReg.f3->f1[%d]: %d\n", i, *myReg.f3->f1);
    }

    printf("\nDeref value of myReg.f3->f2: %d\n", *(*myReg.f3->f2));
    if (myReg.f3->f3 == NULL) {  // I don't know how to actually print the type of NULL.
        printf("Deref value of myReg.f3->f3: NULL\n");
    } else {
        printf("Deref value of myReg.f3->f3: Can't access that location\n");
    }

    return 0;
}