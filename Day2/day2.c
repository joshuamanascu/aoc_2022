#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//enum {A='A',B,C};
//enum {X='X',Y,Z};

int score(char, char);

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
	//printf("%d\n", 3 % 3);
	
	//Part 1
	/*while(fgets(buffer, 999, fp) != NULL) {
		char myMove, theirMove;
		sscanf(buffer, "%c %c", &theirMove, &myMove);
		
		result += score(myMove, theirMove);
	}
	printf("%d\n", result);*/
	
	//Part 2
	char myMove;
	while(fgets(buffer, 999, fp) != NULL) {
		char myResult, theirMove;
		sscanf(buffer, "%c %c", &theirMove, &myResult);
		
		switch(myResult) {
			case 'X':
				myMove = (((theirMove - 'A' + 2) % 3) + 'X');
				break;
			case 'Y':
				myMove = ((theirMove - 'A') + 'X');
				break;
			case 'Z':
				myMove = (((theirMove - 'A' + 1) % 3) + 'X');
				break;
		}
		
		result += score(myMove, theirMove);
	}
	printf("%c\n%d\n", myMove, result);
	
}

int score(char myMove, char theirMove) {
	int result = 0;
	
	switch(myMove) {
		case 'X':
			result += 1;
			
			switch(theirMove) {
				case 'A':
					result += 3;
					break;
				case 'B':
					result += 0;
					break;
				case 'C':
					result += 6;
					break;
			}
			break;
		case 'Y':
			result += 2;
			
			switch(theirMove) {
				case 'A':
					result += 6;
					break;
				case 'B':
					result += 3;
					break;
				case 'C':
					result += 0;
					break;
			}
			break;
		case 'Z':
			result += 3;
			
			switch(theirMove) {
				case 'A':
					result += 0;
					break;
				case 'B':
					result += 6;
					break;
				case 'C':
					result += 3;
					break;
			}
			break;
	}
	
	return result;
}
