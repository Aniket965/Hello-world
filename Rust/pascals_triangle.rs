/*
 *    Written by Carlovan
 *    during Hacktoberfest 2018
 */

use std::collections::HashMap;

const LINES: u64 = 15; // Lines to calculate

// Recursively calculate binomial coefficient; uses an HashMap to sto previously calculated values
fn binomial_coefficient(n: u64, k: u64, bc_memo: &mut HashMap<(u64,u64),u64>) -> u64 {
	if k == 1 || k == n {
		return 1;
	}
	let pair = (n, k);
	// If I already calculated this one
	if bc_memo.contains_key(&pair) {
		return *bc_memo.get(&pair).unwrap();
	}
	// Else calculate recursively and save
	let result = binomial_coefficient(n - 1, k, bc_memo) + binomial_coefficient(n - 1, k - 1, bc_memo);
	bc_memo.insert(pair, result);
	result
}

fn main() {
	let mut bc_memo = HashMap::new();

	// The width to show a number
	let width = binomial_coefficient(LINES, LINES/2, &mut bc_memo).to_string().len() + 3 & (!1);

	for i in 1..LINES+1 {
		let indentation = (width * (LINES - i) as usize) / 2;
		print!("{}", " ".repeat(indentation));
		for j in 1..i+1 {
			print!("{1: ^0$}", width, binomial_coefficient(i, j, &mut bc_memo));
		}
		println!("");
	}
}
