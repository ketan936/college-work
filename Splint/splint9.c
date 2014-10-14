oid updateEnv(char * str)
{
char * tmp;
 tmp = getenv(“MYENV”);
if (tmp != NULL)
strcpy (str, tmp);
}
bounds.c:9: Possible out-of-bounds store:
strcpy(str, tmp)
Unable to resolve constraint:
requires maxSet(str @ bounds.c:9) >=
maxRead(getenv("MYENV") @ bounds.c:7)
needed to satisfy precondition:
requires maxSet(str @ bounds.c:9) >=
maxRead(tmp @ bounds.c:9)
derived from strcpy precondition: requires
maxSet(<parameter 1>) >=
maxRead(<parameter 2>)
void updateEnvSafe (char * str,
size_t strSize)
/*@requires maxSet(str)
>= strSize –1@*/
{
char * tmp;
tmp = getenv(“MYENV”);
if (tmp != NULL)
{
strncpy (str, tmp,
strSize -1);
str[strSize -1] = ‘/0’;
}
}

