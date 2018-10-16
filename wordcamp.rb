require 'mechanize'
require 'csv'
require 'byebug'
class WordcampSpeakers
	urls = []
	File.open("/home/sumit/urls.txt").each_line{ |url| urls << url.strip }
	mechanize = Mechanize.new
	CSV.open("/home/sumit/test/scrapping_result/wordcamp1.csv", "wb+") { |csv|
	csv << ["url", "name", "gravatar_url", "description"]
	urls.each { |url|
		puts url
		res = mechanize.get(url)
		speakers = res.search("div.wcorg-speaker")
		speakers.each { |speaker|
			name = speaker.search("h2")[0].text if speaker.search("h2")
			gravatar_url = speaker.search("img")[0]["src"] if speaker.search("img") && speaker.search("img")[0]
			description = speaker.search("p").text
			csv << [url, name.strip, gravatar_url, description]
		}
	}
	}

end
