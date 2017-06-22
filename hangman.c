#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "draw.h"
#include "choose_problem.h"

#define MAX_CHANCE 7
#define MAX_STR_LEN 4000

void play_game(char* word);
bool compare_answer(char* word, char answer);

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
		if (used_chance > MAX_CHANCE) {
			printf("You are wrong! The answer is %s.\n", word);
			printf("Will you continue to solve the quiz? : 1.yes  2.no\n");
			scanf("%d", &stopswitch);
			break;
		}
		if (used_chance < MAX_CHANCE && success == 1) {
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
	bool find = 0;
	for (i = 0;i < strlen(word);i++) {
		if (word[i] == answer) {
			find = 1;
			break;
		}	
	}
	return find;
}




