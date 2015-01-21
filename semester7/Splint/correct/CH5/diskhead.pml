#define Nclients	3

inline disk_io() {
    activeproc = curproc;
    assert(Interrupt_set == false);
    Interrupt_set = true;
}

inline Serve_client(x) {
    client_busy[x] = true;
    curproc = x+1;
    if    /* check disk status */
    :: activeproc == 0 -> disk_io()
    :: else /* Busy */ -> req_q!curproc
    fi
}

inline Handle() {
    Interrupt_set = false;
    client_busy[activeproc-1] = false;
    if
    :: req_q?curproc -> disk_io()
    :: empty(req_q) -> activeproc = 0
    fi
}

active proctype disk_sched()
{   chan req_q = [Nclients] of { byte };
    bool client_busy[Nclients] = false;
    bool Interrupt_set = false;
    byte activeproc, curproc;

    do
    :: !client_busy[0] -> progress_0: Serve_client(0)
    :: !client_busy[1] -> progress_1: Serve_client(1)
#if Nclients>2
    :: !client_busy[2] -> progress_2: Serve_client(2)
#endif
    :: Interrupt_set == true -> Handle()
    od
}
