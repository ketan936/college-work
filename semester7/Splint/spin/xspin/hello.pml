proctype hello (){

printf("hello\n")
}

proctype world () {

printf("world\n")

}

init  {

run hello ();
run world ();

}
