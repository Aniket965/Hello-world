/**
 * @description This exampl is for mocha and chai test cases
 */
var expect  = require('chai').expect;
var request = require('request');

it('Would you like to have tea ?', function(done) {
    request('http://localhost:8080' , function(error, response, body) {
        expect(body).to.equal('Hello World chai pilo !!!');
        done();
    });
});
