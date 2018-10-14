var ViewModel = function() {
    this.helloWorld = ko.observable('Hello World from KnockoutJS!');
};
 
ko.applyBindings(new ViewModel());