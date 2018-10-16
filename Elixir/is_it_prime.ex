defmodule PrimeNumbers do
  
  def print_possible_prime(number) when number == 2 do
    IO.inspect(" #{number} is prime") 
  end
  def print_possible_prime(number) do
    case fermat_little_thm(number) - 1 do
      0 -> IO.inspect("#{number} is prime")   
      _ -> IO.inspect("#{number} is not a prime")
    end
  end  
  
  def fermat_little_thm(number) do
    :math.pow(2, number - 1)
    |> round
    |> rem(number)
  end
end
