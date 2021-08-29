function checkName(name){
    if (name.value.length > 8){
        name.value = "";
        name.focus();
        alert("昵称过长，请换一个");
        return false
    }
    return true;
}

function checkAge(age){
    if (age.value > 140 || age.value < 6){
        age.value = "";
        age.focus();
        alert("年龄不符合要求");
        return false;
    }
    return true;
}

function checkPassword(p1, p2){
    if (p1.value.length < 6){
        p1.value = "";
        p2.value = "";
        p1.focus();
        alert("密码至少为6个字符");
        return false;
    }
    if (p2.value !== p1.value){
        p2.value = "";
        p2.focus();
        alert("两数输入密码不一致，请重新确认密码");
        return false;
    }
    return true;
}

function checkNull(form){
    for(i=0;i<form.length;i++){
        if(form.elements[i].value == ""){ //form属性的elements的首字母e要小写
            alert("很抱歉," + form.elements[i].name + "不能为空^-^");
            form.elements[i].focus();	//当前元素获取焦点
            return false;
        }
    }
    return true;
}

function check(form){
    if (checkNull(form)){
        return checkName(form.elements[0])&&
                checkAge(form.elements[3])&&
                checkPassword(form.elements[5], form.elements[6]);
    }
    return false;
}
