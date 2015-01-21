mtype = { msgtype };

chan name = [0] of { mtype, byte };

active proctype A()
{	name!msgtype(124);
	name!msgtype(121)
}

active proctype B()
{	byte state;
	name?msgtype(state)
}
