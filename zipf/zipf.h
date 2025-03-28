#ifndef ZIPF_H
#define ZIPF_H


#define MAX_WORD_SIZE 64
#define MAX_WORD_COUNT (64 * 64 * 64) // idk


struct word_node {
  char *word;
  int word_length;
  int occurances;
};


#endif
