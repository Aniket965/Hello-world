def digitalSum(n):
  if n == 0:
      return 0
  return (n % 10 + digitalSum(int(n / 10))
