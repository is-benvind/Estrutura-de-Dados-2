#include <stdio.h>
#include <stdlib.h>

typedef struct arv *Arv;

struct arv {
  char item;
  struct arv *sae;
  struct arv *sad;
};

Arv cria(char a, Arv sae, Arv sad) {
  Arv p = (Arv)malloc(sizeof(struct arv));
  p -> item = a;
  p -> sae = sae;
  p -> sad = sad;
  return p;
}

void destroi(Arv *a) {
  if (*a != NULL) {
    destroi(&((*a) -> sae));
    destroi(&((*a) -> sad));
    free(*a);
    *a = NULL;
  }
}