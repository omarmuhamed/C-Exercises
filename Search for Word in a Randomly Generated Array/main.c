#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arrsize = 0;
int *result;

void inserttoarr(int row, int col, int row2, int col2) {
    *(result + arrsize - 4) = row;
    *(result + arrsize - 3) = col;
    *(result + arrsize - 2) = row2;
    *(result + arrsize - 1) = col2;
}

int main() {
    int m, n, i, x, qs, big, wordsize = 0, col, row, resultcount;
    char *pchars, *pword;
    Matrix:
    printf("Enter Rows count: ");
    scanf("%d", &m);
    printf("Enter Cols count: ");
    scanf("%d", &n);
    char chars[m][n];
    pchars = &chars[0][0];
    srand(time(NULL));
    printf("A\t");
    for (i = 0; i < n; i++) {
        printf("%d\t", i);
    }
    printf("\n\n");
    for (i = 0; i < m; i++) {
        printf("%d\t", i);
        for (x = 0; x < n; x++) {
            *(pchars + (i * n) + x) = 'A' + (rand() % 26);
            printf("%c\t", *(pchars + (i * n) + x));
        }
        printf("\n\n");
    }

    if (m > n) {
        big = m;
    } else {
        big = n;
    }
    char word[big];
    pword = &word[0];
    EnterTheWord:
    printf("Enter the word: ");
    fflush(stdin);
    gets(word);
    for (i = 0; *(pword + i) != '\0'; i++) {
        if ((int) *(pword + i) > 90) {
            *(pword + i) = (char) ((int) *(pword + i) - 32);
        }
        wordsize++;
    }
    if (wordsize > big) {
        printf("Word size cann't be bigger than rows or cols, try again.\n");
        free(pword);
        wordsize = 0;
        goto EnterTheWord;
    }
    result = (int *) malloc(sizeof(int) * (int) (m * n / wordsize));
    for (i = 0; i < m * n; i++) {
        if ((int) (*(pchars + i)) == *pword) {
            row = (int) (i / n);
            col = i % n;
            if (n - (col + wordsize) >= 0) {
                for (x = 1; x < wordsize; x++) {
                    if ((int) (*(pchars + i + x)) != (int) *(pword + x)) {
                        break;
                    }

                    if (x == wordsize - 1) {
                        arrsize += 4;
                        inserttoarr(row, col, row, (i + wordsize - 1) % n);

                    }

                }
            }
            if (n - (n - col - 1) - wordsize >= 0) {
                for (x = 1; x < wordsize; x++) {
                    if ((int) (*(pchars + i - x)) != (int) *(pword + x)) {
                        break;
                    }
                    if (x == wordsize - 1) {
                        arrsize += 4;
                        inserttoarr(row, col, row, ((i - wordsize) + 1) % n);
                    }


                }
            }
            if (m - (row + wordsize) >= 0) {
                for (x = 1; x < wordsize; x++) {
                    if ((int) (*(pchars + i + x * n)) != (int) *(pword + x)) {
                        break;
                    }
                    if (x == wordsize - 1) {
                        arrsize += 4;
                        inserttoarr(row, col, ((int) (i + wordsize * n) / n) - 1, col);
                    }

                }
            }
            if (((row + 1) - wordsize) >= 0) {
                for (x = 1; x < wordsize; x++) {
                    if ((int) (*(pchars + i - x * n)) != (int) *(pword + x)) {
                        break;
                    }
                    if (x == wordsize - 1) {
                        arrsize += 4;
                        inserttoarr(row, col, ((int) (i - wordsize * n) / n) + 1, col);
                    }


                }
            }
        }

    }
    if (arrsize == 0) {
        printf("Not found.\n");
    } else {
        result = (int *) realloc(result, arrsize * sizeof(int));
        resultcount = arrsize / sizeof(int);
        printf("(%s) found %d time/s.\n", pword, resultcount);
        for (i = 0; i < resultcount; i++) {
            printf("A[%d][%d]->A[%d][%d]\n", *(result + i * 4), *(result + (i * 4) + 1), *(result + (i * 4) + 2),
                   *(result + (i * 4) + 3));
        }
    }
    printf("Do you want to search for another word? (1 Yes / 0 No): ");
    scanf("%d", &qs);
    if (qs == 1) {
        printf("Do you want to change the Matrix? (1 Yes / 0 No): ");
        scanf("%d", &qs);
        if (qs == 1) {
            wordsize = 0;
            arrsize = 0;
            free(pword);
            free(result);
            free(pchars);
            goto Matrix;
        } else {
            wordsize = 0;
            arrsize = 0;
            free(pword);
            free(result);
            goto EnterTheWord;
        }
    }

}
