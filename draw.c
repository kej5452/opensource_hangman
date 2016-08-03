#include "draw.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHANCE 7

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
	printf("your answer : %s\t\tchance : %d\n", answer_word, MAX_CHANCE - chance);
	printf("choose the character you want : ");
}

void drawintro() {
	system("clear");
	printf("-------------------------------------------\n");
	printf("		HANGMAN					\n");
	printf("-------------------------------------------\n");
	printf("	choose topic (insert number)\n");
	printf("	1.fruit 2.animal 3.food 4.quit\n");
}

