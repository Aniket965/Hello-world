defmodule MyList do
  def reverse(list) do
    reverse(list, [])
  end

  defp reverse([], result), do: result
  defp reverse([h|t], result) do
    reversed = [h] ++ result
    reverse(t, reversed)
  end
end
