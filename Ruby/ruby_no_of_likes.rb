# Who likes it?
# Problem Statement: You probably know the "like" system from Facebook and other pages. People can "like" blog posts, pictures or other items. We want to create the text that should be displayed next to such an item.
# Implement a function likes :: [String] -> String, which must take in input array, containing the names of people who like an item. 
# Example:

# likes [] // must be "no one likes this"
# likes ["Peter"] // must be "Peter likes this"
# likes ["Jacob", "Alex"] // must be "Jacob and Alex like this"
# likes ["Max", "John", "Mark"] // must be "Max, John and Mark like this"
# likes ["Alex", "Jacob", "Mark", "Max"] // must be "Alex, Jacob and 2 others like this"


def likes(names)
  if names.empty?
    "no one likes this"
  elsif names.length == 1
    "#{names.first} likes this"
  elsif names.length == 2
    "#{names.first} and #{names.last} like this"
  elsif names.length == 3
    "#{names.first(2).join(', ')} and #{names.last} like this"
  else
    "#{names.first(2).join(', ')} and #{(names - names.first(2)).count} others like this"
  end
end



likes([])
likes(['Peter'])
likes(['Peter', 'Sam', 'Andrew'])

