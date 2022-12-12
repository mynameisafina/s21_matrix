#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!s21_correct_matrix(A)) return INCORRECT_MATRIX;
  if (!s21_is_square_matrix(*A)) return CALC_ERROR;
  int i = OK;
  double determ = 0;
  i = s21_determinant(A, &determ);
  if (determ == 0 || fabs(determ) <= 1e-7) return CALC_ERROR;
  if (i == OK) {
    matrix_t tmp = {0};
    i = s21_calc_complements(A, result);
    if (i == OK) i = s21_transpose(result, &tmp);
    s21_remove_matrix(result);
    if (i == OK) i = s21_mult_number(&tmp, 1 / determ, result);
    s21_remove_matrix(&tmp);
  }
  return i;
}
