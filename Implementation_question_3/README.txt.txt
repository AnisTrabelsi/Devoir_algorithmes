Inversion d'une matrice 2^k * 2^k en utilisant la multiplication de strassen

Compilation : 
Assurez-vous d'avoir un compilateur C installé sur votre système. Vous pouvez compiler le programme en utilisant une commande comme celle-ci :
gcc -Wall main_q3.c question_3.c -o exec

Exécutez le programme compilé avec cette commande : 
./exec matriceA.txt matriceAinv.txt

matriceA.txt contient la matrice a inverser
matriceAinv.txt contient la matrice inverse

Remarque: il ya plusieurs exemples de matrices de taille 2^k*2^k (matriceB.txt ou matriceC.txt) qui peuvent etre passées en argument au lieu de la matriceA.txt.

===> Complexite: O(n^log2(7))

A noter : Les matrices A^TA et inverse A^TA et A^-1 sont affichées sur le terminal.Ainsi que le temps d'execution.