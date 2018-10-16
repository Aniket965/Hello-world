function validateEmail(theForm) {
    if (/^w+([.-]?w+)*@w+([.-]?w+)*(.w{2,3})+$/.test(theForm.email-id.value)){
        return(true);
    }
    alert("Invalid e-mail address! Please enter again carefully!.");
    return(false);
}

/**
*Body:
*
*<form onSubmit="return validateEmail(this);" action="">
*E-mail Address:
*<input type="text" name="emailid" />
*<input type="submit" value="Submit" />
*<input type="reset" value="Reset" />
*</form>
*
*/
