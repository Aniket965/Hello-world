# -*- coding: utf-8 -*-
import scrapy


class RalphlaurenbotSpider(scrapy.Spider):
    name = 'ralphlaurenbot'
    allowed_domains = ['www.ralphlauren.co.uk/en/men/clothing/1020?webcat=men-clothing']
    start_urls = ['http://www.ralphlauren.co.uk/en/men/clothing/1020?webcat=men-clothing/']

    def parse(self, response):
    	# extrating the tag 
        tag=response.css('.name-link::text').extract()
        # extracting the price
        price=response.css('.product-sales-price::text').extract()
        # extracting the image src (2 classes are used as one of the images is inside a different class)
        img=response.css('.thumb-link img.default-img::attr(src)').extract()

        # storing the data to store data
        for item in zip(tag,price,img):
        	scrapped_info={
        		'tag' : item[0],
        		'price' : item[1],
        		'image' :item[2]
        	}
           	yield scrapped_info
  		# extracting the link for the next page
    	next_page = response.css('.first-lastbar a::attr(href)').extract_first()
    	# calling the parse function with the new link
        if next_page is not None:
            next_page = response.urljoin(next_page)
            yield scrapy.Request(next_page, callback=self.parse,dont_filter=True)

