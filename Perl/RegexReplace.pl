#!/usr/bin/perl
$bar = "Hello All!\r\n";
print $bar;
$bar =~ s/\bAll\b/World/;
print $bar;
