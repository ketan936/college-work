mtype = { one, two, three };

chan q = [8] of { mtype };
chan c = [8] of { mtype };

active proctype sink()
{
    do
    :: q?one
    :: q?two
    :: q?three
    od
}

active proctype filter()
{	mtype m;
	do
	:: c?m -> q!m
	od
}

active proctype source()
{
    do
    :: c!one
    :: c!two
    :: c!three
    od
}
