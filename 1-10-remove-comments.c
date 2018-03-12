#include <stdio.h>

#define MAYBE_IN_COMMENT      0
#define IN_COMMENT            1
#define MAYBE_LEAVING_COMMENT 2
#define NORMAL                3

#define IN_STRLIT             4
#define IN_CHRLIT             5
#define STR_ESCAPE            6
#define CHR_ESCAPE            6


int main()
{
	int c, state = NORMAL;

	while ((c = getchar()) != EOF) {
		if (state == NORMAL) {
			if (c == '/')
				state = MAYBE_IN_COMMENT;
			else {
				if (c == '"')
					state = IN_STRLIT;
				else if (c == '\'')
					state = IN_CHRLIT;
				putchar(c);
			}
		} else if (state == MAYBE_IN_COMMENT) {
			if (c == '*')
				state = IN_COMMENT;
			else {
				state = NORMAL;
				putchar('/');
				putchar(c);
			}
		} else if (state == IN_COMMENT) {
			if (c == '*')
				state = MAYBE_LEAVING_COMMENT;
		} else if (state == MAYBE_LEAVING_COMMENT) {
			if (c == '/')
				state = NORMAL;
			else
				state = IN_COMMENT;
		} else if (state == IN_STRLIT) {
			if (c == '"')
				state = NORMAL;
			if (c == '\\')
				state = STR_ESCAPE;
			putchar(c);
		} else if (state == IN_CHRLIT) {
			if (c == '\'')
				state = NORMAL;
			if (c == '\\')
				state = CHR_ESCAPE;
			putchar(c);
		} else if (state == STR_ESCAPE) {
			state = IN_STRLIT;
			putchar(c);
		} else if (state == CHR_ESCAPE) {
			state = IN_CHRLIT;
			putchar(c);
		}
	}
}
