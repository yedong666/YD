public class CLchar {
    int number;
    CLchar(String testStr){
        //设置相关运算符的优先级
        switch (testStr){
            case "#":
            case ")": number = 0; break;
            case "+":
            case "-": number = 1; break;
            case "*":
            case "/": number = 2; break;
            case "!":
            case "^":
            case "sqrt:" : number = 3; break;
            case ".": number = 4; break;
            default: number = -1; break;
        }
    }
}
