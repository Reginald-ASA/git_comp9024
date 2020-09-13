#include "RBTree.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
   Tree mytree = newTree();

   // int i = 1;
   // while (i < argc)
   //    mytree = TreeInsert(mytree, atoi(argv[i++]));

   mytree = TreeInsert(mytree, 6);
   mytree = TreeInsert(mytree, 7);


   showTree(mytree);

   freeTree(mytree);
   return 0;
}