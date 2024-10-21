#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

void enqueue(Point* queue, int* front, int* rear, int x, int y);
Point dequeue(Point* queue, int* front);
int is_empty(int front, int rear);

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    if (rows == 0) return -1;
    
    int cols = gridColSize[0];
    int fresh_count = 0;
    int front = 0, rear = 0;
    Point* queue = (Point*)malloc(rows * cols * sizeof(Point));

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == 2) {
                enqueue(queue, &front, &rear, r, c);
            } else if (grid[r][c] == 1) {
                fresh_count++;
            }
        }
    }

    int minutes_passed = 0;
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!is_empty(front, rear) && fresh_count > 0) {
        minutes_passed++;
        int rotten_count = rear - front;
        
        for (int i = 0; i < rotten_count; ++i) {
            Point point = dequeue(queue, &front);
            int x = point.x;
            int y = point.y;

            for (int d = 0; d < 4; ++d) {
                int xx = x + directions[d][0];
                int yy = y + directions[d][1];

                if (xx < 0 || xx >= rows || yy < 0 || yy >= cols || grid[xx][yy] != 1) {
                    continue;
                }

                grid[xx][yy] = 2;
                fresh_count--;
                enqueue(queue, &front, &rear, xx, yy);
            }
        }
    }

    free(queue);

    return fresh_count == 0 ? minutes_passed : -1;
}

void enqueue(Point* queue, int* front, int* rear, int x, int y) {
    queue[*rear].x = x;
    queue[*rear].y = y;
    (*rear)++;
}

Point dequeue(Point* queue, int* front) {
    Point point = queue[*front];
    (*front)++;
    return point;
}

int is_empty(int front, int rear) {
    return front == rear;
}

// Runtime1:
// Memory1:

// Runtime2:
// Memory2:

// Runtime3:
// Memory3: