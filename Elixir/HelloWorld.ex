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
  def in_italian do
    IO.puts "Ciao Mondo!"
  end
  
  @doc """
  Spanish implementation of an hello world.

    ## Examples

        iex> SayHello.in_spanish
        Ciao Mondo!
        :ok
  """
  def in_spanish do
    IO.puts "Hola Mundo!"
  end
end
