# UIN-Campus

Système de gestion académique de l'UIN. Ce dépôt contient le squelette du
projet, réalisé dans le cadre du TP 2 (mise en place de l'environnement) du
cours de POO en C++.

Version actuelle : 0.1.0

## Environnement

Système : Ubuntu 26.04.1 LTS

Versions des outils relevées :

```
<g++ (Ubuntu 15.2.0-16ubuntu1) 15.2.0
Ubuntu clang version 21.1.8 (6ubuntu1)
cmake version 4.2.3
1.13.2
GNU gdb (Ubuntu 17.1-2ubuntu1) 17.1
git version 2.53.0>
```

Standard utilisé : C++23.

## Prérequis

```bash
sudo apt install build-essential clang clangd clang-format clang-tidy lldb gdb \
    cmake ninja-build valgrind cppcheck git
```

## Construction

Configuration et compilation avec le preset `debug` (sanitizers ASan et UBSan
activés) :

```bash
cmake --preset debug
cmake --build --preset debug
```

Exécution :

```bash
./build/debug/uin-campus
```

Résultat attendu :

```
UIN-Campus — Système de gestion académique
Version 0.1.0
```

Version optimisée, sans sanitizers :

```bash
cmake --preset release
cmake --build --preset release
./build/release/uin-campus
```

## Qualité du code

Pour que clangd et clang-tidy retrouvent les options de compilation :

```bash
ln -s build/debug/compile_commands.json .
```

Formatage et analyse statique :

```bash
clang-format -i include/uincampus/*.hpp src/*.cpp app/*.cpp
clang-tidy -p build/debug src/*.cpp app/*.cpp
```

## Arborescence

```
uin-campus/
├── CMakeLists.txt
├── CMakePresets.json
├── .clang-format
├── .clang-tidy
├── .gitignore
├── include/uincampus/version.hpp
├── src/version.cpp
├── app/main.cpp
└── tests/            (vide pour l'instant)
```

## Remarque

La macro `UIN_VERSION` est définie par CMake à partir de la version déclarée
dans `project(...)` : la version n'existe qu'à un seul endroit.