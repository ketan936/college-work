#define can_proceed	true

active proctype counter()
{   int cnt = 1;

    do
    :: can_proceed ->
        /* perform a step */
        cnt++;
        printf("step: %d\n", cnt)
    od
}
