#!/usr/bin/perl
use 5.10.0;
use strict;
use warnings;

sub main {
  my $n = 5;
  my $fact = 1;
  for my $i (1..$n) {
    $fact *= $i;
  }
  say $fact;
}
main();
