Push_swap :

Premier gros projet de 42.On a deux piles A et B, l'objectif est de trier tout une pile en respectant des instructions precises. Pour cela on doit utiliser un algorithme de tri efficace (afin d'avoir une meilleur note).

Personnelement j'utilise un chunk_sort puis un turk_sort afin d'optimiser le nombre de coup, avec cet algo j'atteins un plage de 3894 a ~4500 ce qui permet d'obtenir la note max.

Les algos :
- chunk sort permt de decouper la pile en chunk afin de commencer le tri.

- le turk sort va chercher le minimum de coup que j'ai a faire pour placer l'element au bon endroit.

Bonus part:
  Faire un "checker" qui verifie si les operations qu'on donne permet de trier la pile. Pour cela je prends les informations donner par mon "push_swap" et j'effectue juste les operations sur mes piles, pour finir je regarde si la est bien trier et voila !

  
