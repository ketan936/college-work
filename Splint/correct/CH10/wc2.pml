chan STDIN;
int c, nl, nc;

init {


    do
    :: STDIN?c ->
        if
        :: c == -1 ->   break  /* EOF */
        :: c == '\n' -> nc++; nl++
        :: else ->      nc++
        fi;
        if
        :: true ->
            skip
        :: true ->
            if
            :: true ->
                skip; skip
            :: true
            fi
        fi
    od;
    assert(nc >= nl);
    printf("%d\t%d\n", nl, nc)
}
