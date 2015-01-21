function writeData(data) {
	console.log("Write data is called");
	document.querySelector("#result > p").innerHTML = data;
}

function findRowCount(element) {
	for (i = 0; i < rows.length; i++) {
		if (rows[i] == element)
			return i;
	}

}

mouseoverFunction = function() {
	console.log("Mouseover function is called");
	writeData(findRowCount(this.parentElement) + "x" + (this.cellIndex + 1));
	this.className = "hover";
	hoverCell =this;

};

mouseoutFunction = function() {
	console.log("Mouseout function is called");
	this.className = "";
};

mainFunction = function() {
	rows = document.getElementsByTagName("tr");
	tags = document.getElementsByTagName("td");
	console.log("Main function is loaded");
	for (i = 0; i < tags.length; i++) {
		tag = tags[i];
		tag.addEventListener("mouseover", mouseoverFunction);
		tag.addEventListener("mouseout", mouseoutFunction);
	}
};

window.addEventListener("load", mainFunction);