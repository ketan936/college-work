/*
 * trivial model, generating the state space
 * from Figure 8.9 without weak fairness or
 * from Figure 8.10 with weak fairness
 */

bool x;
active proctype A() { do :: d_step { !x -> x=1 } od }
active proctype B() { do :: d_step { x -> x=0 } od }
never {
S1:	x == 0;
accept:	x == 1;
	goto S1
}
