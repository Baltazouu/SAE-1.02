# SAE-1.02 :Comparaison d'approches algorithmiques

### Développeurs
* Agostinho Alexandre
* Dudonné Baptiste

### Compétences
* Optimiser des applications informatiques (Compétence 2)
---

## Structure du projet
```
   .
   |-- build            # <-- répertoire temporaire créé lors de la compilation>
   |   |-- bin          # <-- répertoire des fichiers objets>
   |   |   |-- src1.o
   |   |   |-- src2.o
   |   |   `-- (...)
   |   `-- deps         # <-- répertoire des fichiers de dépendances>
   |       |-- src1.d
   |       |-- src2.d
   |       `-- (...)
   |-- compile_flags.txt    # <-- permet à Clang de connaître les flags de compilation>
   |-- config.h         # <-- header de configuration de l'application>
   |-- doc              # <-- dossier contenant la documentation générée par DOXYGEN>
   |   `-- html
   |       `-- (doxygen output)...
   |-- include          # <-- emplacement de tous les headers>
   |   |-- inc1
   |   |-- inc2
   |   |-- (...)
   |   |-- acutest.h    # <-- header des tests unitaire (voir **Crédits)>
   |   `-- (...)
   |-- sae1.02          # <-- éxécutable du programme>
   |-- sae1.02_test     # <-- éxécutable des tests du programme>
   `-- src              # <-- emplacement des fichier de code source>
       |-- main.c       # <-- fonction 'main' du programme>
       |-- test.c       # <-- tests unitaires>
       |-- fold1
       |   |-- src1.c
       |   |-- src2.c
       |   `-- (...)
       |-- fold2
       |-- fold3
       `-- (...)
```
---

## Usage
### Make commandes
> Usage: ` make [cmd] [VAR=val]`

* ` {vide} `, ` build `: Build le programme, créé son éxécutable
* ` run `: Lance le programme
* ` test `: Build les tests unitaires, créé l'éxécutable correspondant
* ` run_test `: Lance les tests unitaires
* ` doc `: Créé la documentation DOXYGEN
* ` clean `: Supprime tout les binaires et fichiers résiduels
* ` clflags `: Créé le fichier "compile_flags.txt" pour Clang
* *(` init `: Créé les dossiers de base de l'architecture du projet)*
* *(` directories `: Créé les répertoires aceuillant les binaires et fichier résiduels)*

### Test options
> Usage: ` ./sae1.02_test [-t|-v|-l|-h] [test] ` ou ` make test [TESTVER=(TRUE|FALSE)] `

* ` -t `: indique le temps d'éxécution des fonctions
* ` -v, --verbose `: verbose mode, affiche en détails les tests éfféctué
* ` -l, --list `: liste tout les tests sans les effectuer
* ` -h, --help `: affiche l'aide complete
* ` [test] `: indique les tests à faire. Si `{vide}`, lance tout les tests
---

## Notes
