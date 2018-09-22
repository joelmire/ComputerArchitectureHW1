#include <stdio.h>
#include <stdlib.h>

float* e_ptr;

float foo(float* x, float *y, float* z){
    if (*x > *y + *z) {
        return *x;
    }
    else {
        return *y+*z;
    }
}

int main() {
    float a = 1.2;
    e_ptr = &a;
    float* b_ptr = (float*)malloc (2*sizeof(float));
    b_ptr[0] = 7.0;
    b_ptr[1] = 4.0;
    float c = foo(e_ptr, b_ptr, b_ptr+1);
    free(b_ptr);
    if (c > 10.5) {
        return 0;
    }
    else {
        return 1;
    }
}