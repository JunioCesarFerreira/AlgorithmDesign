# Exercise Generate Words With Space

## Enunciado

Escreva um programa que gere todas as strings possíveis (incluindo a própria string) que
contenha espaços em brancos entre cada um dos caracteres.

## Formulação Matemática do Problema

Neste exercício temos um problema simples de combinatória, um arranjo com repetição pois dada uma string $w$ digamos que $|w|=n$ isto é $w$ tem $n$ simbolos. Assim, teremos $n$ posições entre os simbolos que podem ou não ser preenchidas com espaços. Logo, para uma string com $n$ simbolos teremos $2^{n}$ combinações de strings.

## Sobre a Solução

Esta solução só é possível por backtracking (força bruta), pois é necessário apresentar todas as combinações possíveis.