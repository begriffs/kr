# use no more nor less than ANSI C
CFLAGS = -std=c89 -Wall -Wextra -Wpedantic -Wshadow

all :
	ls 0*.c | xargs -J % -L 1 basename % .c | xargs ${MAKE}

05-01-getint 05-02-getfloat 05-18-dcl 06-01-keywords : j-getch.o
05-07-sort 05-14-sort-fancy 05-15-sort-case : j-qsort.o j-lines.o

# additional deps beyond the suffix rule
j-getch.o : j-getch.h
j-qsort.o : j-qsort.h
j-lines.o : j-lines.h

# these programs require -lm
04-04-calc 05-10-expr :
	${CC} ${CFLAGS} -o $@ $? ${LDFLAGS} -lm

04-04-calc : 04-04-calc.o
05-10-expr : 05-10-expr.o

clean :
	find . -maxdepth 1 -perm -111 -type f -exec rm {} +
	rm -f *.o
