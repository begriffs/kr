#include <stdio.h>

/* Keeping track of states like being in a string
   literal, or escaped quotes would be similar to
   exercise 1-10-remove-comments so I'm being lazy
   and not duplicating it here */

int main()
{
	int curl_count = 0, brack_count = 0,
		brace_count = 0, dq_count = 0, sq_count = 0;
	int c;

	while((c = getchar()) != EOF) {
		if (c == '(') ++curl_count;
		if (c == ')') --curl_count;
		if (c == '[') ++brack_count;
		if (c == ']') --brack_count;
		if (c == '{') ++brace_count;
		if (c == '}') --brace_count;
		if (c == '"') ++dq_count;
		if (c == '\'') ++sq_count;

		if (curl_count < 0) {
			puts("Unbalanced parens");
			return;
		}
		if (brack_count < 0) {
			puts("Unbalanced brackets");
			return;
		}
		if (brace_count < 0) {
			puts("Unbalanced braces");
			return;
		}
	}

	if (curl_count != 0)
		puts("Unbalanced parentheses");
	if (brack_count != 0)
		puts("Unbalanced square brackets");
	if (brace_count != 0)
		puts("Unbalanced braces");
	if (dq_count % 2 != 0)
		puts("Unbalanced double quotes");
	if (sq_count % 2 != 0)
		puts("Unbalanced single quotes");
}
