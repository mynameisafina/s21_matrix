#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (!s21_correct_matrix(A) || result == NULL) return INCORRECT_MATRIX;
  if (!s21_is_square_matrix(*A)) return CALC_ERROR;
  int check = OK;
  double tmpres = 0;
  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  } else if (check == OK) {
    matrix_t lol = {0};
    double tmp = 0;
    for (int i = 0; check == OK && i < A->rows; i++) {
      check = find_minor_matrix(A, i, 0, &lol);
      if (check == OK) check = s21_determinant(&lol, &tmp);
      if (check == OK) tmpres += tmp * A->matrix[i][0] * (i % 2 == 0 ? 1 : -1);
      s21_remove_matrix(&lol);
    }
    *result = tmpres;
    // s21_remove_matrix(&lol);
  }
  return OK;
}
