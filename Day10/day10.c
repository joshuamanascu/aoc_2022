#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int X, cycle;

int partOne(FILE*);
void partTwo(FILE*);

int main(int argc, char *argv[]) {
	char *filename = argv[1];
	FILE *fp = fopen(filename, "r");
	
	X = 1;
	cycle = 1;
	
	printf("PART ONE: %d\n", partOne(fp));
	
	X = 1;
	cycle = 1;
	fseek(fp, 0, SEEK_SET);
	
	partTwo(fp);
	
}

void partTwo(FILE *fp) {
	char buffer[1000];
	int change; //change in the cycle
	
	char row[41];
	memset(row, 0, 41);
	
	printf("------- PART TWO -------\n");
	
	while (fgets(buffer, 999, fp) != NULL) {
		if (buffer[0] == 'n') change = 1;
		else change = 2;
		
		for (int i = 0; i < change; i++) {
			
			
			if (abs((cycle - 1) % 40 - X) <= 1) row[(cycle - 1) % 40] = '#';
			else row[(cycle - 1) % 40] = '.';
			
			if (cycle % 40 == 0) {
				printf("%s\n", row);
				memset(row, 0, 41);
			}
			
			
			if (i == 1) {
				int add;
				sscanf(buffer, "addx %d", &add);
			
				X += add;
			}
			
			cycle++;
			
		}
	}
}

int partOne(FILE *fp) {
	
	char buffer[1000];
	int change; //change in the cycle
	int result = 0;
	
	while (fgets(buffer, 999, fp) != NULL) {
		if (buffer[0] == 'n') change = 1;
		else change = 2;
		
		for (int i = 0; i < change; i++) {
			cycle++;
			
			if (i == 1) {
				int add;
				sscanf(buffer, "addx %d", &add);
			
				X += add;
			}
			
			if (cycle == 20 || ((cycle - 20) % 40 == 0 && cycle <= 220)) {
				result += (cycle * X);
			}
		}
	}
	
	return result;
}
