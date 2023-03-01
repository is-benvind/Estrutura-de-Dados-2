#include "tree.h"

int nos(Arv a) {
  if (a == NULL) {
    return 0;
  } else {
    int esq = nos(a -> sae);
    int dir = nos(a -> sad);

    return 1 + esq + dir;
  }
}

int main() {
  Arv e = cria('E', NULL, NULL);
  Arv d = cria('D', NULL, NULL);
  Arv c = cria('C', e, NULL);
  Arv b = cria('B', NULL, d);
  Arv a = cria('A', b, c);

  printf("%d", nos(a));
  destroi(&a);
  
  return 0;
}