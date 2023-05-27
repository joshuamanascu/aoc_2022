#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *crates[9];

void loadCrates(FILE*);
void partOne(FILE*);
void partTwo(FILE*);

int main(int argc, char *argv[]) {
	char *filename = argv[1];
	FILE *fp = fopen(filename, "r");
	
	loadCrates(fp);
	partOne(fp);
	
	fp = fopen(filename, "r");
	
	loadCrates(fp);
	partTwo(fp);
}

void loadCrates(FILE *fp) {
	
	for (int i = 0; i < 9; i++) {
		crates[i] = malloc(1000);
	}
	
	char buffer[1000];
	
	while(fgets(buffer, 999, fp) != NULL) {
		
		if (buffer[0] == ' ' && buffer[1] == '1') break;
		
		int stack = 1;
		char *token = strtok(buffer, "]");
		
		while (token != NULL && *(token + strlen(token) - 1) != '\n') {
			if (*token == ' ' || *token == '[') token++;
			if (*token == '[') token++;
			while (strncmp(token, "   ", 3) == 0) {
				token += 4;
				stack++;
			}
			if (*token == '[') token++;
			strncat(crates[stack-1], token, 1);
			stack++;
			
			token = strtok(NULL, "]");
		}
	}
	
}

void partOne(FILE *fp) {
	char buffer[1000];
	int num, src, dest;
	fgets(buffer, 999, fp); // Skip unncessary line
	
	while(fgets(buffer, 999, fp) != NULL) {
		sscanf(buffer, "move %d from %d to %d", &num, &src, &dest);
		
		for (int i = 0; i < num; i++) {
			char tmp[100];
			memset(tmp, 0, 100);
			
			if (*crates[src-1] != '\0') {
				snprintf(tmp, 99, "%c%s", *crates[src-1], crates[dest-1]);
				strncpy(crates[dest-1], tmp, 99);
				crates[src-1]++;
			}
			else {
				break;
			}
		}
	}
	
	for (int i = 0; i < 9; i++) {
		puts(crates[i]);
	}
	printf("\n");
	
}

void partTwo(FILE *fp) {
	char buffer[1000];
	int num, src, dest;
	fgets(buffer, 999, fp); // Skip unncessary line
	
	while(fgets(buffer, 999, fp) != NULL) {
		sscanf(buffer, "move %d from %d to %d", &num, &src, &dest);
		
		char tmp[100];
		memset(tmp, 0, 100); //Set memory to null
		strncpy(tmp, crates[src-1], num);
		strncat(tmp, crates[dest-1], 99);
		strncpy(crates[dest-1], tmp, 99);
		crates[src-1] += num;
	}
	
	for (int i = 0; i < 9; i++) {
		puts(crates[i]);
	}
	printf("\n");
}
