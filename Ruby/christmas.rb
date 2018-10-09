require 'date'

current_date = DateTime.now.strftime "%d/%m"
christmas_date = "25/12"
puts "Is it Christmas?"
if current_date == christmas_date
	puts "Yes, Happy Christmas!"
else
	puts "No, it's not Christmas"
end