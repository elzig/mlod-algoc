# Description du projet
Ce jeu est basé sur le mini jeu "space invaders" de [raylib](https://www.raylib.com/games.html)

Le code est disponible [ici](https://github.com/raysan5/raylib-games/blob/master/classics/src/space_invaders.c)

Le but est d'ajouter un niveau supplémentaire, avec des ennemis qui sont capables de nous tirer dessus

# Comment compiler
Exécuter les lignes de commande suivante :

```console
~$ cd MiniProjet/
~$ cc space_invaders.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

# Comment exécuter
Après la compilation, exécuter la ligne de commande suivante :

```console
$ ./a.out
```

# Comment utiliser le projet
Le but du jeu est de déplacer le joueur de haut en bas de l'écran (flèche du haut et flèche du bas), afin qu'il évite les ennemis.

En appuyant sur la touche espace, il a la capacité de leur tirer dessus pour les détruire.
A partir d'un certain nombre d'ennemis détruits, le jeu passe à la vague suivante avec encore plus d'ennemis (4 vagues).

A la quatrième vague, il y a également des ennemis capables de nous tirer dessus.

# Vidéo de démo
