require 'mechanize'
require 'csv' 
require 'byebug'

class Themeisle
	mechanize = Mechanize.new
	Baseurl = "https://themeisle.com/blog/page/"
	CSV.open("/home/sumit/test/scrapping_result/themeisle.csv", 'wb+') { |csv|
		for page in 1..32 do
			begin
				puts page
				res = mechanize.get("#{Baseurl}#{page}/")
				articles = res.search('article')
				articles.each do |article|
					csv << [article.search('h2.entry-title a')[0]['href']] if article.search('h2.entry-title a')[0]
				end
			rescue => e
				puts e
			end
		end

	}

end
