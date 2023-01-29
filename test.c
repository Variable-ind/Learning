

#include <stdio.h>


float halveit(const float tst[]){
    return tst[1];
}

int main(int argc, const char *argv[]){
    float test[4] = {1.5, 2.4, 3.2, 4.7};
    printf("test \n");
    printf("before %f \n", test[3]);
    printf("%f \n", halveit(test));
    printf("after %f \n", test[3]);
    return (0);
}