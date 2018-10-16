defmodule Fibonacci do

  def get_fibonacci(number) when is_integer(number) and number >= 0 do
    calculate_fibonacci(number) |> IO.inspect
  end

  def get_fibonacci(_number) do
    IO.inspect("Enter a positive integer!")
  end

  def calculate_fibonacci(number) when number in 0..1, do: 1

  def calculate_fibonacci(number) do
    calculate_fibonacci(number - 1) + calculate_fibonacci(number - 2)
  end
end

