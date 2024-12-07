Push_swap :

Premier gros projet de 42. On a deux piles A et B, l'objectif est de trier toute une pile en respectant des instructions précises. Pour cela, on doit utiliser un algorithme de tri efficace (afin d'avoir une meilleure note).

Personnellement j'utilise un chunk_sort puis un turk_sort afin d'optimiser le nombre de coups, avec cet algo j'atteins une score entre 3894 et ~4500, ce qui permet d'obtenir la note maximale.

Les algos :
- Chunk sort permet de découper la pile en chunk afin de faire un pré-tri dans B. Pour la suite je garde 3 valeurs dans A afin d'effectuer un tri simple dessus, le reste est dans B. 

- Turk sort va calculer le minimum de coups qu'il faut faire pour placer un élément au bon endroit, afin de trouver le meilleur élément, on effectue ce calcul sur toute la pile. Une fois qu'on a trouvé le meilleur, on l'envoie dans la pile A et le tour est joué !

Bonus part:
  Faire un programme nommé "checker" qui vérifie si les opérations qu'on donne permettent de trier la pile. Pour cela je prends les informations données par mon "push_swap" et j'effectue juste les opérations sur mes piles, pour finir, je regarde si la pile A est bien triée et voilà !

Le rendu final :

- Pour 100 nombres :
https://github.com/user-attachments/assets/7419df5d-8629-4369-baaf-c7d6f758ecbd

- Pour 500 nombres :
https://github.com/user-attachments/assets/e0014914-84b4-4ff4-991b-bc8e3891c710
