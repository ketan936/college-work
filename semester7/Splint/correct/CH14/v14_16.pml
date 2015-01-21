#define Final \
	subscriber@Idle && switch@end \
	&& remote[4]@Idle && remote[5]@Idle \
	&& session_ss7[2]@Idle && session_ss7[3]@Idle

#define Event(x) \
	do \
	:: last_sent == x -> break \
	:: else \
	od

never {	/* sample of a 3way call: */
	Event(offhook);
	Event(digits);
	Event(flash);
	Event(digits);
	Event(flash);
	Event(digits);
	Event(flash);
	Event(onhook);
	do
	:: Final -> break
	:: else
	od
}
