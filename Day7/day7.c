#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct DIR {
	int fileSizes; //Size of the files in the directory, not recursively in subdirectories
	char *name;
	
	struct DIR *firstChild;
	struct DIR *parent;
	struct DIR *nextSibling;
	
	
};

typedef struct DIR DIR;

void loadData(FILE*);
DIR *searchRecursive(DIR*, char*);
DIR *search(DIR*, char*);
DIR *newDir(char*);
void addChild(DIR*, DIR*);
int recursiveSize(DIR*);
int partOne(DIR*);
int partTwo(DIR*, int);

struct DIR *root;

int totalSize;

int main(int argc, char *argv[]) {
	
	root = newDir("/");
	
	char *filename = argv[1];
	FILE *fp = fopen(filename, "r");
	loadData(fp);
	fclose(fp);
	
	totalSize = recursiveSize(root);
	
	printf("PART ONE: %d\n", partOne(root));
	printf("PART TWO: %d\n", partTwo(root, totalSize));
	
}

int partOne(DIR *node) {
	int size = 0;
	
	if (node != NULL) {
		int nodeSize = recursiveSize(node);
		if (nodeSize <= 100000) size += nodeSize;
		
		DIR *child = node->firstChild;
		while (child != NULL) {
			size += partOne(child);
			child = child->nextSibling;
		
		}
		
		return size;
	}
}

int partTwo(DIR *node, int prevSize) {
	int size = totalSize;
	
	if (node != NULL) {
		int nodeSize = recursiveSize(node);
		if (70000000 - totalSize + nodeSize >= 30000000 && nodeSize <= prevSize) size = nodeSize;
		else size = prevSize;
		
		DIR *child = node->firstChild;
		while (child != NULL) {
			size = partTwo(child, size);
			child = child->nextSibling;
		
		}
		
		return size;
	}
}


DIR *newDir(char *name) {
	DIR *new = malloc(sizeof(DIR));
	new->name = malloc(strlen(name) + 1);
	strcpy(new->name, name);
	
	new->fileSizes = 0;
	
	new->firstChild = NULL;
	new->parent = NULL;
	new->nextSibling = NULL;
	
	return new;
}

DIR *searchRecursive(DIR *node, char *name) { //Searches directory recursively for another directory
	if (node != NULL) {
		if (strcmp(node->name, name) == 0) return node;
		else {
			DIR *child = node->firstChild;
			while (child != NULL) {
				DIR *test = search(child, name);
				if (test != NULL) return test;
				child = child->nextSibling;
			}
			
		}
	}
	else {
		return NULL;
	}
}

DIR *search(DIR *node, char *name) {
	DIR *child = node->firstChild;
	while (child != NULL) {
		if (strcmp(child->name, name) == 0) return child;
		child = child->nextSibling;
	}
	
	return NULL;
}

int recursiveSize(DIR *node) {
	if (node->firstChild == NULL) return node->fileSizes;
	
	DIR *child = node->firstChild;
	int size = 0;
	while (child != NULL) {
		size += recursiveSize(child);
		child = child->nextSibling;
		
	}
	
	return size + node->fileSizes;
}

void addChild(DIR *parent, DIR *child) {
	child->parent = parent;
	
	if (parent->firstChild != NULL) {
		DIR *pt = parent->firstChild;
		while (pt->nextSibling != NULL) {
			pt = pt->nextSibling;
		}
		pt->nextSibling = child;
	}
	else {
		parent->firstChild = child;
	}
}

void loadData(FILE *fp) {
	
	char buffer[1000];
	DIR *currentDir = root;
	
	while(fgets(buffer, 999, fp) != NULL) {
		if (buffer[0] == '$') {
			if (buffer[2] == 'c' && buffer[3] == 'd') { //cd command
				char dirName[100];
				memset(dirName, 0, 100);
				sscanf(buffer, "$ cd %s", dirName);
				if (strcmp(dirName, "..") == 0 && currentDir->parent != NULL) {
					currentDir = currentDir->parent;
					continue;
				}
				else if ((strcmp(dirName, "/") == 0)) {
					currentDir = root;
					continue;
				}
				DIR *parent = currentDir;
				currentDir = search(parent, dirName);
				
				if (currentDir == NULL && strcmp(dirName, "/") != 0) {
					currentDir = newDir(dirName);
					addChild(parent, currentDir);
				}
			}
			else if (buffer[2] == 'l' && buffer[3] == 's') { //ls
				
				while (fgets(buffer, 999, fp) != NULL && buffer[0] != '$') {
					if (buffer[0] == 'd') {
						char dirName[100];
						memset(dirName, 0, 100);
						sscanf(buffer, "dir %s", dirName);
						
						DIR *test = search(currentDir, dirName);
						if (test == NULL) {
							addChild(currentDir, newDir(dirName));
						}
					}
					else {
						int size;
						sscanf(buffer, "%d %*s", &size);
						currentDir->fileSizes += size;
					}
				}
				fseek(fp, -strlen(buffer), SEEK_CUR);
			}
		}
	}
}
