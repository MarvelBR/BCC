/**
 * Header: matriz.h
 * Descrição: funções básicas para manipular matriz dinâmica de inteiros.
 * 
 * Autor: Rodrigo Campiolo
 * Data: 04/09/2019
 * Atualização: Erick Molina Gehring (13/04/2026) - Adição de gravação em arquivo.
 */

#ifndef MATRIZ_H
#define MATRIZ_H

/** 
 * Cria uma matriz de inteiros row x col dinamicamente.
 * Entrada: row (linhas), col (colunas)
 * Saída: ponteiro para a matriz
 */
int** create_matrix(int row, int col);

/**
 * Gera elementos inteiros aleatórios para uma matriz existente.
 * Entrada: matrix, row, col, limit (valor máximo)
 */
void generate_elements(int** matrix, int row, int col, int limit);

/**
 * Lê uma matriz de um arquivo no formato "MxN".
 * Entrada: filename, ponteiros para row e col
 * Saída: ponteiro para a matriz lida
 */
int** read_matrix_from_file(char* filename, int *row, int *col);

/**
 * Exibe a matriz na saída padrão.
 */
void print_matrix(int** matrix, int row, int col);

/**
 * Grava a matriz em um arquivo texto no formato "MxN".
 * Entrada: filename, matrix, row, col
 */
void write_matrix_to_file(char* filename, int** matrix, int row, int col);

#endif
