#include "s21_matrix.h"

int s21_is_square_matrix(matrix_t A) {
  if (A.rows == A.columns) return 1;
  return 0;
}

int s21_correct_matrix(matrix_t *A) {
  if (A == NULL || A->rows <= 0 || A->columns <= 0 || A->matrix == NULL)
    return 0;
  return 1;
}

int s21_is_equal_size(matrix_t *A, matrix_t *B) {
  if (A->rows == B->rows && A->columns == B->columns) {
    return 1;
  }
  return 0;
}

int find_minor_matrix(matrix_t *A, int m, int n, matrix_t *result) {
  if (!s21_correct_matrix(A)) return INCORRECT_MATRIX;
  if (!s21_is_square_matrix(*A)) return CALC_ERROR;
  if (A->rows == 1 || A->columns == 1) return CALC_ERROR;
  s21_create_matrix(A->rows - 1, A->columns - 1, result);
  for (int i = 0, k = 0; i < A->rows; i++) {
    if (i == m) continue;
    for (int j = 0, l = 0; j < A->columns; j++) {
      if (j == n) continue;
      result->matrix[k][l] = A->matrix[i][j];
      l++;
    }
    k++;
  }
  return OK;
}

int make_triangle_matrix(int size, double number, matrix_t *A) {
  s21_create_matrix(size, size, A);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i <= j) {
        A->matrix[i][j] = number;
      } else {
        A->matrix[i][j] = 0;
      }
    }
  }
  return OK;
}

int make_low_triangle_matrix(int size, double number, matrix_t *A) {
  s21_create_matrix(size, size, A);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i >= j) {
        A->matrix[i][j] = number;
      } else {
        A->matrix[i][j] = 0;
      }
    }
  }
  return OK;
}
