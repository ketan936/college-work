function write_data(data) {
$("#result p").html(data);
}


	
	/*$("td").hover(function() {
		write_data(($(this).parent("tr").index() + 1) +"x" + ($(this).index() + 1));
		$(this).addClass("hover");
	},function(){
		$(this).removeClass("hover");
	});*/
	
window.onload = function(){ 
	tags = document.getElementsByTagName("td");
	console.log(tags);
	for (i=0; i<tags.length; i++){
		tag = tags[i];
		console.log("hello");
		tag.addEventListener("click",function (){
			console.log("function is called");
		});
	}
	
};