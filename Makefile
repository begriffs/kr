# use no more nor less than ANSI C
CFLAGS = -std=c89 -Wall -Wextra -Wpedantic -Wshadow

.SUFFIXES :
.SUFFIXES : .o .c .h

all :
	ls 0*.c | xargs -J % -L 1 basename % .c | xargs ${MAKE}

watch:
	ls *.c *.h | entr ${MAKE}

clean :
	find . -maxdepth 1 -perm -111 -type f -exec rm {} +
	rm -f *.o

j-getch.o : j-getch.h
j-qsort.o : j-qsort.h
j-lines.o : j-lines.h

05-07-sort 05-14-sort-fancy 05-15-sort-case : $$@.c j-qsort.o j-lines.o
	${CC} ${CFLAGS} -o $@ $*.c j-qsort.o j-lines.o ${LDFLAGS}

05-01-getint 05-02-getfloat 05-18-dcl 06-01-keywords : $$@.c j-getch.o
	${CC} ${CFLAGS} -o $@ $*.c j-getch.o ${LDFLAGS}

# requiring -lm
04-04-calc 05-10-expr : $$@.c
	${CC} ${CFLAGS} -o $@ $? ${LDFLAGS} -lm
