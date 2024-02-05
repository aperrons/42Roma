function addCell() {
	var row = document.getElementById("row");
	var card = document.getElementById("item").cloneNode(true);
	var x = row.insertCell(-1);
	x.innerHTML = card.innerHTML;
}