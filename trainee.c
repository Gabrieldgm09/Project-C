#include <stdio.h>
#include <locale.h>

float divInts(int x, int y) {
    
    float q = (float)x/y;
    
    return q;
}

int main(void) {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int x, y;
    
    printf("Declare o valor de x: ");
    scanf ("%d", &x);
    
    printf("Declare o valor de y: ");
    scanf ("%d", &y);
    
    if (y == 0) {
        printf("O resultado da divisão é indeterminada");
    } else {
        printf("O resultado da divisão é: %.2f", divInts(x,y));
    }
    
    return 0;
}

