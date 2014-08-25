$(document).ready(function() {
	console.log("outside");
	$("form").submit(function(event) {
		console.log("hello");
		event.preventDefault();
		alert("Handler for .submit() called.");

	});
});