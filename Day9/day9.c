#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct coord {
	int x; 
	int y; 
}H, T;

struct coord tails[9];

bool visits[5000][5000]; //Offset by 2500, so 0 represents -2500

int partOne(FILE *);
int partTwo(FILE *);

int main(int argc, char *argv[]) {
	char *filename = argv[1];
	FILE *fp = fopen(filename, "r");
	
	//Initial states
	H.x = 0;
	H.y = 0;
	T.x = 0;
	T.y = 0;
	
	printf("PART 1: %d\n", partOne(fp));
	
	//Initial states (again)
	H.x = 0;
	H.y = 0;
	for (int i = 0; i < 9; i++) {
		tails[i].x = 0;
		tails[i].y = 0;
	}
	
	fseek(fp, 0, SEEK_SET); //File pointer back to start
	printf("PART 2: %d\n", partTwo(fp));
}

int sign(int x) {
	if (x < 0) return -1;
	else if (x > 0) return 1;
	else return 0;
}

//Make T respond to the move by H. 
void respond(struct coord *H, struct coord *T) {
	int xDist = H->x - T->x;
	int yDist = H->y - T->y;
	
	bool move = true;
	
	if (abs(xDist) > 1) {
		T->x += sign(xDist);
		if (yDist != 0 ) {
			T->y += sign(yDist);
			move = false;
		}
	}
	if (abs(yDist) > 1 && move) {
		T->y += sign(yDist);
		if (xDist != 0) T->x += sign(xDist);
	}
}

int partOne(FILE *fp) {
	
	char buffer[100];
	char direction; //Direction to move
	int num; //Number of spaces to move
	int spaces = 1; //Total number of spaces occupied, starts at 1
	
	memset(visits, false, 5000*5000);
	visits[T.x + 2500][T.y + 2500] = true;
	
	
	while (fgets(buffer, 99, fp) != NULL) {
		sscanf(buffer, "%c %d", &direction, &num);
		
		for (int i = 0; i < num; i++) {
			switch (direction) { //Move H
				case 'R':
					H.x++;
					respond(&H, &T);
					break;
				case 'L':
					H.x--;
					respond(&H, &T);
					break;
				case 'U':
					H.y--;
					respond(&H, &T);
					break;
				case 'D':
					H.y++;
					respond(&H, &T);
					break;
			}
			
			if (!visits[T.x + 2500][T.y + 2500]) {
				spaces++;
				visits[T.x + 2500][T.y + 2500] = true;
			}
		}
		
	}
	
	return spaces;
}


int partTwo(FILE* fp) {
	
	char buffer[100];
	char direction; //Direction to move
	int num; //Number of spaces to move
	int spaces = 1; //Total number of spaces occupied, starts at 1
	
	memset(visits, false, 5000*5000); //Memset yo
	visits[tails[8].x + 2500][tails[8].y + 2500] = true;
	
	while (fgets(buffer, 99, fp) != NULL) {
		sscanf(buffer, "%c %d", &direction, &num);
		
		for (int i = 0; i < num; i++) {
			switch (direction) { //Move H
				case 'R':
					H.x++;
					for (int j = 0; j < 9; j++) {
						if (j == 0) respond(&H, &tails[j]);
						else respond(&tails[j-1], &tails[j]);
					}
					break;
				case 'L':
					H.x--;
					for (int j = 0; j < 9; j++) {
						if (j == 0) respond(&H, &tails[j]);
						else respond(&tails[j-1], &tails[j]);
					}
					break;
				case 'U':
					H.y--;
					for (int j = 0; j < 9; j++) {
						if (j == 0) respond(&H, &tails[j]);
						else respond(&tails[j-1], &tails[j]);
					}
					break;
				case 'D':
					H.y++;
					for (int j = 0; j < 9; j++) {
						if (j == 0) respond(&H, &tails[j]);
						else respond(&tails[j-1], &tails[j]);
					}
					break;
			}
			
			if (!visits[tails[8].x + 2500][tails[8].y + 2500]) {
				spaces++;
				visits[tails[8].x + 2500][tails[8].y + 2500] = true;
			}
		}
		
	}
	
	return spaces;
	
}
