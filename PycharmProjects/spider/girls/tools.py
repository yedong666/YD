import requests

def loadPage(url, saveUrl):
    #设置请求头，防止网站反爬
    header = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/93.0.4577.63 Safari/537.36',
        'Cookie': 'HMACCOUNT_BFESS=48D5DAD13DC6E2D0; BAIDUID_BFESS=6B48173580C30F0265D6435BAE2C86F2:FG=1',
        'Accept': 'image/avif,image/webp,image/apng,image/svg+xml,image/*,*/*;q=0.8',
        'Accept-Encoding': 'gzip, deflate, br',
        'Accept-Language': 'zh-CN,zh;q=0.9'
        }
    res = requests.get(url, headers=header)
    # 获取响应消息的内容，并对其进行解码
    content = res.content.decode("utf-8")
    file = open(saveUrl, "w+", encoding='utf-8')
    file.write(content)
    file.close()

def loadImg(url, num):
    res = requests.get(url)
    # 获取响应消息的内容，并对其进行解码
    num = str(num)
    content = res.content
    file = open("imgs/baidu_girl" + num + ".jpg", "ab")
    print("imgs/baidu_girl" + num + ".jpg")
    file.write(content)
    file.close()