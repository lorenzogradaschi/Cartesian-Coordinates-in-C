#include <stdio.h>
#include <math.h>

#define WIDTH 60
#define HEIGHT 20
#define X WIDTH/2
#define Y HEIGHT/2

struct coordinates {
    int x;
    int y;
};

void moveCoordinates(struct coordinates *coord) {
    printf("Insert value of coordinates (x y): ");
    scanf("%d %d", &coord->x, &coord->y);
}

void displayGrid(char grid[HEIGHT][WIDTH]) {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++)
            putchar(grid[y][x]);
        putchar('\n');
    }
}

void initializeGrid(char grid[HEIGHT][WIDTH]) {
    int x, y;
    for (y = 0; y < HEIGHT; y++)
        for (x = 0; x < WIDTH; x++)
            grid[y][x] = ' ';
    for (y = 0; y < HEIGHT; y++)
        grid[y][X] = '|';
    for (x = 0; x < WIDTH; x++)
        grid[Y][x] = '-';
    grid[Y][X] = '+';
}

double calculateDistance(struct coordinates point1, struct coordinates point2) {
    return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
}

int main() {
    char grid[HEIGHT][WIDTH];
    struct coordinates point1 = {0, 0};
    struct coordinates point2 = {0, 0};
    int risp = 1;

    do {
        printf("Enter first point coordinates:\n");
        moveCoordinates(&point1);

        printf("Enter second point coordinates:\n");
        moveCoordinates(&point2);

        initializeGrid(grid);

        int gridX1 = X + point1.x;
        int gridY1 = Y - point1.y;

        int gridX2 = X + point2.x;
        int gridY2 = Y - point2.y;

        if (gridX1 >= 0 && gridX1 < WIDTH && gridY1 >= 0 && gridY1 < HEIGHT) {
            grid[gridY1][gridX1] = '*';
        }

        if (gridX2 >= 0 && gridX2 < WIDTH && gridY2 >= 0 && gridY2 < HEIGHT) {
            grid[gridY2][gridX2] = '*';
        }

        displayGrid(grid);

        double distance = calculateDistance(point1, point2);
        printf("Distance between (%d, %d) and (%d, %d) is: %.2f\n",
               point1.x, point1.y, point2.x, point2.y, distance);

        printf("Do you want to insert another pair of points? (1 for yes, 0 for no): ");
        scanf("%d", &risp);

    } while (risp > 0);

    return 0;
}

