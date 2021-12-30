import re
import tools

if __name__ == '__main__':
    url = 'https://image.baidu.com/search/index?tn=baiduimage&ps=1&ct=201326592&lm=-1&cl=2&nc=1&ie=utf-8&dyTabStr=MCwzLDIsMSw1LDQsOCw3LDYsOQ%3D%3D&word=%E7%BE%8E%E5%A5%B3'
    tools.loadPage(url, 'pages/baiduImg.html')
    page = open('pages/baiduImg.html', 'r', encoding='utf-8')
    pageContent = page.read()
    #声明一个列表,存储图片地址
    imgUrls = []
    #利用正则表达式,在html文件中找出所有图片地址
    patten = re.compile(r'"thumbURL":"(.*?)",')
    imgUrls = patten.findall(pageContent)
    i = 0
    for imgUrl in imgUrls:
        tools.loadImg(imgUrl, i)
        i += 1
