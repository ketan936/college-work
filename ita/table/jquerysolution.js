function writeData(data) {
	$("#result p").html(data);
}

$(document).ready(function() {
			console.log("in cell");
			$("td").hover(function() {
						writeData(($(this).parent("tr").index() + 1) + "x" + ($(this).index() + 1));
						$(this).addClass("hover");
					}, function() {
						$(this).removeClass("hover");
					});
		});