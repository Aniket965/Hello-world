require 'mechanize'
require 'csv'
require 'byebug'
class Checkmoz
	def self.fetch
		mechanize = Mechanize.new
		websites = []
		File.open("/home/sumit/input.txt").each { |website|
			websites << website
		}
		response = mechanize.get("https://www.checkmoz.com/")
		form = response.form
		CSV.open("/home/sumit/test/out.csv", "wb+") { |csv|
		websites.each { |website|
			form.field_with(:name => 'url_form').value = website
			result = form.submit
			da = result.search('div.table-wrap tr td')[2].text if result.search('div.table-wrap tr td')[2]
			pa = result.search('div.table-wrap tr td')[3].text if result.search('div.table-wrap tr td')[3]
			moz_rank = result.search('div.table-wrap tr td')[4].text if result.search('div.table-wrap tr td')[4]
			external_links = result.search('div.table-wrap tr td')[5].text if result.search('div.table-wrap tr td')[5]
			csv << [website, da, pa, moz_rank, external_links]
		}
		}
	end

	Checkmoz.fetch

end
