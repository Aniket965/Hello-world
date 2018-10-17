var app = angular.module("app", []);
    app.controller("HelloController", function($scope) {
      $scope.hello = "Hello World!";
      $scope.helloworld = "Hello World";
$scope.fibbo = function(numMax){
    for(var fibArray = [0,1], i=0,j=1,k=0; k<numMax;i=j,j=x,k++ ){
        x=i+j;
        fibArray.push(x);
    }
	$scope.fibseries = fibArray;
    console.log(fibArray);
}
	}
);
