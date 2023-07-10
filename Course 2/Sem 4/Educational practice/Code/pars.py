import requests
from selenium import webdriver
from bs4 import BeautifulSoup as bs
from time import sleep

URL_TEMPLATE = "https://coinmarketcap.com/"

cl_table = []
name_class = ''
symbol_class = ''
cap_class = ''


def data_search(name):
    global cl_table
    for i in cl_table:
        if str(name).lower() == str(i[0]).lower() or str(name).lower() == str(i[1]).lower():
            return i

    return (['Введено неверное название'])


def find_class_names():
    r = requests.get(URL_TEMPLATE)
    soup = bs(r.text, "html.parser")
    code = soup.prettify()

    global name_class, symbol_class, cap_class
    code = code[code.find("name-area"):]
    name_class = code[code.find("name-area"):code.find("Bitcoin")]
    name_class = name_class[name_class.find("="):name_class.find(" color")]
    name_class = name_class[2:-1]

    symbol_class = code[code.find(
        "</div>"):code.find("coin-item-symbol") + 1 + len("coin-item-symbol")]
    symbol_class = symbol_class[symbol_class.find("=") + 2:-1]

    cap_class = code[code.find("cmc-link"):]
    cap_class = cap_class[:cap_class.find('data-nosnippet="true"')]
    cap_class = cap_class[-50:]
    cap_class = cap_class[cap_class.find('"') + 1:-2]


def data_processing(soup):
    global name_class, symbol_class, cap_class
    data = [[0]*4 for i in range(100)]

    table = soup.find('tbody')
    rows = table.find_all("tr")

    count = 0
    for row in rows:
        try:
            data[count][0] = str(
                (row.find("p", class_=name_class)).text)

            data[count][1] = str(
                (row.find("p", class_=symbol_class)).text)

            price_code = row.find_all("a", class_="cmc-link")
            for i in price_code:
                try:
                    price = i.find('span').text
                    data[count][2] = str(price)
                except:
                    pass

            data[count][3] = str(
                (row.find("span", class_=cap_class)).text)
        except:
            pass

        count += 1

    global cl_table
    cl_table = data


def req_parsing():
    r = requests.get(URL_TEMPLATE)
    soup = bs(r.text, "html.parser")

    data_processing(soup)


def sel_parsing():
    options = webdriver.EdgeOptions()
    options.add_argument('headless')
    options.add_argument('--disable-gpu')
    driver = webdriver.Edge("./msedgedriver.exe", options=options)

    driver.get(URL_TEMPLATE)

    max_height = 0
    scroll_height = 1000

    while True:
        # Получаем текущую позицию
        current_position = driver.execute_script("return window.pageYOffset;")

        # Прокручиваем страницу на scroll_height пикселей вниз
        driver.execute_script(
            f"window.scrollTo(0, {current_position + scroll_height});")
        sleep(1)

        # Проверяем, достигли ли мы конца страницы
        new_scroll_height = driver.execute_script(
            "return document.body.scrollHeight")
        if new_scroll_height == max_height:
            break
        max_height = new_scroll_height

    soup = bs(driver.page_source, 'html.parser')

    driver.close()

    data_processing(soup)
