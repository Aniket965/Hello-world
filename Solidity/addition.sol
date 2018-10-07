pragma solidity ^0.4.18;

contract Addition{
  
  uint private sum;

function addNumber(uint _a, uint _b) public constant returns(uint)
  {
     sum = _a+_b;
     return sum;
  } 
}
