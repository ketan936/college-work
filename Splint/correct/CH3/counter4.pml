byte count;

active proctype counter()
{
	do
	:: (count != 0) ->
		if
		:: count++
		:: count--
		:: else
		fi
	:: else -> break
	od
}
