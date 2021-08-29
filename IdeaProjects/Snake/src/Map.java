public class Map {
    static final int map_weight = 90, map_height = 31;
    char[][] map = new char[map_height][map_weight];

    public void Init_map(Snake snake){
            for(int i = 0; i<map_height; i++){
                for(int j = 0; j<map_weight; j++){
                    if(i == 0 || j == 0 || i==map_height-1 ||j == map_weight-1){
                            map[i][j] = '#';
                    }
                    else{
                        map[i][j] = ' ';
                    }
                }
            }
            map[snake.snakebodies.get(0).x][snake.snakebodies.get(0).y] = '@';
            for(int k = 1; k<snake.snakebodies.size(); k++) {
                if (snake.snakebodies.size() > 0) {
                    map[snake.snakebodies.get(k).x][snake.snakebodies.get(k).y] = 'o';
                }
            }
    }

    public void draw_map(){
        for(int i = 0; i<map_height; i++) {
            for (int j = 0; j < map_weight; j++) {
                System.out.print(map[i][j]);
            }
            System.out.println();
        }
    }

}
