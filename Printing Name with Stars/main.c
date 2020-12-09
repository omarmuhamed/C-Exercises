#include <stdio.h>
#include <math.h>

int size;

void PrintSpaces(int x, int y) {
    int i;
    for (i = x; i < y; i++) {
        printf(" ");
    }
}

void PrintStars(int x, int y) {
    int i;
    for (i = x; i < y; i++) {
        printf("* ");
    }
}

void O() {
    int i;
    int spacescount = 2 * size - 7;
    int firstline = size - 2;
    int secondline = size - 1;
    for (i = 0; i < size; i++) {
        if (i == 0 || i == secondline) {
            printf("  ");
            PrintStars(0, size - 2);
            printf("\n");
        } else if (i == 1 || i == firstline) {
            printf(" ");
            PrintStars(0, size - 1);
            printf("\n");
        } else {
            printf("* *");
            PrintSpaces(0, spacescount);
            printf("* *\n");

        }
    }

}

void M() {
    int spaces = 2 * size - 13;
    int i, k = 0, l = 0, m, n = 6, f;
    for (i = 0; i < size; i++) {
        printf("* *");
        if (spaces <= 0) {
            if (f != 1) {
                for (m = 0; m < 3; m++) {
                    PrintSpaces(0, size - n);
                    if (m == 0) {
                        printf("* * *");
                    } else if (m == 1) {
                        printf("* *");
                    } else {
                        printf("*");
                    }
                    PrintSpaces(0, size - n);
                    printf("* *\n");
                    if (m != 2) {
                        printf("* *");
                    }
                    n = n - 1;
                    i++;
                }
                i--;
                f = 1;
                continue;
            } else {
                PrintSpaces(0, 2 * size - 7);
            }
            printf("* *\n");
            continue;
        }
        PrintSpaces(0, k);
        k++;

        printf("* *");
        PrintSpaces(0, spaces);
        spaces -= 2;
        printf("* *");
        PrintSpaces(0, l);
        l++;
        printf("* *\n");
    }
}

void A() {
    int asize = (2 * size - 3) / 2, j, x;
    int y = 1;
    int spaces = asize - 3;
    int fpart = (int) (size / 2) - 3;

    for (x = 0; x < 3; x++) {
        PrintSpaces(0, asize + 1 - x);
        switch (x) {
            case 0:
                printf("*");
                break;
            case 1:
                printf("* *");
                break;
            case 2:
                printf("* * *");
                break;
        }

        printf("\n");
    }
    for (j = 0; j < fpart; j++) {
        PrintSpaces(0, spaces + 1);
        printf("* *");
        if (j == 0) {
            printf(" * *\n");
            spaces--;
            continue;
        } else {
            PrintSpaces(0, y + 2);
        }
        printf("* *");
        printf("\n");
        spaces -= 1;
        y += 2;
    }
    for (j = 0; j < 2; j++) {
        PrintSpaces(0, spaces + 1);
        PrintStars(0, (((2 * size) - 3) - (2 * spaces)) / 2 + 1);
        PrintSpaces(0, spaces);
        printf("\n");
        spaces -= 1;
    }
    for (x = 0; x < ceil((double) size / 2 - 3) + 1; x++) {
        PrintSpaces(0, spaces + 1);
        printf("* *");
        PrintSpaces(0, ((2 * size - 3) - (2 * spaces)) - 6);
        printf("* *\n");
        spaces--;
    }
}

void R() {
    int i;
    for (i = 0; i < 2; i++) {
        PrintStars(0, size - 1 + i);
        printf("\n");
    }
    for (i = 0; i < size / 2 - 2; i++) {
        printf("* *");
        PrintSpaces(0, 2 * size - 7);
        printf("* *\n");
    }
    for (i = 0; i < 2; i++) {
        PrintStars(0, size - i);
        printf("\n");
    }
    for (i = 0; i < size - (size / 2 + 2); i++) {
        printf("* *");
        PrintSpaces(0, 2 * size - 8);
        printf("* *\n");
    }
}

void H() {
    int i;
    for (i = 0; i < size; i++) {
        if (i == (int) size / 2 - 1 || i == (int) size / 2) {
            PrintStars(0, size);
            printf("\n");
            continue;

        } else {
            printf("* *");
            PrintSpaces(0, 2 * size - 7);
            printf("* *\n");
        }
    }
}

void E() {
    int i;
    for (i = 0; i < size; i++) {
        if (i == 0 || i == 1 || i == size - 1 || i == size - 2 || i == (int) size / 2 - 1 || i == (int) size / 2) {
            PrintStars(0, size);
            printf("\n");
            continue;
        } else {
            printf("* *\n");

        }
    }
}

void D() {
    int i, j;
    for (i = 0; i < size; i++) {
        if (i == 0) {
            for (j = 0; j < 2; j++) {
                PrintStars(0, size - 2 + j);
                printf("\n");
                i++;
            }
            i--;
        } else if (i == size - 2) {
            for (j = 0; j < 2; j++) {
                PrintStars(0, size - 1 - j);
                printf("\n");
                i++;
            }
        } else {
            printf("* *");
            PrintSpaces(0, 2 * size - 7);
            printf("* *\n");
        }
    }
}

int main() {
    printf("Enter a size >= 10: ");
    while (scanf("%d", &size)) {
        if (size >= 10) {
            break;
        } else {
            printf("Size can't be less than 10, try again: ");
        }
    }
    printf("\n");
    O();
    printf("\n");
    M();
    printf("\n");
    A();
    printf("\n");
    R();
    printf("\n");
    M();
    printf("\n");
    O();
    printf("\n");
    H();
    printf("\n");
    A();
    printf("\n");
    M();
    printf("\n");
    E();
    printf("\n");
    D();
}
