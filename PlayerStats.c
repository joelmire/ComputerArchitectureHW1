#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file_pointer;

struct player{
	char name[64];
	float doc;
	struct player *next;
};

void sort_list(struct player* list);

int main(int argc, char *argv[]) {
	file_pointer = fopen(argv[1], "r");

	int empty_file = fgetc(file_pointer);
	if (empty_file == EOF) {
		printf("PLAYER FILE IS EMPTY\n");
		return EXIT_SUCCESS;
	} else {
    ungetc(empty_file, file_pointer);
	}

    struct player *head;
	head = (struct player*)malloc(sizeof(struct player));
	float points, rebounds, minutes;
	fscanf(file_pointer, "%s%f%f%f", &head->name, &points, &rebounds, &minutes);
	if (minutes == 0) {
		head->doc = 0;
	} else {
		head->doc = (points + rebounds) / minutes;
	}
	head->next = NULL;

    int guard = 1;
	while (guard == 1) {
		char check[64];
		fscanf(file_pointer, "%s", &check);
		if (strcmp(check, "DONE") == 0) {
			break;
		}
		struct player *previous;
		previous = (struct player*)malloc(sizeof(struct player));
		strcpy(previous->name, check);
		float points, rebounds, minutes;
		fscanf(file_pointer, "%f%f%f", &points, &rebounds, &minutes);
		if (minutes == 0) {
			previous->doc = 0;
		} else {
			previous->doc = (points + rebounds) / minutes;
	}
	    previous->next = head;
	    head = previous;
	}
	fclose(file_pointer);

	sort_list(head);

	struct player *current;
	current = head;
	while (current != NULL) {
		printf("%s %f\n", current->name, current->doc);
		struct player *temp = current->next;
		free(current);
		current = temp;
	}
	return EXIT_SUCCESS;
}

void sort_list(struct player* list) {
    struct player* p1 = list;
    while(p1->next != NULL) {
        struct player* p2 = p1->next;
  		while (p2 != NULL) {
  			if (p1->doc == p2->doc) {
        		if (strcmp(p1->name, p2->name) > 0) {
        			//swap names
        			char name_swapper[64];
        			strcpy(name_swapper, p1->name);
        			strcpy(p1->name, p2->name);
        			strcpy(p2->name, name_swapper);
        			//swap docs
        			float doc_swapper;
        			doc_swapper = p1->doc;
        			p1->doc = p2->doc;
        			p2->doc = doc_swapper;
        		}
        	}
        	if (p1->doc < p2->doc) {
        		//swap names
        		char name_swapper[64];
        		strcpy(name_swapper, p1->name);
        		strcpy(p1->name, p2->name);
        		strcpy(p2->name, name_swapper);
             	//swap docs
        		float doc_swapper;
        		doc_swapper = p1->doc;
        		p1->doc = p2->doc;
        		p2->doc = doc_swapper;
        	}
        	p2 = p2->next;
    	}
    	p1 = p1->next;
    }
}