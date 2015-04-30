struct input_quiz{
char anaswer[256];
};
struct output_quiz{
char reply[256];
};

program QUIZ_PROG {
    version QUIZ_VERS {
        output_quiz QUIZ_QUES() = 1; 
	output_quiz QUIZ_ANS(input_quiz) = 2;    
    } = 1;                         
} = 0x31234569;                    
