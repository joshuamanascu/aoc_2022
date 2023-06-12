#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **data;
int rows, columns;

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

int partTwo() {
	int maxScore = 0;
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			char val = data[i][j];
			int score = 0;
			int direction = 0;
			
			for (int k = i-1; k >= 0; k--) { //UP
				if (val <= data[k][j]) {
					direction++;
					break;
				}
				else direction++;
			}
			score = direction;
			direction = 0;
			for (int k = i + 1; k < columns; k++) { //DOWN
				if (val <= data[k][j]) {
					direction++;
					break;
				}
				else direction++;
			}
			score *= direction;
			direction = 0;
			for (int k = j - 1; k >= 0; k--) { //LEFT
				if (val <= data[i][k]) {
					direction++;
					break;
				}
				else direction++;
			}
			score *= direction;
			direction = 0;
			for (int k = j + 1; k < rows; k++) { //RIGHT
				if (val <= data[i][k]) {
					direction++;
					break;
				}
				else direction++;
			}
			score *= direction;
			
			if (score > maxScore) maxScore = score;
			
		}
	}
	
	return maxScore;
}

int partOne() {
	int visible = 0;
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			char val = data[i][j];
			if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1) visible++;
			else {
				int directions = 4;
				
				for (int k = 0; k < i; k++) { //UP
					if (val <= data[k][j]) {
						directions--;
						break;
					}
				}
				for (int k = columns - 1; k > i; k--) { //DOWN
					if (val <= data[k][j]) {
						directions--;
						break;
					}
				}
				for (int k = 0; k < j; k++) { //LEFT
					if (val <= data[i][k]) {
						directions--;
						break;
					}
				}
				for (int k = rows - 1; k > j; k--) { //RIGHT
					if (val <= data[i][k]) {
						directions--;
						break;
					}
				}
				
				if (directions > 0) visible++;
				
			}
			
		}
	}
	
	return visible;
}

void loadData(FILE *fp) {
	char buffer[1000];
	rows = 0;
	
	while (fgets(buffer, 999, fp) != NULL) {
		rows++;
	}
	
	columns = strlen(buffer) - 1;
	
	//row number of char* pointers + space for the characters
	data = malloc(sizeof(char*) * rows);
	fseek(fp, 0, SEEK_SET);
	
	for (int i = 0; fgets(buffer, 999, fp) != NULL; i++) {
		data[i] = malloc(sizeof(char) * columns);
		strncpy(data[i], buffer, columns);
		data[i][columns] = '\0';
	}
}
