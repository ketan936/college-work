/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "quiz.h"


void
quiz_prog_1(char *host)
{
	CLIENT *clnt;
	output_quiz  *result_1;
	char *quiz_ques_1_arg;
	output_quiz  *result_2;
	input_quiz  quiz_ans_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, QUIZ_PROG, QUIZ_VERS, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = quiz_ques_1((void*)&quiz_ques_1_arg, clnt);
	if (result_1 == (output_quiz *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = quiz_ans_1(&quiz_ans_1_arg, clnt);
	if (result_2 == (output_quiz *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	quiz_prog_1 (host);
exit (0);
}
