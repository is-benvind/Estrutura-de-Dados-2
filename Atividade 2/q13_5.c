#include "tree.h"

int tem(Arv a, char x) {
    if (a == NULL) {
        return 0;
    } else {
        int esq = tem(a -> sae, x);
        int dir = tem(a -> sad, x);

        if (a -> item == x) {
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

  printf("%d", tem(a, 'C'));
  destroi(&a);
  
  return 0;
}