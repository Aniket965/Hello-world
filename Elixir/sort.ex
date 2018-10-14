defmodule Sort do
    # insert element at right place in list
    defp _insert(element, []), do: [element]
    defp _insert(element, [head | tail]) when element <= head do
        [element, head | tail]
    end
    defp _insert(element, [head|tail]) do
        [head|_insert(element, tail)]
    end
    # use insert to do an insertion sort
    def isort(l), do: isort(l,[])
    def isort([], sorted), do: sorted
    def isort([head|rest], sorted) do
        isort(rest, _insert(head, sorted))
    end

    # merge sort
    def merge([], y), do: y
    def merge(x, []), do: x
    def merge([xh|xt]=x, [yh|yt]=y) when xh > yh, do: [yh | merge(x,yt)]
    def merge([xh|xt]=x, y), do: [xh | merge(xt, y)]

    def msort([]), do: []
    def msort([x]), do: [x]
    def msort(l) do
        {left, right} = msplit(l,[],[])
        merge(msort(left), msort(right))
    end

    def msplit([], left, right), do: {left, right}
    def msplit([head|tail], left, right) do
        msplit(tail, [head | right], left)
    end

    # quicksort
    def qsort([]), do: []
    def qsort([p|l]) do
        {left, right} = qsplit(p, l, [], [])
        small = qsort(left)
        large = qsort(right)
        append(small, [p|large])
    end

    def qsplit(_, [], small, large), do: {small, large}
    def qsplit(p, [h|t], small, large) do
        cond do
            h <= p  -> qsplit(p, t, [h|small], large)
            true    -> qsplit(p, t, small, [h|large])
        end
    end

    def append([], back), do: back
    def append([h|t], back), do: [h|append(t,back)]
end
