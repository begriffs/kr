#ifndef __J_GETCH
#define __J_GETCH

int getch(void);
void ungetch(int);

int getword(char *, int);

enum pstate {
	ST_NORMAL,     ST_STR,     ST_STR_ESC,
	ST_COMMENT_IN, ST_COMMENT, ST_COMMENT_OUT
};

enum pstate new_state(enum pstate, int);

#endif
