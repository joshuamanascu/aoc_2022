#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int topN(char*, int);

int main(int argc, char *argv[]) {
	char *filename = "";
	
	if (argc == 2) {
		filename = argv[1];
	}
	else {
		return -1;
	}
	
	/*int max = 0;
	int count = 0;*/
	
	/*char buffer[1000];
	
	while (fgets(buffer, 999, fp) != NULL) {
		//printf("%s",buffer);
		
		if (strcmp(buffer, "\n") == 0) {
			if (count > max) {
				max = count;
			}
			count = 0;
		}
		else {
			int tmp = 0;
			sscanf(buffer, "%d\n", &tmp);
			count += tmp;
		}
		
	}
	fclose(fp);*/
	
	int maxOne = topN(filename, 1);
	
	printf("%d\n", maxOne);
	
	int maxThree = topN(filename, 3);
	
	printf("%d\n", maxThree);
}

int topN(char *filename, int num) {
	FILE *fp = fopen(filename,"r");
	char buffer[1000];
	
	int max[num];
	for (int i = 0; i < num; i++) {
		max[i] = 0;
	}
	int count = 0;
	
	while (fgets(buffer, 999, fp) != NULL) {
		//printf("%s",buffer);
		
		if (strcmp(buffer, "\n") == 0) {
			int min_index = 0;
			int min_value = max[min_index];
			for (int i = 1; i < num; i++){
				if(max[i] < min_value) {
					min_value = max[i];
					min_index = i;
				}
			}
			
			if (count > max[min_index]) {
				max[min_index] = count;
			}
			count = 0;
			
		}
		else {
			int tmp = 0;
			sscanf(buffer, "%d\n", &tmp);
			count += tmp;
		}
		
	}
	fclose(fp);
	
	
	int min_index = 0;
	int min_value = max[min_index];
	for (int i = 1; i < num; i++){
		if(max[i] < min_value) {
			min_value = max[i];
			min_index = i;
		}
	}
			
	if (count > max[min_index]) {
		max[min_index] = count;
	}
	count = 0;
			
	
	
	int result = 0;
	for (int i = 0; i < num; i++) {
		result += max[i];
	}
	
	return result;
}
