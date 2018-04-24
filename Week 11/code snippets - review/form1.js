let form = document.getElementById("registration");
form.onsubmit = function() {
	if (!form.email.value) {
		alert("missing email");
		return false;
	} else if (!form.password.value) {
		alert("missing password");
		return false;
	} else if (form.password.value != form.confirmation.value) {
		alert("passwords don't match");
		return false;
	} else if (!form.agreement.checked) {
		alert("checkbox unchecked");
		return false;
	}
	return true;
};