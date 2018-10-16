require 'mechanize'
require 'csv'
require 'byebug'
require 'json'

def url(f)
  "http://" + f.strip
end

public
def human_readable_to_i
  multiplier = {'K' => 1_000, 'M' => 1_000_000}[self.upcase[/[KM](?=\z)/]] || 1
  value = self.gsub(/[^\d.]/, '')
  case value.count('.')
    when 0 then value.to_i
    when 1 then value.to_f
    else 0
  end * multiplier
end

mechanize = Mechanize.new
#read data from a file
CSV.open('/tmp/data.csv','a+') { |csv|
  csv << ['url', 'article_title', 'time_published']
  file = File.open("list.txt")
  count = 0
  file.each_line { |line|
    line = line.gsub("\n", '')
    count += 1
    begin
      puts count
      res = mechanize.get(line)
      if res
        article_title = res.at('meta[property="og:title"]') ? res.at('meta[property="og:title"]')[:content].strip : "NF"
        if article_title == "NF"
          article_title = res.title ? res.title.strip : "NF"
        end
        time_published = res.at('meta[property="article:published_time"]') ? res.at('meta[property="article:published_time"]')[:content] : "NF"
        csv << [line, article_title, time_published]
      end
    rescue => e
      csv << [line, "", ""]
      puts e, line
    end
  }
}
