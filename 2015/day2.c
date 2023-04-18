#include <stdio.h>

int surface_area(int l, int w, int h);
int smallest_side_area(int l, int w, int h);
int smallest_perimeter(int l, int w, int h);
int volume(int l, int w, int h);

int main(void) {
    FILE* file;
    int l, w, h;
    int wrapping_paper = 0, ribbon = 0;

    file = fopen("input2.txt", "r");
    while (fscanf(file, "%dx%dx%d", &l, &w, &h) != EOF) {
        wrapping_paper += surface_area(l, w, h) + smallest_side_area(l, w, h);
        ribbon += smallest_perimeter(l, w, h) + volume(l, w, h);
    }

    fclose(file);
    printf("%d\n%d\n", wrapping_paper, ribbon);
}

int surface_area(int l, int w, int h) {
    return 2 * l * w + 2 * w * h + 2 * h * l;
}

int smallest_side_area(int l, int w, int h) {
    int lw = l * w, wh = w * h, hl = h * l;
    int min = lw < wh ? lw : wh;
    min = min < hl ? min : hl;
    return min;
}

int smallest_perimeter(int l, int w, int h) {
    int lw = 2 * l + 2 * w, wh = 2 * w + 2 * h, hl = 2 * h + 2 * l;
    int min = lw < wh ? lw : wh;
    min = min < hl ? min : hl;
    return min;
}

int volume(int l, int w, int h) {
    return l * w * h;
}