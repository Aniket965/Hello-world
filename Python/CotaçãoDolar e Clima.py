# COTAÇÃO DO DOLAR E CLIMA ATUAL
import re
import requests
import json

rc = requests.get('http://api.promasters.net.br/cotacao/v1/valores').text
cotacoes = re.findall(r'\d\.\d+', rc)  # TODAS COTAÇÕES

cidade = str(input('Digite a cidade: ')).strip().lower()
cidade = cidade.split(' ')
cidade = '%20'.join(cidade)

rt = requests.get('https://api.hgbrasil.com/weather/?format=json&city_name=' + cidade + '&key=bcb790a1').text
dic = json.loads(rt)
print(dic)
print('O dolar está custando: {}\n'.format(cotacoes[0]))
print('Em {}'.format(dic['results']['city_name']))
print('Faz {}ºC e está {}\nSão exatamente {}'.format(dic['results']['temp'], dic['results']['description'], dic['results']['time']))
