require 'mechanize'
require 'csv'
require 'json'
require 'byebug'

class RestApiUserFromLink
	mechanize = Mechanize.new
	CSV.open("/home/sumit/test/scrapping_result/rest_api_users_from_link1.csv", 'wb') { |csv|
		count = 0
		File.open("/home/sumit/users_link.txt").each { |url|
			begin
				puts count
				count += 1
				response = mechanize.get(url.strip)
				user = JSON.parse(response.body)
				user_id = user['id']
				user_name = user['name']
				user_description = user['description']
				user_link = user['link']
				gravatar_url = user['avatar_urls']['24'] || "" if user['avatar_urls']
				csv << [url.strip, user_id, user_name, user_description, user_link, gravatar_url]
			rescue => e
				puts e
			end
		}
	}
end
