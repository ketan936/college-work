 
#include "quiz.h"
#include <string.h>
input_quiz *
quiz_ques_1_svc(void *argp, struct svc_req *rqstp)
{
        static input_quiz  result;
int key;
key  = rand()%4;
switch (key) {
			case 0:
			 strcpy(result.answer,"2+2");
	
				break;
 case 1:
                         strcpy(result.answer,"2+3");
                         result.b=5;
                                break;
case 2:
                         strcpy(result.answer,"2+5");
                         result.b=7;
                                break;
 case 3:
                         strcpy(result.answer,"2+4");
result.b=6;
                                break;
 case 4:
   strcpy(result.answer,"2+5");

                                break;


			default:
				break;
		}
        result.op=key;
        return &result;
}

input_quiz *
quiz_ans_1_svc(input_quiz *argp, struct svc_req *rqstp)
{
        static input_quiz  result;

       if(argp->b == argp->a){
         strcpy(result.answer,"yes");
       }
       else
        strcpy(result.answer,"no");
        return &result;
}
 
