defmodule FizzBuzz do 
  def to(max) do
    1..max |> Enum.each fn(n) ->
      case {rem(n, 3) === 0, rem(n, 5) === 0} do
        {true, true} -> IO.puts "#{n} FizzBuzz"
        {true, false} -> IO.puts "#{n} Fizz"
        {false, true} -> IO.puts "#{n} Bazz"
        _ -> IO.puts n
      end
    end
  end
end
