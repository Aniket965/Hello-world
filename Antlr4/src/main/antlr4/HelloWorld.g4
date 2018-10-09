grammar HelloWorld;
helloWorld   : 'hello' NAME;
NAME  : [a-z]+ ;
WS  : [ \t\r\n]+ -> skip ;