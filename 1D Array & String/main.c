#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getstr(char **str, int cap);

int main() {
    int n;
    scanf("%d", &n);

    // Flush leftover newline
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    char *str = NULL;
    getstr(&str, n);

    // Tokenize and calculate sum
    int sum = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        sum += atoi(token);
        token = strtok(NULL, " ");
    }

    printf("%d", sum);
    free(str);
    return 0;
}

void getstr(char **str, int cap) {
    int ch;
    size_t len = 0, capacity = cap * 2;

    *str = malloc(capacity);
    if (!*str) {
        perror("malloc failed");
        return;
    }

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (len + 1 >= capacity) {
            printf("times");
            capacity *= 2;
            char *tmp = realloc(*str, capacity);
            if (!tmp) {
                perror("realloc failed");
                free(*str);
                *str = NULL;
                return;
            }
            *str = tmp;
        }
        (*str)[len++] = ch;
    }

    (*str)[len] = '\0';
}
