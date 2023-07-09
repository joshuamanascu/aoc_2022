#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Monkey {
	long long int *items;
	int numItems;
	char opType; //*, +
	int opNum; //Amount to add or multiply, 0 indicates itself
	int test; //Divisible by this
	
	int throws[2]; //First if true, second if false
	
	int inspections; //Number of inspections made
};

typedef struct Monkey Monkey;

Monkey *monkeys; //Array of Monkeys
int numMonkeys;

// FUNCTIONS

void loadData(FILE*);
int partOne();
long long int partTwo();

int main(int argc, char *argv[]) {
	char *filename = argv[1];
	FILE *fp = fopen(filename, "r");
	
	loadData(fp);
	
	printf("PART ONE: %d\n", partOne());
	
	fseek(fp, 0, SEEK_SET);
	free(monkeys);
	loadData(fp);
	
	
	
	printf("PART TWO: %lld\n", partTwo());
	
}

int partOne() {
	
	
	for (int round = 0; round < 20; round++) { //20 rounds
	
		for (int i = 0; i < numMonkeys; i++) { //Go through each monkey
			for (int j = 0; j < monkeys[i].numItems; j++) { //Go through each item
				
				monkeys[i].inspections++;
				
				//Check operation type
				if (monkeys[i].opType == '*') {
					if (monkeys[i].opNum != 0) monkeys[i].items[0] *= monkeys[i].opNum;
					else monkeys[i].items[0] *= monkeys[i].items[0];
				}
				else if (monkeys[i].opType == '+') {
					if (monkeys[i].opNum != 0) monkeys[i].items[0] += monkeys[i].opNum;
					else monkeys[i].items[0] += monkeys[i].items[0];
				}
				
				monkeys[i].items[0] /= 3;
				
				if (monkeys[i].items[0] % monkeys[i].test == 0) {
					monkeys[monkeys[i].throws[0]].numItems++;
					monkeys[monkeys[i].throws[0]].items = reallocarray(monkeys[monkeys[i].throws[0]].items, monkeys[monkeys[i].throws[0]].numItems, sizeof(long long int));
					monkeys[monkeys[i].throws[0]].items[monkeys[monkeys[i].throws[0]].numItems - 1] = monkeys[i].items[0];
					monkeys[i].items++;
				}
				else {
					monkeys[monkeys[i].throws[1]].numItems++;
					monkeys[monkeys[i].throws[1]].items = reallocarray(monkeys[monkeys[i].throws[1]].items, monkeys[monkeys[i].throws[1]].numItems, sizeof(long long int));
					monkeys[monkeys[i].throws[1]].items[monkeys[monkeys[i].throws[1]].numItems - 1] = monkeys[i].items[0];
					monkeys[i].items++;
				}
			}
			
			monkeys[i].numItems = 0;
			monkeys[i].items = NULL;
		}
	}
	
	//Determine monkeys with the most inspections
	int twoHighest[2] = {monkeys[0].inspections, monkeys[1].inspections};
	
	for (int i = 2; i < numMonkeys; i++) {
		if(monkeys[i].inspections > twoHighest[0] && monkeys[i].inspections > twoHighest[1]) {
			if (twoHighest[0] > twoHighest[1]) twoHighest[1] = monkeys[i].inspections;
			else twoHighest[0] = monkeys[i].inspections;
		}
		else if (monkeys[i].inspections > twoHighest[0]) twoHighest[0] = monkeys[i].inspections;
		else if (monkeys[i].inspections > twoHighest[1]) twoHighest[1] = monkeys[i].inspections; 
	}
	
	return twoHighest[0] * twoHighest[1];
	
}

