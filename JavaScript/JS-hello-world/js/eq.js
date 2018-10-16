function Equation(a,b,c,l,m,n){
    var x=0,y=0;
this.a=a;
this.b=b;
this.c=c;
this.l=l;
this.m=m;
this.n=n;

this.countX = function (){
    var x = (this.b*this.n - this.c*this.m) / (this.l*this.b- this.a * this.m);
    console.log("X = " +x);

}
this.countY = function (){
    var y = (this.a * this.n - this.l * this.c) / (this.a* this.m - this.l * this.b);
    console.log("Y = " +y);


}  

}

var eq = new Equation(3,3,10,12,1,3,6);
eq.countX();
eq.countY();
