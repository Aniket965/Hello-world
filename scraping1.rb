require 'mechanize'
require 'csv'
require 'byebug'
require 'json'

class RestApiPost

	def self.get_url(url)
		"http://www.#{url}/wp-json/wp/v2/posts"
	end

	def self.parse_response(url, csv, json_response)
	json_response.each { |article|
	match_data = article['content']['rendered'].match(/(wordpress backup|backup wordpress|backup plugin|updraft|vaultpress|backupbuddy|codeguard)/i)
		if match_data
		puts match_data.to_s
		article_id = article["id"]
		article_date = article["date"]
		article_title = article["title"]["rendered"]
		article_link = article["link"]
		article_author_link = article["_links"]["author"][0]['href']
		csv <<	[url ,article_id, article_date, article_title.strip, article_link, article_author_link]
	end
	}	
	end

	mechanize = Mechanize.new
	mechanize.agent.http.verify_mode = OpenSSL::SSL::VERIFY_NONE
	CSV.open("/home/sumit/test/scrapping_result/rest_api_post_from_link1.csv", "wb+") { |csv|
		csv << ['url', 'id', 'date', 'title', 'link', 'author_link']
		File.open("/home/sumit/articles_link.txt").each { |url|	
			begin
			request_url = get_url(url.strip)
			response = mechanize.get(request_url)
			parse_response(url.strip, csv, JSON.parse(response.body))
			rescue => e
				puts url
				puts e
			end
			}
		}
end
