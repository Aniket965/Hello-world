#
# Odd or Even Program in Perl
#
use strict;
use warnings;
print "Enter a number\n";
my $num = <STDIN>;
if ($num%2 == 0){
print "The number you entered is even\n";}
else {
print "The number you entered is odd\n";
}