// Binary Search Tree ADT Tester ... COMP9024 20T2

#include <stdlib.h>
#include <stdio.h>
#include "BST.h"

#define MAX_STR_LEN 20

void help();

int main(void) {
   Tree mytree = newTree();

   bool noShow = false;
   char line[MAX_STR_LEN];
   printf("\n> ");
   while (fgets(line,MAX_STR_LEN,stdin) != NULL) {
      int value = atoi(&line[1]);

      switch (line[0]) {
      case 'n':	 
         freeTree(mytree);
	 mytree = newTree();
         break;

      case 'i':
         mytree = TreeInsert(mytree, value);
         printf("继续输入节点，Q结束\n");
         while(scanf("%d",&value) == 1){
            printf("继续输入节点，Q结束\n");
            mytree = TreeInsert(mytree, value);

         }
         break;

      case 'h':
         help();
         break;

      case 'r':
         mytree = rebalance(mytree);
         break;

      case 'p':
         mytree = partition(mytree,value);
         break;
	 
      case 'I':
         mytree = insertAtRoot(mytree, value);
         break;
	 
      case 'R':
         mytree = insertRandom(mytree, value);
         break;
	 
      case 'A':
         mytree = insertAVL(mytree, value);
         break;
	 
      case 'z':
         mytree = insertSplay(mytree, value);
         break;
	 
      case 'd':
         mytree = TreeDelete(mytree, value);
         break;
	 
      case 's':
         if (TreeSearch(mytree, value))
            printf("Found!\n");
         else
            printf("Not found\n");
         noShow = true;
	 break;
	
      case 'b':
         mytree = rebalance(mytree);
         break;
	 
      case 'q':
	 printf("Bye.\n");
	 freeTree(mytree);
         return 0;
	 
      default:
         // help();
         printf("继续输入其他命令\n");
         noShow = true;
      }
      
      if (noShow) {
	 noShow = false;
	 printf("\n> ");
      } else {
	 printf("New Tree:");
	 printf("  #nodes = %d,  ", TreeNumNodes(mytree));
	 printf("  height = %d\n", TreeHeight(mytree));
	 if (TreeHeight(mytree) < 8)
	    showTree(mytree);
	 else
	    printf("New Tree is too deep to display nicely\n");
	 printf("\n> ");
      }
   }

   freeTree(mytree);
   return 0;
}

void help() {
   printf("Commands:\n");
   printf("n = make a new tree\n");
   printf("i N = 插入 N into tree\n");
   printf("I N = 插入 N into tree at root\n");
   printf("R N = 插入 N at random\n");
   printf("A N = 插入 N into -AVL- tree\n");
   printf("z N = 插入 N into -Splay- tree\n");
   printf("d N = 删除 N from tree\n");
   printf("s N = 遍历 for N in tree\n");
   printf("r rebalance\n");

   printf("b = rebalance tree\n");
   printf("p = partition\n");
   printf("q = quit\n");
}