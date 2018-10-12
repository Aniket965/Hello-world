# Counting Duplicates
# Problem Statement: Write a function that will return the count of distinct case-insensitive alphabetic characters and numeric digits that occur more than once in the input string. The input string can be assumed to contain only alphabets (both uppercase and lowercase) and numeric digit

def duplicate_count(text)
   result = text.split("")
   result.group_by{|elem| elem and elem.upcase}.select{|key,val| val.length > 1}.keys.count
end


duplicate_count("")
duplicate_count("abcde")
duplicate_count("abcdeaa")
duplicate_count("abcdeaB")
duplicate_count("Indivisibilities")