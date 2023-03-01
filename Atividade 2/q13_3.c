#include "tree.h"

int folhas(Arv a) {
    if (a == NULL) {
        return 0;
    } else {
        int esq = folhas(a -> sae);
        int dir = folhas(a -> sad);

        if (a -> sae == NULL && a -> sad == NULL) {
            return 1 + esq + dir;
        } else {
            return 0 + esq + dir;
        }
    }
}

int main() {
  Arv e = cria('E', NULL, NULL);
  Arv d = cria('D', NULL, NULL);
  Arv c = cria('C', e, NULL);
  Arv b = cria('B', NULL, d);
  Arv a = cria('A', b, c);

  printf("%d", folhas(a));
  destroi(&a);

  return 0;
}