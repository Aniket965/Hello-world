require 'mechanize'
require 'csv' 
require 'byebug'

class ThemeisleFromLinks
	mechanize = Mechanize.new
	CSV.open("/home/sumit/test/scrapping_result/themeisle_article_details.csv", 'wb+') { |csv|
		csv << ['url', 'article_name', 'article_date', 'author_grvatar_link', 'author_name', 'author_description']
		count = 0
		File.open("/home/sumit/articles_link.txt").each_line { |url|
			begin
				puts count
				count += 1
				res = mechanize.get(url)
				article_name = res.search('h1.entry-title').text if res.search('h1.entry-title')
				article_date = res.search('time').text if res.search('time')
				author_gravatar_link = res.search('div.author-details-img-wrap img')[1]['src'] if res.search('div.author-details-img-wrap img')[1]
				author_name = res.search('div.author-details-title').text if res.search('div.author-details-title')
				author_description = res.search('div.author-details-content').text if res.search('div.author-details-content')
				csv << [url, article_name, article_date, author_gravatar_link, author_name, author_description]
			rescue => e
				puts e
			end
		}
	}
end
