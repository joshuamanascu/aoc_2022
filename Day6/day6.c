#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool overlaps(char*, int);
int partOne(char*);
int partTwo(char*);

int main(int argc, char *argv[]) {
	char *filename = argv[1];
	FILE *fp = fopen(filename, "r");
	fseek(fp, 0, SEEK_END);
	long fileSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	
	char *buffer = malloc(fileSize + 1);
	fgets(buffer, fileSize + 1, fp);
	printf("PART ONE: %d\n", partOne(buffer));
	printf("PART TWO: %d\n", partTwo(buffer));
	
	
}

int partOne(char *in) {
	char *track = in;
	
	for (int i = 1; *(track + 4) != '\0'; i++) {
		if (!overlaps(track, 4)) return i + 3;
		else track++;
	}
	
	return -1;
}

int partTwo(char *in) {
	char *track = in;
	
	for (int i = 1; *(track + 14) != '\0'; i++) {
		if (!overlaps(track, 14)) return i + 13;
		else track++;
	}
	
	return -1;
}

bool overlaps(char *in, int num) {
	bool alpha[26];
	memset(alpha, false, 26);
	
	alpha[in[0] - 97] = true;
	
	for (int i = 1; i < num; i++) {
		if (alpha[in[i] - 97]) return true;
		else alpha[in[i] - 97] = true;
	}
	
	return false;
}
