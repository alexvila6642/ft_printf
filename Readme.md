*Ce projet a été réalisé dans le cadre du cursus de l’école 42 par alvila.*

# ft_printf

## Description

Le projet **ft_printf** consiste à réimplémenter une version simplifiée de la
fonction standard du langage C `printf`.

L’objectif est de comprendre :
- le fonctionnement des fonctions variadiques (`va_list`)
- la gestion d’un format d’affichage
- l’écriture sur la sortie standard
- le calcul et le retour du nombre de caractères affichés

Cette implémentation est **autonome**, respecte la **norme 42**, et reproduit
le comportement de `printf` pour un ensemble limité de conversions.

---

## Compilation

Fournir votre propre main


Pour compiler le projet, exécutez :

```bash
make
gcc -o program main.c libftprintf.a
./program

```

## Utilisation et exemple

Voici les differentes conversion disponible :

• %c Affiche un caractère unique.

• %s Affiche une chaîne de caractères (selon la convention C).

• %p L'argument pointeur void * doit être affiché au format hexadécimal.

• %d Affiche un nombre décimal (base 10).

• %i Affiche un entier en base 10.

• %u Affiche un nombre décimal non signé (base 10).

• %x Affiche un nombre en minuscules au format hexadécimal (base 16).

• %X Affiche un nombre en majuscules au format hexadécimal (base 16).

• %% Affiche le signe pourcentage.

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s!\n", "World");
	ft_printf("Number: %d\n", 42);
	return (0);
}
```
