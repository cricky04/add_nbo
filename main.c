#include <stdint.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    uint32_t a, b, c;
    uint32_t t;
    FILE * fone = fopen(argv[1], "r");
    FILE * ftwo = fopen(argv[2], "r");

    fread(&a, sizeof(uint32_t), 1, fone);
    fread(&b, sizeof(uint32_t), 1, ftwo);

    // ntoh
    a = ((a & 0x000000FF) << 24) | ((a & 0x0000FF00) << 8) | ((a & 0x00FF0000) >> 8) | ((a & 0xFF000000) >>24);

    b = ((b & 0x000000FF) << 24) | ((b & 0x0000FF00) << 8) | ((b & 0x00FF0000) >> 8) | ((b & 0xFF000000) >>24);

    c = a + b;
    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)", a, a, b, b,c, c);
}
