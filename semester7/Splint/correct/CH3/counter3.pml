byte count;

active proctype counter()
{
	do
	:: (count != 0) ->
		if
		:: count++
		:: count--
		fi
	:: (count == 0) -> break
	od
}
