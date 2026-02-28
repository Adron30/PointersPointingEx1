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

    myReg.f1 = &b; //Setting the value of myReg.f1 pointing to 'b'
    *(myReg.f1) = 10; //Dereferencing the value of myReg.f1 to 10 (b = 10)

    myReg.f2 = &c;  // F2 is pointing to the value of C (f2 = &C)
    *(myReg.f2) = &d; //Dereferecning the value of pointer f2 to set it to point at the pointer of d (c = &d)
    *(*(myReg.f2)) = 30; //Dereferencing the value of pointer F2 and dereferencing the value of C.

    myReg.f3 = &myRegR2; //Pointing to Register 2

    for (i = 0; i < 3; i++) {
        myReg.f3->f1 = &array[i]; //For i (0,2) the value of the pointer of the value array[i] is asigned to pointer f1 (f1 = array[i])
        *(myReg.f3->f1) = i; //Set the dereference value of f1 (which is a pointer at array[i]) to 'i'
    }
    myReg.f3->f2 = &c; //Set the value of reg2.f2 pointing to the pointer 'c'

    myReg.f3->f3 = NULL; //Set the pointer of reg2.f3 to NULL

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