CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
VALGRIND=valgrind --leak-check=full --leak-resolution=med -s
OS:= $(shell uname -s)
LINFLAGS=-lcheck -pthread -lrt -lm -lsubunit
SRCFILE = s21_math.c 
OBJECTS = s21_math.o 

all: clean test 

s21_math.a:
	$(CC) $(CFLAGS) -c $(SRCFILE)
	@ar rcs s21_math.a $(OBJECTS)
	ranlib s21_math.a

test: s21_math.a
ifeq ($(OS), Darwin)
	gcc s21_test.c s21_math.a  -o test `pkg-config --cflags --libs check` -lcheck -lpthread -fsanitize=address
	./test
	rm -rf *.o *.a 
else
	gcc s21_test.c s21_math.a -o test $(LINFLAGS)
	./test
	rm -rf *.o *.a 
endif

gcov_report: clean
ifeq ($(OS), Darwin)
	gcc --coverage s21_test.c -o test $(SRCFILE) -lcheck
	./test
	gcov -f s21_string.gcda
	lcov -t "s21_test" -o s21_test.info -c -d .   
	genhtml -o report s21_test.info
	open ./report/index.html
else
	gcc --coverage s21_test.c -o test $(SRCFILE) $(LINFLAGS)
	./test
	gcov -f s21_string.gcda
	lcov -t "s21_test" -o s21_test.info -c -d .  
	genhtml -o report s21_test.info
	xdg-open ./report/index.html
endif

check: clean cppcheck style leaks

cppcheck: test
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

style: test
	clang-format -style=google -i *.c *.h
	clang-format -style=google -n *.c *.h
	rm .clang-format 

clean:
	-rm -rf *.o && rm -rf *.gcno && rm -rf *.exec
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./gcov_report
	-rm -rf ./run_tests ./test 
	-rm -rf ./report/
	-rm -rf *.log
