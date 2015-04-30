#include <rpc/rpc.h>        /* standard RPC include file */
#include "date.h"           /* this file is generated by rpcgen */

/*
 * Return the binary date and time
 */
 
 long * bin_date_1_svc(void * temp, struct svc_req * req)
 {
    static long timeval;    /* must be static */
 
    timeval = time((long *) 0);
    return(&timeval);
 }
 
/*
 * Convert a binary time and return a human readable string
 */
  
char ** str_date_1_svc(long *bintime, struct svc_req *req)
{
    static char *ptr;       /* must be static */
    ptr = ctime(bintime);   /* convert to local time */
    return(&ptr);
}
