#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "zipf.h"




char word_terminators[3] = {' ', '\n', '\t'};


int char_in(char ch, char *string, int string_len){
  for (int i = 0; i < string_len; i++){
    if (ch == string[i]){
      return 1;
    }
  }
  return -1;
}


int same_word(char *word_1, int word_1_len, char *word_2, int word_2_len){
  if (word_1_len != word_2_len){
    return 0;
  }

  for (int index = 0; index < word_1_len; index++){
    if (word_1[index] != word_2[index]){
      return 0;
    }
  }

  return 1;
}


int insert_word(char *word, int word_len, struct word_node *word_list, int word_list_len){
  if (word_len == 0){
    return -1;
  }


  for (int index = 0; index < word_list_len; index++){
    if (same_word(word_list[index].word, word_list[index].word_length, word, word_len)){
      word_list[index].occurances++;
      return 1;
    }


    if (word_list[index].word == NULL){
      // if it's a new word
      word_list[index].word = (char *)malloc(word_len * sizeof(char));
      memcpy(word_list[index].word, word,    word_len * sizeof(char));

      word_list[index].word_length = word_len;
      word_list[index].occurances = 1;
      return 0;
    }
  }

  printf("mm");
  exit(EXIT_FAILURE);
}


void print_word(char *word, int word_len){
  for (int index = 0; index < word_len; index++){
    printf("%c", word[index]);
  }
}




int main(){
  FILE *file = fopen("test.txt", "r");


  if (file == NULL){
    printf("failed to open file \n");
    exit(EXIT_FAILURE);
  }


  char c;

  char *word = (char *)calloc(MAX_WORD_SIZE, sizeof(char));

  struct word_node *word_list = (struct word_node *)calloc(MAX_WORD_COUNT, sizeof(struct word_node));

  int current_word_length = 0;

  int stored_words = 0;

  while ((c = fgetc(file)) != EOF){
    //check for word terminating chars
    if(char_in(c, word_terminators, 3) == 1){
      if (insert_word(word, current_word_length, word_list, MAX_WORD_COUNT) == 0){
        stored_words++;
      }

      current_word_length = 0;
      continue;
    }

    word[current_word_length] = c;
    current_word_length++;
  }


  for (int index = 0; index < stored_words; index++){
    print_word(word_list[index].word, word_list[index].word_length);
    printf(" occurances: %d\n", word_list[index].occurances);
  }


  free(word);
  free(word_list);


  return 0;
}
