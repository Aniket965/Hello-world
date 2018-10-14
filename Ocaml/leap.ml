let leap_year y =
  let divisible_by x = y mod x = 0 in
  divisible_by 400 || not @@ divisible_by 100 && divisible_by 4
