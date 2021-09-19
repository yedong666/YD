"auto";
// app.viewFile("./Camera/1617060142882.jpg");
var qq = "755422304";
app.startActivity({ 
    action: "android.intent.action.VIEW", 
    data:"mqq://im/chat?chat_type=wpa&version=1&src_type=web&uin=" + qq, 
    packageName: "com.tencent.mobileqq", 
});
sleep(1000);