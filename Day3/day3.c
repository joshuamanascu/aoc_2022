#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int priorityCommon(char*, char*, int);
int priorityCommonTriple(char*, char*, char*);

int main(int argc, char *argv[]) {
	
	char *filename = "";
	
	if (argc == 2) {
		filename = argv[1];
	}
	else {
		return -1;
	}
	
	FILE *fp = fopen(filename, "r");
	char buffer[1000];
	int result = 0;
	
	//Part 1
	/*while(fgets(buffer, 999, fp) != NULL) {
		buffer[strcspn(buffer, "\n")] = '\0';
		char compart1[500], compart2[500];
		
		int length = strlen(buffer) / 2;
		
		memset(compart1, 0, 500);
		memset(compart2, 0, 500);
		strncpy(compart1, buffer, length);
		strncpy(compart2, buffer + length, length);
		
		result += priorityCommon(compart1, compart2, length);
	}*/
	
	//Part 2
	char buffer2[1000], buffer3[1000];
	while(fgets(buffer, 999, fp) != NULL) {
		fgets(buffer2, 999, fp);
		fgets(buffer3, 999, fp);
		buffer[strcspn(buffer, "\n")] = '\0';
		buffer2[strcspn(buffer2, "\n")] = '\0';
		buffer3[strcspn(buffer3, "\n")] = '\0';
		
		result += priorityCommonTriple(buffer, buffer2, buffer3);
	}
	
	
	printf("%d\n", result);
}

int priorityCommonTriple(char *compart1, char *compart2, char *compart3) {
	
	int length = strlen(compart1);
	
	for (int i = 0; i < length; i++) {
		if (strchr(compart2, compart1[i]) != NULL && strchr(compart3, compart1[i]) != NULL) {
			char common = compart1[i];
			if (common < 'a') {
				return common - 'A' + 27;
			}
			else {
				return common - 'a' + 1;
			}
		}
	}
	
	return 0;
}

int priorityCommon(char *compart1, char *compart2, int length) {
	for (int i = 0; i < length; i++) {
		if (strchr(compart2, compart1[i]) != NULL) {
			char common = compart1[i];
			if (common < 'a') {
				return common - 'A' + 27;
			}
			else {
				return common - 'a' + 1;
			}
		}
	}
	
	return 0;
}
