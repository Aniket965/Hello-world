require 'mechanize'
require 'csv' 
require 'byebug'

class Themeforest
	mechanize = Mechanize.new
	Baseurl = "https://themeforest.net/category/wordpress?page="
	CSV.open("/home/sumit/test/scrapping_result/themeforest.csv", 'wb+') { |csv|
		csv << ['article_name', 'author_name', 'author_link']
		for page in 1..60 do
			begin
				puts page
				res = mechanize.get("#{Baseurl}#{page}")
				articles = res.search('ul._1qKTi article')
				articles.each do |article|
					article_name = article.search('div._3mIlg a').text if article.search('div._3mIlg a')
					author_name = article.search('div._1lg18 a').text if article.search('div._1lg18 a')
					author_link = article.search('div._1lg18 a')[0]['href'] if article.search('div._1lg18 a')[0]
					csv << [article_name, author_name, author_link]
				end
			rescue => e
				puts e
			end
		end
	}
end
