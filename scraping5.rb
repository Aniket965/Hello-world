require 'mechanize'
require 'csv' 
require 'byebug'

class ThemeforestFromAuthorLinks
	mechanize = Mechanize.new
	CSV.open("/home/sumit/test/scrapping_result/themeforest_author_details.csv", 'wb+') { |csv|
		csv << ['author_link', 'sales', 'social_links']
		count = 0
		File.open("/home/sumit/authors_link.txt").each_line { |url|
			begin
				puts count
				count += 1
				res = mechanize.get(url)
				result = [url]
				sales = res.search('div.user-info-header__stats-content')[1].text if res.search('div.user-info-header__stats-content')[1]
				sales ? result.push(sales.strip) : result.push("")
				a_tags = res.search('div.social-networks a')
				if a_tags
					a_tags.each do |a_tag|
						result.push a_tag['href']
					end
				end
				csv << result
			rescue => e
				puts e
			end
		}
	}
end
