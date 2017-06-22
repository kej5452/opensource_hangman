#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "choose_problem.h"

char* choose_problem(int topic) {
	int max_length = 15;
	char* word = malloc((max_length+2)*sizeof(char));
	int rand_counter = 0;
	int i;
	int line = 0;
	FILE *problem;
	switch (topic) {
	case 1:
		problem = fopen("fruit.txt", "r");
		line = getTotalLine(problem);		
		rand_counter = rand() % line; 
		rewind(problem);
		for (i = 0;i < rand_counter;i++) {
			fgets(word, max_length, problem);
		}
		word[strlen(word)-1] = '\0';
		fclose(problem);
		break;
	case 2:
		problem = fopen("animal.txt", "r");
		line = getTotalLine(problem);
		rand_counter = rand() % line; 
		rewind(problem);
		for (i = 0;i < rand_counter;i++) {
			fgets(word, max_length, problem);
		}
		word[strlen(word) - 1] = '\0';
		fclose(problem);
		break;
	case 3:
		problem = fopen("food.txt", "r");
		line = getTotalLine(problem);
		rand_counter = rand() % line; 
		rewind(problem);
		for (i = 0;i < rand_counter;i++) {
			fgets(word, max_length, problem);
		}
		word[strlen(word) - 2] = '\0';
		fclose(problem);
		break;
	default:
		break;
	}
	return word;
}

int getTotalLine(FILE* fp) {
	int line = 0;
	char c;
	while ((c = fgetc(fp)) != EOF)
		if (c == '\n') line++;
	return line+1;
}
