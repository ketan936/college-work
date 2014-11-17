function write_data(data) {
$("#result p").html(data);
}


	
	/*$("td").hover(function() {
		write_data(($(this).parent("tr").index() + 1) +"x" + ($(this).index() + 1));
		$(this).addClass("hover");
	},function(){
		$(this).removeClass("hover");
	});*/
rows = document.getElementsByTagName("tr");
function findRowCount(element){
	console.log(rows);
for (i=0; i<rows.length; i++){
	if (rows[i] == element)
		return i;
}

}
mouseoverFunction = function (){
			console.log("function is called");
			write_data( findRowCount(this.parentElement) +"x" + (this.cellIndex+1));
			p = this;
			k = this.parentElement;
			n = this.parentNode;
			console.log(k.cellIndex);
			this.className = "hover";
		};
mouseoutFunction = function (){
	
	this.className = "";
};


console.log("outside windows")	

	console.log("hello"); 
	tags = document.getElementsByTagName("td");

	console.log(tags);
	for (i=0; i<tags.length; i++){
		tag = tags[i];
		console.log("hello");
		tag.addEventListener("mouseover",mouseoverFunction);
		tag.addEventListener("mouseout",mouseoutFunction);
	}
