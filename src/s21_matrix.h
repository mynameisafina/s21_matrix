#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define INCORRECT_MATRIX 1
#define CALC_ERROR 2

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
int s21_is_square_matrix(matrix_t A);
int s21_correct_matrix(matrix_t *A);
int s21_is_equal_size(matrix_t *A, matrix_t *B);
int find_minor_matrix(matrix_t *A, int m, int n, matrix_t *result);
int make_low_triangle_matrix(int size, double number, matrix_t *A);
int make_triangle_matrix(int size, double number, matrix_t *A);

#endif  // SRC_S21_MATRIX_H_