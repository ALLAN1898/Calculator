/*
 * Autor: Allan Breno
 * Email: allan.breno@upe.br
 * Data de Criação: 16 setembro
 * Última Revisão: 18 setembro 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void decimalParaBinario(int n) {
    int binario[32];
    int i = 0;

    printf("Passos para conversão de decimal %d para binário:\n", n);
    while (n > 0) {
        binario[i] = n % 2;
        printf("%d / 2 = %d, resto = %d\n", n, n / 2, binario[i]);
        n = n / 2;
        i++;
    }

    printf("Número binário: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
}


void decimalParaOctal(int n) {
    int octal[32];
    int i = 0;

    printf("Passos para conversão de decimal %d para octal:\n", n);
    while (n > 0) {
        octal[i] = n % 8;
        printf("%d / 8 = %d, resto = %d\n", n, n / 8, octal[i]);
        n = n / 8;
        i++;
    }

    printf("Número octal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}


void decimalParaHexadecimal(int n) {
    char hexa[32];
    int i = 0;

    printf("Passos para conversão de decimal %d para hexadecimal:\n", n);
    while (n > 0) {
        int temp = n % 16;
        if (temp < 10) {
            hexa[i] = temp + 48;
        } else {
            hexa[i] = temp + 55;
        }
        printf("%d / 16 = %d, resto = %d\n", n, n / 16, temp);
        n = n / 16;
        i++;
    }

    printf("Número hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexa[j]);
    }
    printf("\n");
}


void decimalParaBCD(int n) {
    printf("Passos para conversão de decimal %d para código BCD:\n", n);

    printf("Número BCD: ");
    while (n > 0) {
        int digito = n % 10;
        printf("\n%d = ", digito);
        for (int i = 3; i >= 0; i--) {
            printf("%d", (digito >> i) & 1);
        }
        n = n / 10;
    }
    printf("\n");
}


void decimalParaComplemento2(int n) {
    printf("Passos para conversão de decimal %d para complemento a 2 (16 bits):\n", n);
    
    unsigned short int comp2;
    
    if (n >= 0) {
        comp2 = n; 
    } else {
        comp2 = (1 << 16) + n; 
    }

    printf("Número em complemento a 2 (16 bits): ");
    for (int i = 15; i >= 0; i--) {
        printf("%d", (comp2 >> i) & 1);
    }
    printf("\n");
}


void mostrarFloatBits(float f) {
    unsigned int bits = *((unsigned int*)&f);

    printf("Sinal: %d\n", (bits >> 31) & 1);
    printf("Expoente: ");
    for (int i = 30; i >= 23; i--) {
        printf("%d", (bits >> i) & 1);
    }
    printf("\nFração: ");
    for (int i = 22; i >= 0; i--) {
        printf("%d", (bits >> i) & 1);
    }
    printf("\n");
}


void mostrarDoubleBits(double d) {
    unsigned long long bits = *((unsigned long long*)&d);

    printf("Sinal: %llu\n", (bits >> 63) & 1);
    printf("Expoente: ");
    for (int i = 62; i >= 52; i--) {
        printf("%llu", (bits >> i) & 1);
    }
    printf("\nFração: ");
    for (int i = 51; i >= 0; i--) {
        printf("%llu", (bits >> i) & 1);
    }
    printf("\n");
}

int main() {
    int numero, escolha;
    float numFloat;
    double numDouble;

    printf("Digite um número decimal: ");
    scanf("%d", &numero);

    printf("Escolha a conversão desejada:\n");
    printf("1 - Decimal para Binário\n");
    printf("2 - Decimal para Octal\n");
    printf("3 - Decimal para Hexadecimal\n");
    printf("4 - Decimal para Código BCD\n");
    printf("5 - Decimal para Complemento a 2 (16 bits)\n");
    printf("6 - Converter Real para Float (bits)\n");
    printf("7 - Converter Real para Double (bits)\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            decimalParaBinario(numero);
            break;
        case 2:
            decimalParaOctal(numero);
            break;
        case 3:
            decimalParaHexadecimal(numero);
            break;
        case 4:
            decimalParaBCD(numero);
            break;
        case 5:
            decimalParaComplemento2(numero);
            break;
        case 6:
            printf("Digite um número float: ");
            scanf("%f", &numFloat);
            mostrarFloatBits(numFloat);
            break;
        case 7:
            printf("Digite um número double: ");
            scanf("%lf", &numDouble);
            mostrarDoubleBits(numDouble);
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }

    return 0;
}
