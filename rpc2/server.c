#include <rpc/rpc.h>        /* standard RPC include file */
#include "calc.h"           /* this file is generated by rpcgen */

/*
 * Return the binary date and time
 */
 
float * calculator_1_svc(input_calc* temp, struct svc_req * req)
 {
    static float val;    /* must be static */
 	
    val = (float)temp->a +(float)temp->b;
    return(&val);
 }
 
/*
 * Convert a binary time and return a human readable string
 */
  
