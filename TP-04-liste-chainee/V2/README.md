# Compiler
```shell
user@pc:~$ gcc -W -Wall linkedList.c linkedListOfMusic.c mySpitofy.c -o mySpitofy
```

# Exécuter
```shell
user@pc:~$ ./mySpitofy > output.csv
```

# Vérifier les différences
```shell
user@pc:~$ diff -s output.csv music.csv
```
Les fichiers ne sont pas identiques car le fichier output.csv créé par le programme a une ligne vide en plus à la fin du programme que je n'ai pas réussi à retirer.

# Pour trier la liste
Il faut décommenter la ligne 32 :
```
32 triABulles(listeMusique);
```