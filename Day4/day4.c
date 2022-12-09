#include <stdio.h>
#include <string.h>

int partOne(FILE*);
int partTwo(FILE*);

struct range {
	int start;
	int end;
}range1, range2;

int main(int argc, char *argv[]) {
	
	char *filename;
	
	if (argc == 2) {
		filename = argv[1];
	}
	else {
		return -1;
	}
	
	FILE *fp = fopen(filename, "r");
	printf("PART ONE: %d\n", partOne(fp));
	
	fp = freopen(filename, "r", fp);
	printf("PART TWO: %d\n", partTwo(fp));
	
	fclose(fp);
	
}

int partOne(FILE *fp) {
	int result = 0;
	char buffer[1000];
	
	while(fgets(buffer, 999, fp) != NULL) {
		
		sscanf(buffer, "%d-%d,%d-%d", &range1.start, &range1.end, &range2.start, &range2.end);
		
		if (range1.start <= range2.start && range1.end >= range2.end) {
			result++;
		}
		else if (range2.start <= range1.start && range2.end >= range1.end) {
			result++;
		}
	}
	
	return result;
}

int partTwo(FILE *fp) {
	int result = 0;
	char buffer[1000];
	
	while(fgets(buffer, 999, fp) != NULL) {
		
		sscanf(buffer, "%d-%d,%d-%d", &range1.start, &range1.end, &range2.start, &range2.end);	
		
		if (range1.start <= range2.start && range1.end >= range2.start) {
			result++;
		}
		else if (range2.start <= range1.start && range2.end >= range1.start) {
			result++;
		}
	}
	
	return result;
}
