# -*- coding: utf-8 -*-
import scrapy

class DefaultQuotesSpider(scrapy.Spider):
    name = 'default_quotes'
    allowed_domains = ['quotes.toscrape.com']
    start_urls = ['http://quotes.toscrape.com']

    def parse(self, response):
        
        for quote in response.css('div.quote'):
            print(quote.css('span.text::text').get())
            print(quote.css('small.author::text').get())
            for tag in quote.css('div.tags').css('a.tag::text'):
                print(tag.get())
