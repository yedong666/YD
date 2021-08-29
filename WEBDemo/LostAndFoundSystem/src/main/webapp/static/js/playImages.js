function changeImg(){
    const messages = new Array("这是图片一", "这是图片二", "这是图片三")
    const nums = imgs.length;
    let img = document.getElementById("image");
    let mesg = document.getElementById("imgMessage");
    img.src = imgs[i%nums];
    mesg.innerHTML = messages[i%nums];
    i++;
}

let i = 0;
setInterval(changeImg, 3000);
