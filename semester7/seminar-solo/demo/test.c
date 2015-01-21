 #include <stdio.h>
   #include <stdlib.h>
#include <string.h>
#include <glib.h>
   int
   main(void)
   {
FILE * fp;
       char * line = NULL;
       size_t len = 0;
       ssize_t read;
       char* serial = "4C530303040604115195";
       

       fp = fopen("data.txt", "r");
       if (fp == NULL)
           exit(EXIT_FAILURE);

       while ((read = getline(&line, &len, fp)) != -1) {
    		gchar* ptr=NULL;
    		ptr = g_strrstr(line , "\n");
    		if (ptr){
    			ptr[0]='\0';
    		}
    		printf("::%s::\n",line );
           if (g_strcmp0(serial,line) == 0){
            g_print("match found\n");
           if (line)
            free(line);
          return 0;
       }
       }

      fclose(fp);
  
    return 1;
   }