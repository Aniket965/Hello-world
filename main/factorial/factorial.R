fatorialrec = function(n){

	if(n%%1!=0 || n<0 || is.numeric(n)) stop(“erro”)

	if(n==1 || n==0) return(1)

	return(fatorialrec(n-1)*n)
}
