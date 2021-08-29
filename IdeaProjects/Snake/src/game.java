public class game {
    public static void main(String[] args) {
        Map snake_map = new Map();
        Snake snake = new Snake();
        while (true) {
            snake_map.Init_map(snake);
            snake_map.draw_map();
            snake.snake_move();
            try {
                Thread.sleep(1000);//单位：毫秒
            } catch (Exception e) {
            }
            System.out.flush();
        }
    }
}
