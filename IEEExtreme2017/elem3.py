import requests


session = requests.Session()

session.headers.update({'Cookie': 'crossSessionId=u2lwcda374udixopbw6hfunlq8onoowh; csrftoken=oFo0r2bfk3CEMQBFUC10cOBpBl08xf3qK4cxLjP4oJilCNxXt7vEsBB7e2i70wHB',
'Origin': 'https://csacademy.com',
'Accept-Encoding': 'gzip, deflate, br',
'Accept-Language': 'es-419,es;q=0.8,en-US;q=0.6,en;q=0.4',
'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.100 Safari/537.36',
'Content-Type': 'multipart/form-data; boundary=----WebKitFormBoundaryDSBJTdTASRxZUc9i',
'Accept': '*/*',
'Referer': 'https://csacademy.com/ieeextreme11/task/c787255968c972c653677a52599ecc2f/',
'x-requested-with': 'XMLHttpRequest',
'Connection': 'keep-alive',
'x-csrftoken': 'oFo0r2bfk3CEMQBFUC10cOBpBl08xf3qK4cxLjP4oJilCNxXt7vEsBB7e2i70wHB',
'DNT': '1'})


def getAnswer(entrada):
    data = '------WebKitFormBoundaryDSBJTdTASRxZUc9i\r\nContent-Disposition: form-data; name="type"\r\n\r\nelementary\r\n------WebKitFormBoundaryDSBJTdTASRxZUc9i\r\nContent-Disposition: form-data; name="input"\r\n\r\n{0}------WebKitFormBoundaryDSBJTdTASRxZUc9i--\r\n'.format(entrada)
    return session.post('https://csacademy.com/eval/input_server_test/', data=data).json()


a = open('in.txt')
print(getAnswer(a.read().replace('\n', '\r\n'))['output'])
