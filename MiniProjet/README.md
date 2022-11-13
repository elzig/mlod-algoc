# Description du projet
Ce jeu est basé sur le mini jeu "space invaders" de [raylib](https://www.raylib.com/games.html)

Le code est disponible [ici](https://github.com/raysan5/raylib-games/blob/master/classics/src/space_invaders.c)

Le but est d'ajouter une vague d'ennemis supplémentaire.

Dès la fin de la troisième vague, le canon du vaisseau tombe en panne...

Le seul moyen de continuer à gagner des points est donc de se faufiler entre les ennemis, afin de collecter les bonus verts qui permettent de faire augmenter le compteur de points.

Cependant, une cinquième vague encore plus difficile vient corser la victoire...

Il y a également des malus dans le jeu à partir de la troisième vague, à vous de découvrir leurs effets...

# Comment compiler
Exécuter les lignes de commande suivante :

```console
~$ cd MiniProjet/
~$ cc space_invaders.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

# Comment exécuter
Après la compilation, exécuter la ligne de commande suivante :

```console
~$ ./a.out
```

# Comment utiliser le projet
Le but du jeu est de déplacer le vaisseau de haut en bas de l'écran (flèche du haut et flèche du bas), afin qu'il évite les ennemis.

Le vaisseau peut également se déplacer à gauche et à droite avec les flèches correspondantes.

En appuyant sur la touche espace, il a la capacité de leur tirer dessus pour les détruire.
A partir d'un certain nombre d'ennemis détruits, le jeu passe à la vague suivante avec encore plus d'ennemis.

A la quatrième vague, il n'est plus possible de tirer, seulement d'absorber des bonus pour faire grimper le score.

# Détails de l'implémentation
J'ai rajouté 2 nouvelles struct, une struct Bonus et une Malus, en me basant sur les struct représentant les ennemis et le joueur.

J'initialise ensuite 2 tableaux contenant respectivement des Bonus et des Malus, avec leur position, leur vitesse et leur couleur.

Ils sont désactivés de base puisqu'ils ne sont pas sur l'écran dès la première vague.

Je rajoute également 2 vagues avec comme condition de passage à la suivante l'obtention d'un certain score.

Je gère ensuite les collisions de chacune des entités avec le joueur et je défini l'action à réaliser si ils se touchent.

Pour finir je dessine sur l'écran les deux entités (seulement si elles sont actives).

# Vidéo de démo
https://drive.google.com/drive/folders/1AJNvGa_KkCiL1TDWzUNQXfP1BOFGDkyL?usp=sharing