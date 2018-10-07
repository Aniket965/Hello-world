def factorial_recursive(n)
    n.zero? ? 1 : n * factorial_recursive(n - 1)
end