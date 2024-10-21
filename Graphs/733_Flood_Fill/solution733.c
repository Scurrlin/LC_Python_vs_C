#include <stdio.h>
#include <stdlib.h>

void flood_fill(int** image, int imageSize, int* imageColSize, int x, int y, int start_color, int new_color);

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int new_color, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    *returnColumnSizes = (int*)malloc(imageSize * sizeof(int));

    for (int i = 0; i < imageSize; ++i) {
        (*returnColumnSizes)[i] = imageColSize[i];
    }

    int start_color = image[sr][sc];

    if (start_color == new_color) {
        return image;
    }

    flood_fill(image, imageSize, imageColSize, sr, sc, start_color, new_color);

    return image;
}

void flood_fill(int** image, int imageSize, int* imageColSize, int x, int y, int start_color, int new_color) {
    if (x < 0 || x >= imageSize || y < 0 || y >= imageColSize[x]) {
        return;
    }

    if (image[x][y] != start_color) {
        return;
    }

    image[x][y] = new_color;

    flood_fill(image, imageSize, imageColSize, x - 1, y, start_color, new_color);
    flood_fill(image, imageSize, imageColSize, x + 1, y, start_color, new_color);
    flood_fill(image, imageSize, imageColSize, x, y - 1, start_color, new_color);
    flood_fill(image, imageSize, imageColSize, x, y + 1, start_color, new_color);
}

// Runtime1:
// Memory1:

// Runtime2:
// Memory2:

// Runtime3:
// Memory3: