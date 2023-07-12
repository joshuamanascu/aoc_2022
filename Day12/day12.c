#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

char **grid;
bool **visits;
int **distance;
int width, height;

struct Point {
	int x;
	int y;
	char h;
}S, E;

//FUNCTIONS
void loadData(FILE*);
int partOne();
int partTwo();

int main(int argc, char *argv[]) {
	
	char *filename = argv[1];
	FILE *fp = fopen(filename, "r");
	
	loadData(fp);
	
	printf("PART ONE: %d\n", partOne());
	printf("PART TWO: %d\n", partTwo());
	
}

struct Point findSmallest(struct Point start) {
	struct Point result = {.x = start.x, .y = start.y, .h = start.h};
	int smallest = INT_MAX;
	
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (!visits[i][j] && distance[i][j] < smallest) {
				smallest = distance[i][j];
				result.x = i;
				result.y = j;
				result.h = grid[i][j];
				
			}
		}
	}
	
	return result;
	
}

//Generalize part 1
int shortestPath(struct Point start) {
	struct Point current = {.x = start.x, .y = start.y, .h = start.h};
	
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			distance[i][j] = INT_MAX;
			visits[i][j] = false;
		}
	}
	
	distance[start.x][start.y] = 0; //Distance to itself is zero
	
	while (current.x != E.x || current.y != E.y) {
		int x = current.x;
		int y = current.y;
		int h = current.h;
		
		//Check neighbors
		
		if (y < height - 1 && !visits[x][y+1] && h + 1 >= grid[x][y+1] ) { //BELOW
			if (distance[x][y+1] > distance[x][y] + 1) distance[x][y+1] = distance[x][y] + 1;
		}
		if (y > 0 && !visits[x][y-1] && h + 1 >= grid[x][y-1] ) { //ABOVE
			if (distance[x][y-1] > distance[x][y] + 1) distance[x][y-1] = distance[x][y] + 1;
		}
		if (x < width - 1 && !visits[x+1][y] && h + 1 >= grid[x+1][y] ) { //RIGHT
			if (distance[x+1][y] > distance[x][y] + 1) distance[x+1][y] = distance[x][y] + 1;
		}
		if (x > 0 && !visits[x-1][y] && h + 1 >= grid[x-1][y]) { //LEFT
			if (distance[x-1][y]> distance[x][y] + 1) distance[x-1][y] = distance[x][y] + 1;
		}
		
		visits[x][y] = true; //Current square has now been visited
		
		//printf("x: %d     y: %d    h: %c\n", x, y, h);
		
		current = findSmallest(start);
		
		if (current.x == start.x && current.y == start.y) return INT_MAX; // No path to goal
	}
	
	return distance[current.x][current.y];
}

int partTwo() {
	int smallest = INT_MAX;
	
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (grid[i][j] != 'a') continue;
			
			
			
			struct Point start = {.x = i, .y = j, .h = grid[i][j]};
			int test = shortestPath(start);
			//printf("x: %d    y: %d    h: %c\n", i, j, grid[i][j]);
			
			if (test < smallest) smallest = test;
		
		}
		
	}
	
	return smallest;
	
	
}

//Attempt Dijkstra's algorithm
int partOne() {
	
	return shortestPath(S);
}

void loadData(FILE *fp) {
	char buffer[1000];
	fgets(buffer, 999, fp);
	
	width = strlen(buffer) - 1; //Exclude \n
	fseek(fp, 0, SEEK_END);
	
	height = ftell(fp) / width;
	
	fseek(fp, 0, SEEK_SET); // Return to start
	grid = calloc(width, sizeof(char*));
	
	for (int i = 0; i < width; i++) {
		grid[i] = calloc(height, sizeof(char));
	}
	
	for (int i = 0; i < height; i++) {
		fgets(buffer, 999, fp);
		
		for (int j = 0; j < width; j++) {
			grid[j][i] = buffer[j]; //So we can index [x][y]
			
			if (buffer[j] == 'S') {
				S.x = j;
				S.y = i;
				S.h = 'a';
				grid[S.x][S.y] = 'a';
			}
			else if (buffer[j] == 'E') {
				E.x = j;
				E.y = i;
				E.h = 'z';
				grid[E.x][E.y] = 'z';
			}
		}
	}
	
	visits = calloc(width, sizeof(bool*)); //Has the location been visited?
	distance = calloc(width, sizeof(int*)); //Tentative distance value, INT_MAX indicates tentative infinity
	for (int i = 0; i < width; i++) {
		visits[i] = calloc(height, sizeof(bool));
		distance[i] = calloc(height, sizeof(int));
	}
	
}
