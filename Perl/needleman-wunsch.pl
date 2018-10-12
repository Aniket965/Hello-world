#!/usr/bin/perl
use strict;
use warnings;

use Getopt::Std;

my $display_dp;

my @sequences;
my @aligned_sequences;
$sequences[0] = "";
$sequences[1] = "";
my %scores;
$scores{A}{A} = 4;
$scores{A}{C} = -3;
$scores{A}{T} = -3;
$scores{A}{G} = -2;

$scores{C}{A} = -3;
$scores{C}{C} = 4;
$scores{C}{T} = -2;
$scores{C}{G} = -3;

$scores{T}{A} = -3;
$scores{T}{C} = -2;
$scores{T}{T} = 4;
$scores{T}{G} = -3;

$scores{G}{A} = -2;
$scores{G}{C} = -3;
$scores{G}{T} = -3;
$scores{G}{G} = 4;

my $gap = -8;



sub needleman_wunsch
{
	my @dp;
	my @traceback;
	my $vert;
	my $hor;
	my $diag;
	my $base1; #the current base from sequence 1
	my $base2; #the current base from sequence 2
	$dp[0][0] = 0;
	$traceback[0][0] = "D";
	for my $i (1 .. length($sequences[0])) {
		$dp[$i][0] = $dp[$i-1][0] + $gap;
		$traceback[$i][0] = "^";
		# print substr $sequences[0], $i-1, 1;
		# print "\n";
	}
	print "\n";
	for my $j (1 .. length($sequences[1])) {
		$dp[0][$j] = $dp[0][$j-1] + $gap;
		$traceback[0][$j] = "<";
		# print substr $sequences[1], $j-1, 1;
		# print "\n";
	}
	for my $i (1 .. length($sequences[0])) {
		for my $j (1 .. length($sequences[1])) {
			$dp[$i][$j] = 0;
			$traceback[$i][$j] = "0";		
		}
	}
	for my $i (1 .. length($sequences[0])) {
		for my $j (1 .. length($sequences[1])) {
			$base1 = substr $sequences[0], $i-1, 1;
			$base2 = substr $sequences[1], $j-1, 1;
			$vert = $dp[$i-1][$j] + $gap;
			$hor  = $dp[$i][$j-1] + $gap;
			$diag = $dp[$i-1][$j-1] + $scores{$base1}{$base2};
			if($diag >= $vert and $diag >= $hor){
				$dp[$i][$j] = $diag;
				$traceback[$i][$j] = "D";
			}elsif($vert >= $diag and $vert >= $hor){
				$dp[$i][$j] = $vert;
				$traceback[$i][$j] = "^";
			}elsif($hor >= $diag and $hor >= $vert){
				$dp[$i][$j] = $hor;
				$traceback[$i][$j] = "<";
			}
		}
	}
	if($display_dp){
		print "\t-\t";
		for my $j (0 .. length($sequences[1])) {
			print substr $sequences[1], $j, 1;
			print "\t";
		}
		print "\n-\t";
		for my $i (0 .. length($sequences[0])) {
			if($i != 0){
				print substr $sequences[0], $i-1, 1;
				print "\t";
			}
			for my $j (0 .. length($sequences[1])) {
				print $dp[$i][$j] . "\t";
			}
			print "\n";
		}

		print "\n\n";
		print "\t-\t";
		for my $j (0 .. length($sequences[1])) {
			print substr $sequences[1], $j, 1;
			print "\t";
		}
		print "\n-\t";
		for my $i (0 .. length($sequences[0])) {
			if($i != 0){
				print substr $sequences[0], $i-1, 1;
				print "\t";
			}
			for my $j (0 .. length($sequences[1])) {
				print $traceback[$i][$j] . "\t";
			}
			print "\n";
		}
	}
	print "Best Alignment Score: ".$dp[length($sequences[0])][length($sequences[1])]."\n";

	my $j = length $sequences[1];
	my $i = length $sequences[0];
	my $final_len;
	$aligned_sequences[0] = "";
	$aligned_sequences[1] = "";
	while($i >= 0 and $j >= 0){
		if($traceback[$i][$j] eq "D"){
			$aligned_sequences[0] =  (substr $sequences[0], $i, 1) . $aligned_sequences[0];
			$aligned_sequences[1] =  (substr $sequences[1], $j, 1) . $aligned_sequences[1];
			$i--;
			$j--;
		}elsif($traceback[$i][$j] eq "^"){
			$aligned_sequences[0] =  (substr $sequences[0], $i, 1) . $aligned_sequences[0];
			$aligned_sequences[1] =  "-" . $aligned_sequences[1];
			$i--;
		}elsif($traceback[$i][$j] eq "<"){
			$aligned_sequences[0] =  "-" . $aligned_sequences[0];
			$aligned_sequences[1] =  (substr $sequences[1], $j, 1) . $aligned_sequences[1];
			$j--;
		}
	}
	print $aligned_sequences[0] . "\n" . $aligned_sequences[1] . "\n";
}

sub parse_input
{
	my $filename = $ARGV[0];
	my $seq  = "";
	my $seq_num = -1;

	open(my $fh, '<:encoding(UTF-8)', $filename)
	 or die "Unable to open file: '$filename' - STOPPED\n";

	 while (my $row = <$fh>){
	 	chomp $row;
	 	if(index($row, ">") != 0)
	 	{
	 		if(!$sequences[$seq_num] || length($sequences[$seq_num]) == 0)
	 		{
	 			$sequences[$seq_num] = $row;
	 		} else 
	 		{
	 			$sequences[$seq_num].=$row;
	 		}
	 	} else 
	 	{
	 		$seq_num++;
	 	}
	 }
	 for my $i (0 .. $seq_num){
	 	print "Sequence ". ($i+1).": ".$sequences[$i]."\n";
	 }
	 needleman_wunsch();
}

sub main 
{
	my %opts;
	$display_dp = 0;
	getopts('o:', \%opts);
	if($opts{o}) {
		$display_dp = 1;
	}
	if($ARGV[0]){
		#has input file
	} else { 
		die "No file provided - STOPPED\n";
	}
	parse_input();
}

main();
