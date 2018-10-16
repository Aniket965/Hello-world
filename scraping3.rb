require 'mechanize'
require 'csv'
require 'byebug'
require 'active_support/all'

class SeoWebPageAnalyzer
	mechanize = Mechanize.new
	CSV.open("/home/sumit/test/scrapping_result/seo_web_page_analyzer_result1.csv", 'wb') { |csv|
		csv << ['url', 'Total amount of images', 'Images without alt attribute', 'Images with 
				empty alt attribute', 'h1 count', 'h2count', 'title', 'keywords', 'description']
		count = 0
		File.open("/home/sumit/marketing_links.txt").each { |url|
			begin
				puts count
				count += 1
				url = url.strip
				result = [url]
				response = mechanize.get("http://www.seowebpageanalyzer.com/")
				form = response.form_with(:action => 'http://www.seowebpageanalyzer.com')
				form.field_with(:id => 'url').value = url
				res = form.submit
				li_tags = res.search('div#images ul.statslist li')
				if li_tags && li_tags.present?
					li_tags.each { |li_tag|
						result << li_tag.search('dd').text
					}
				else
					result.push('nil') * 3
				end
				result << res.search('div.heading-structure h1').count
				result << res.search('div.heading-structure h2').count
				dd_tags = res.search('div#meta dd')
				if dd_tags
					dd_tags.each { |dd_tag|
						result << dd_tag.text
					}
				else
					result.push('nil') * 3
				end
				csv << result
				sleep(1)
			rescue => e
				puts e
			end
		}
	}
end
