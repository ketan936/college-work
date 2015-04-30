struct input_quiz{
char answer[256];
float b;
float a;
int op;
};
struct output_quiz{
char answer[256];
float b;
int op;
};

program QUIZ_PROG {
    version QUIZ_VERS {
        input_quiz QUIZ_QUES() = 1;
	input_quiz QUIZ_ANS(input_quiz) = 2;    
    } = 1;                         
} = 0x31234568;                    
