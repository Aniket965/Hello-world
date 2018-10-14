defmodule SayHello do
  @moduledoc """
  A SayHello module that simply prints hello world.
  """

  @doc """
  English implementation of an hello world.

    ## Examples

        iex> SayHello.in_english
        Hello World!
        :ok
  """
  def in_english do
    IO.puts "Hello World!"
  end

  @doc """
  Italian implementation of an hello world.

    ## Examples

        iex> SayHello.in_italian
        Ciao Mondo!
        :ok
  """
  def in_english do
    IO.puts "Ciao Mondo!"
  end
end
