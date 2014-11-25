/*
 * Models the Pathfinder scheduling algorithm and explains the
 * cause of the recurring reset problem during the mission on Mars
 *
 * there is a high priority process, that consumes
 * data produced by a low priority process.
 * data consumption and production happens under
 * the protection of a mutex lock
 * the mutex lock conflicts with the scheduling priorities
 * which can deadlock the system if high() starts up
 * while low() has the lock set
 * there are 12 reachable states in the full (non-reduced)
 * state space -- two of which are deadlock states
 * partial order reduction cannot be used here because of
 * the 'provided' clause that models the process priorities
 */

mtype = { free, busy, idle, waiting, running };

mtype H_state = idle;
mtype L_state = idle;
mtype mutex = free;

active proctype high_priority()
{
end:
    do
    :: H_state = waiting;
        atomic { mutex == free -> mutex = busy };
        H_state = running;

        /* produce data */

        atomic { H_state = idle; mutex = free }
    od
}

active proctype low_priority() provided (H_state == idle)
{
end:
    do
    :: L_state = waiting;
        atomic { mutex == free -> mutex = busy };
        L_state = running;

        /* consume data */

        atomic { L_state = idle; mutex = free }
    od
}
