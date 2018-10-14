class Main
  def self.run
    arr = [93, 2, 47, 1, 902]
    puts bubble_sort(arr)
  end

  def self.bubble_sort(arr)
    (0).upto((arr.length - 2)).each do |i|
      (0).upto((arr.length - 2 - i)).each do |j|
          arr[j], arr[j+1] = arr[j+1], arr[j] if arr[j] > arr[j+1]
      end
    end
    arr
  end
end


Main.run