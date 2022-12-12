#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!s21_correct_matrix(A)) return INCORRECT_MATRIX;
  if (!s21_is_square_matrix(*A)) return CALC_ERROR;
  s21_create_matrix(A->rows, A->columns, result);
  double tmp = 0;
  int lol = OK;
  matrix_t minor = {0};
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      find_minor_matrix(A, i, j, &minor);
      lol = s21_determinant(&minor, &tmp);
      result->matrix[i][j] = tmp * pow(-1, i + j);
      s21_remove_matrix(&minor);
    }
  }
  return lol;
}
