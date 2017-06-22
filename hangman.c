#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_Chance 7
#define MAX_STR_LEN 4000

void drawscreen(int chance, char* used_char, char* answer_word);
void drawintro();
char* choose_problem(int topic);
void play_game(char* word);
bool compare_answer(char* word, char answer);
int getTotalLine(FILE* fp);
char* my_strset(char* word,char padding);
char*  trim(char *s); 
char* ltrim(char *s); 
char* rtrim(char* s); 

static int stopswitch = 0;
static int score = 0; 

int main() {
	char* word;
	int topic = 0;

		drawintro();
		scanf("%d", &topic);
		if (topic == 4) {
			printf("Quit\n");
			return 0;
		}
		while (1) {			
			word = choose_problem(topic);
			//printf("%s", word);
			play_game(word);
			if (stopswitch == 2) {
				printf("Game over! your score is %d.\n", score);
				stopswitch = 0;
				score = 0;					
				break;
			}
		}
		return 0;
}

void play_game(char* word) {
	char remained_char[27] = "abcdefghijklmnopqrstuvwxyz";
	remained_char[26] = '\0';
	word[strlen(word)-1] = '\0';
	char* answer_word = malloc((strlen(word))*sizeof(char));
	memset(answer_word, ' ', strlen(word));
	answer_word[strlen(word)] = '\0';
	
	int index_used = 0;
	int used_chance = 0;
	bool success = 0;
	char answer = ' ';
	int i;
	
	while (1) {
		drawscreen(used_chance, remained_char, answer_word);
		scanf("%c", &answer);
		scanf("%c", &answer);
		if (compare_answer(word, answer) == 0) {
			used_chance++;
			remained_char[answer - 97] = ' ';
		}
		else {
			for (i = 0;i < strlen(word);i++) {
				if (word[i] == answer) answer_word[i] = answer;
				remained_char[answer - 97] = ' ';
			}
		}
		if (!strcmp(answer_word, word)) success = 1;
		drawscreen(used_chance, remained_char, answer_word);
		if (used_chance > MAX_Chance) {
			printf("You are wrong! The answer is %s.\n", word);
			printf("Will you continue to solve the quiz? : 1.yes  2.no\n");
			scanf("%d", &stopswitch);
			break;
		}
		if (used_chance < MAX_Chance && success == 1) {
			score += 10;
			printf("\n");
			printf("You are right! The answer is %s.\n", word);
			printf("Your score is %d.\n",score);
			printf("Will you continue to solve the quiz? : 1.yes  2.no\n");

			scanf("%d", &stopswitch);
			free(answer_word);
			free(word);
			break;
		}
	}

}

bool compare_answer(char* word, char answer) {
	int i;
	int chance;
	bool find = 0;
	for (i = 0;i < strlen(word);i++) {
		if (word[i] == answer) {
			find = 1;
			break;
		}	
	}
	return find;
}

void drawscreen(int chance, char* remained_char, char* answer_word) {
	system("clear");
	switch (chance) {
	case 0:
		printf("\n┌───┐\n│\n│\n│\n│\n└──────\n");
		break;
        case 1:
		printf("\n┌───┐\n│　○\n│\n│\n│\n└──────\n");
		break;
        case 2:
		printf("\n┌───┐\n│　○\n│　 |\n│\n│\n└──────\n");
		break;
        case 3:
		printf("\n┌───┐\n│　○\n│　/|\n│\n│\n└──────\n");
        	break;
        case 4:
		printf("\n┌───┐\n│　○\n│　/|＼\n│　\n│\n└──────\n");
        	break;
        case 5:
		printf("\n┌───┐\n│　○\n│　/|＼\n│　/\n│\n└──────\n");
        	break;
        case 6:
		printf("\n┌───┐\n│　○\n│　/|＼\n│　/＼\n│\n└──────\n");
        	break;
        case 7:
		printf("\n┌───┐\n│　○\n│　 X\n│　/|＼\n│　/＼\n└──────\n");
        	break;
	default:
		break;
	}
	printf("The characters that you can use : %s\n", remained_char);
	printf("your answer : %s\t\tchance : %d\n", answer_word, MAX_Chance - chance);
	printf("choose the character you want : ");
}

void drawintro() {
	printf("-------------------------------------------\n");
	printf("		HANGMAN					\n");
	printf("-------------------------------------------\n");
	printf("	choose topic (insert number)\n");
	printf("	1.fruit 2.animal 3.food 4.quit\n");
}

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


