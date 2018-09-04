# -*- coding: utf-8 -*-
import scrapy
import json

class ScrollQuotesSpider(scrapy.Spider):
    name = 'scroll_quotes'
    allowed_domains = ['quotes.toscrape.com']
    start_urls = ['http://quotes.toscrape.com/api/quotes?page=1']

    def parse(self, response):
        data = json.loads(response.body)
        page = 1 
        for quote in data['quotes']:
        	print(quote['author']['name'])
        	print(quote['text'])
        	for tag in quote['tags']:
        		print(tag)
        if data['has_next']:
        	page += 1
        	yield scrapy.Request(url='http://quotes.toscrape.com/api/quotes?page='+page)

        