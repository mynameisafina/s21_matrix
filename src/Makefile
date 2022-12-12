FLAGS = -Wall -Werror -Wextra -std=c11
FUNC_C = s21_create_matrix.c s21_transpose.c s21_remove_matrix.c s21_matrix.c \
s21_mult_matrix.c s21_sum_matrix.c s21_mult_number.c s21_eq_matrix.c \
s21_sub_matrix.c s21_determinant.c s21_calc_complements.c s21_inverse_matrix.c
FUNC_O = s21_create_matrix.o s21_transpose.o s21_remove_matrix.o s21_matrix.o \
s21_mult_matrix.o s21_sum_matrix.o s21_mult_number.o s21_eq_matrix.o \
s21_sub_matrix.o s21_determinant.o s21_calc_complements.o s21_inverse_matrix.o

all: s21_matrix.a

rebuild: clean all

clean:
	rm -rf *.o out *.info *.gcda *.gcno *.gcov *.gch *.out *.a test *.txt *.dSYM

s21_matrix.a: s21_matrix.o
	ar rc s21_matrix.a $(FUNC_O)
	ranlib s21_matrix.a

s21_matrix.o:
	gcc $(FLAGS) -c $(FUNC_C)

test: clean
	gcc $(FLAGS) -fprofile-arcs -ftest-coverage $(FUNC_C) -o test  s21_test.c -lcheck -lm -lpthread
	./test

gcov_report: test
	gcov s21_test.c
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out

style:
	clang-format -n *.c

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem ./

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./test

leak:
	leaks -atExit -- ./test 	

fsan: clean
	gcc $(FLAGS) -fsanitize=address -c $(FUNC_C)
	ar rcs s21_matrix.a $(FUNC_O)
	gcc -Wall -Werror -Wextra -fsanitize=address -std=c11 s21_test.c s21_matrix.a -L. -lcheck -lm -o test_f
	./test_f