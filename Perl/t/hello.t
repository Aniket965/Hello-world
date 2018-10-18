#!/usr/bin/perl -w

use Test::Simple tests => 3;

ok((-x 'hello.pl'),"executable");
mkdir($ENV{'HOME'}.'/log');
mkdir($ENV{'HOME'}.'/log/hello.pl');
ok(`./hello.pl`,"ran");
ok(-d $ENV{'HOME'}.'/log/hello.pl',"logdir created");