long long int partTwo() {
	
	int mod_forall = 1;
	
	for (int i = 0; i < numMonkeys; i++) mod_forall *= monkeys[i].test; //Reducing worry level while keeping the tests consistent
	
	for (int round = 0; round < 10000; round++) { //10000 rounds
	
		for (int i = 0; i < numMonkeys; i++) { //Go through each monkey
			for (int j = 0; j < monkeys[i].numItems; j++) { //Go through each item
				
				monkeys[i].inspections++;
				
				//Check operation type
				if (monkeys[i].opType == '*') {
					if (monkeys[i].opNum != 0) monkeys[i].items[0] *= monkeys[i].opNum;
					else monkeys[i].items[0] *= monkeys[i].items[0];
				}
				else if (monkeys[i].opType == '+') {
					if (monkeys[i].opNum != 0) monkeys[i].items[0] += monkeys[i].opNum;
					else monkeys[i].items[0] += monkeys[i].items[0];
				}
				
				monkeys[i].items[0] = monkeys[i].items[0] % mod_forall;
				
				if (monkeys[i].items[0] % monkeys[i].test == 0) {
					monkeys[monkeys[i].throws[0]].numItems++;
					monkeys[monkeys[i].throws[0]].items = reallocarray(monkeys[monkeys[i].throws[0]].items, monkeys[monkeys[i].throws[0]].numItems, sizeof(long long int));
					monkeys[monkeys[i].throws[0]].items[monkeys[monkeys[i].throws[0]].numItems - 1] = monkeys[i].items[0];
					monkeys[i].items++;
				}
				else {
					monkeys[monkeys[i].throws[1]].numItems++;
					monkeys[monkeys[i].throws[1]].items = reallocarray(monkeys[monkeys[i].throws[1]].items, monkeys[monkeys[i].throws[1]].numItems, sizeof(long long int));
					monkeys[monkeys[i].throws[1]].items[monkeys[monkeys[i].throws[1]].numItems - 1] = monkeys[i].items[0];
					monkeys[i].items++;
				}
			}
			
			monkeys[i].numItems = 0;
			monkeys[i].items = NULL;
		}
	}
	
	//Determine monkeys with the most inspections
	long long int twoHighest[2] = {monkeys[0].inspections, monkeys[1].inspections};
	
	for (int i = 2; i < numMonkeys; i++) {
		if(monkeys[i].inspections > twoHighest[0] && monkeys[i].inspections > twoHighest[1]) {
			if (twoHighest[0] > twoHighest[1]) twoHighest[1] = monkeys[i].inspections;
			else twoHighest[0] = monkeys[i].inspections;
		}
		else if (monkeys[i].inspections > twoHighest[0]) twoHighest[0] = monkeys[i].inspections;
		else if (monkeys[i].inspections > twoHighest[1]) twoHighest[1] = monkeys[i].inspections; 
	}
	
	long long int result = twoHighest[0] * twoHighest[1];
	
	return result;
	
}

void loadData(FILE *fp) {
	numMonkeys = 0;
	char buffer[1000];
	
	while (fgets(buffer, 999, fp) != NULL) { //Number of Monkeys
		
		if (strncmp(buffer, "Monkey ", 7) == 0) {
			sscanf(buffer, "Monkey %d:\n", &numMonkeys);
			numMonkeys++;
		}
	}
	
	monkeys = calloc(numMonkeys, sizeof(Monkey));
	fseek(fp, 0, SEEK_SET);
	
	
	for (int i = 0; i < numMonkeys; i++) { //iterate through the monkeys
		
		monkeys[i].inspections = 0;
		
		fgets(buffer, 999, fp); //Monkey: %d
		fgets(buffer, 999, fp); //Starting items
		char *test = buffer; //Finding the number of items
		while (*test != '\0') {
				if (*test == ',') monkeys[i].numItems++;
				test++;
		}
		monkeys[i].numItems++;
		
		char *tok = strtok(buffer, ":,");
		tok = strtok(NULL, ":,");
		
		if (*tok == '\n') monkeys[i].numItems = 0; //Correct for the case of 0 starting items
		
		monkeys[i].items = calloc(monkeys[i].numItems, sizeof(long long int));
		
		for (int j = 0; j < monkeys[i].numItems; j++) { //Adding starting items to the list
			monkeys[i].items[j] = atoi(tok);
			tok = strtok(NULL, ":,");
		}
		
		fgets(buffer, 999, fp); //Operation
		if (sscanf(buffer, "  Operation: new = old %c %d", &monkeys[i].opType, &monkeys[i].opNum) == EOF) monkeys[i].opNum = 0;
		
		fgets(buffer, 999, fp); //Test
		sscanf(buffer, "  Test: divisible by %d", &monkeys[i].test);
		
		fgets(buffer, 999, fp); //if true
		sscanf(buffer, "    If true: throw to monkey %d", &monkeys[i].throws[0]);
		fgets(buffer, 999, fp); //if false
		sscanf(buffer, "    If false: throw to monkey %d", &monkeys[i].throws[1]);
		
		fgets(buffer, 999, fp); //Empty line
	}
	
}
