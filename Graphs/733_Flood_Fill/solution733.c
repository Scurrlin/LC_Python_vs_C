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

// Runtime1: 0ms, beats 100%
// Memory1: 13.24MB, beats 9.94%

// Runtime2: 0ms, beats 100%
// Memory2: 13.25MB, beats 9.94%

// Runtime3: 0ms, beats 100%
// Memory3: 12.93MB, beats 67.08%