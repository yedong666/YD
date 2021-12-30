auto()
timers.addDailyTask({
    path: '/sdcard/脚本/openApp.js',
    time: '10:35'
}, task => {
    toastLog("已开始在今日校园打卡；", + task)
})
var appName = '今日校园';
app = launchApp(appName);
while(!click('更多'));
while(!click('疫情信息收集'));
while(!click('提交'));