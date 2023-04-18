#include <stdio.h>

int main(void) {
    FILE* file;
    char c;
    int floor = 0, instruction_index = 0, basement_index = 0;

    file = fopen("input1.txt", "r");
    if (NULL == file) {
        printf("Failed to read input file.\n");
        return 1;
    }

    while ((c = fgetc(file)) != EOF) {
        if (c == '(') floor++;
        else floor--;

        if (!basement_index && floor == -1)
            basement_index = instruction_index + 1;

        instruction_index++;
    }

    fclose(file);
    printf("%d\n%d\n", floor, basement_index);
    return 0;
}
