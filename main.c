#include <stdio.h> 
#include <math.h>
int main(void)
{
    
    float var1, var2,var3, var4, med;
 
    printf("Digite a nota1: ");
    scanf("%f", &var1);

    printf("Digite a nota2: ");
    scanf("%f", &var2);

    printf("Digite a nota3: ");
    scanf("%f", &var3);

    printf("Digite a nota4: ");
    scanf("%f", &var4);

    med=(var1+var2+var3+var4)/4;
    

    printf("Média: %.1f", med);
    if(med>=15) {
    printf("[aluno aprovado]");
    } else printf("[aluno de recuperação]");

    return 0;



}

 