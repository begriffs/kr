# use no more nor less than ANSI C
CFLAGS = -std=c89 -Wall -Wextra -Wpedantic -Wshadow -Werror

.SUFFIXES :
.SUFFIXES : .o .c .h

all :
	ls 0*.c | xargs -J % -L 1 basename % .c | xargs ${MAKE}

watch:
	ls *.c *.h | entr ${MAKE}

clean :
	find . -maxdepth 1 -perm -111 -type f -exec rm {} +
	rm -f *.o

# suffix rules can handle most of our source files, but the following
# require repetitive rules. Unfortunately I can't count on $* evaluating
# in regular dependency rules

j-getch.o : j-getch.h
j-qsort.o : j-qsort.h
j-lines.o : j-lines.h

05-07-sort : 05-07-sort.c j-qsort.o j-lines.o
	${CC} ${CFLAGS} -o $@ 05-07-sort.c j-qsort.o j-lines.o ${LDFLAGS}
05-14-sort-fancy : 05-14-sort-fancy.c j-qsort.o j-lines.o
	${CC} ${CFLAGS} -o $@ 05-14-sort-fancy.c j-qsort.o j-lines.o ${LDFLAGS}
05-15-sort-case : 05-15-sort-case.c j-qsort.o j-lines.o
	${CC} ${CFLAGS} -o $@ 05-15-sort-case.c j-qsort.o j-lines.o ${LDFLAGS}

05-01-getint : 05-01-getint.c j-getch.o
	${CC} ${CFLAGS} -o $@ 05-01-getint.c j-getch.o ${LDFLAGS}
05-02-getfloat : 05-02-getfloat.c j-getch.o
	${CC} ${CFLAGS} -o $@ 05-02-getfloat.c j-getch.o ${LDFLAGS}
05-18-dcl : 05-18-dcl.c j-getch.o
	${CC} ${CFLAGS} -o $@ 05-18-dcl.c j-getch.o ${LDFLAGS}
06-01-keywords : 06-01-keywords.c j-getch.o
	${CC} ${CFLAGS} -o $@ 06-01-keywords.c j-getch.o ${LDFLAGS}

.SECONDEXPANSION: # a GNU'ism to allow $$@

# requiring -lm
04-04-calc 05-10-expr : $$@.c
	${CC} ${CFLAGS} -o $@ $? ${LDFLAGS} -lm
