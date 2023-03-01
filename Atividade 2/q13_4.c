#include "tree.h"

int altura(Arv a) {
    if (a == NULL) {
        return 0;
    } else {
        int esq = altura(a -> sae);
        int dir = altura(a -> sad);

        if (esq > dir) {
            return 1 + esq;
        } else {
            return 1 + dir;
        }
    }
}

int main() {
  Arv e = cria('E', NULL, NULL);
  Arv d = cria('D', NULL, NULL);
  Arv c = cria('C', e, NULL);
  Arv b = cria('B', NULL, d);
  Arv a = cria('A', b, c);

  printf("%d", altura(b));
  destroi(&a);
  
  return 0;
}