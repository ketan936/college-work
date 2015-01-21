/* first example */
chan x = [0] of { bit };
chan y = [0] of { bit };
active proctype A() { x?0 unless y!0 }
active proctype B() { y?0 unless x!0 }
