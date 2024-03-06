Multiplication de matrices en C
Ce programme en C effectue la multiplication de deux matrices carrées lues à partir de 
fichiers texte (matriceA.txt et matriceB.txt) et écrit le résultat dans un autre fichier texte (resultat.txt).

Compilation : 
Assurez-vous d'avoir un compilateur C installé sur votre système. Vous pouvez compiler le programme en utilisant une commande comme celle-ci :
 gcc -Wall main_q1.c question_1.c -o exec

Exécutez le programme compilé avec cette commande : 
./exec matriceA.txt matriceB.txt resultat.txt

Assurez-vous d'avoir les fichiers matriceA.txt et matriceB.txt dans le même répertoire que le programme exécutable.

Contenu des fichiers d'entrée:
matriceA.txt: La première ligne contient la taille n des matrices, suivie des éléments de la matrice A.
matriceB.txt: La première ligne contient également la taille n des matrices, suivie des éléments de la matrice B.

Contenu du fichier de sortie:
resultat.txt: La première ligne contient la taille n du résultat, suivie des éléments de la matrice résultante de la multiplication.

Remarque:Temps d'execution est affiché sur le terminal