mtype = { msgtype };

chan glob = [0] of { chan };

active proctype A()
{	chan loc = [0] of { mtype, byte };
	glob!loc;
	loc?msgtype(121)
}

active proctype B()
{	chan who;
	glob?who;
	who!msgtype(121)
}
