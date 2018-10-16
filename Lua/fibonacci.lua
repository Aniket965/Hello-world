local function fibonacci(n)
  local a, b = 0, 1
  for i = 1, n do
    a, b = b, a + b
  end
  return a
end

print(fibonacci(10))
