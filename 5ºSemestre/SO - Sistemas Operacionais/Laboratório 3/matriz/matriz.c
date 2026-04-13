/**
 * Code: matriz.c (Header: matriz.h) 
 * Descrição: Implementação de funções básicas para manipular matriz de inteiros.
 * 
 * Autor: Rodrigo Campiolo
 * Data: 04/09/2019
 * Atualização: Erick Molina Gehring (13/04/2026) - Implementação de write_matrix_to_file.
 */

#include <stdio.h> 
#include <stdlib.h>
#include "matriz.h"
 
int** create_matrix(int row, int col) {
   int **matrix = (int **)malloc(row * sizeof(int *));
   for (int i = 0; i < row; i++) 
      matrix[i] = (int *)malloc(col * sizeof(int));
   return matrix;
}

void print_matrix(int** matrix, int row, int col) {
    for (int i = 0; i <  row; i++) {
      for (int j = 0; j < col; j++) {
         printf("%3d ", matrix[i][j]); 
      }
      printf ("\n");
   }
}

void generate_elements(int** matrix, int row, int col, int limit) {
   for (int i = 0; i <  row; i++) 
      for (int j = 0; j < col; j++)
         matrix[i][j] = rand()%limit + 1;
}

int** read_matrix_from_file(char* filename, int *row, int *col) {
   FILE *fd;
   int r, c;

   fd = fopen (filename, "r");
   if (!fd) return NULL;

   if (fscanf(fd, "%dx%d\n", &r, &c) != 2) {
       fclose(fd);
       return NULL;
   }
 
   int** m = create_matrix(r, c);
   for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
         if (fscanf(fd, "%d", &m[i][j]) != 1) break;
      }
   }
     
   fclose(fd);
   *row = r; *col = c;
   return m;
}

void write_matrix_to_file(char* filename, int** matrix, int row, int col) {
   FILE *fd = fopen(filename, "w");
   if (!fd) {
      perror("Erro ao abrir arquivo para escrita");
      return;
   }
   fprintf(fd, "%dx%d\n", row, col);
   for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
         fprintf(fd, "%d%s", matrix[i][j], (j == col - 1) ? "" : " ");
      }
      fprintf(fd, "\n");
   }
   fclose(fd);
}
