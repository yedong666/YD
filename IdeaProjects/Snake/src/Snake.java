import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Snake {
    int length;
    ArrayList<snakebody> snakebodies = new ArrayList<>();

    Snake(){
        Random random = new Random();
        snakebody body1 = new snakebody(), body2 = new snakebody(), body3 = new snakebody();
        int x1, y1;
        x1 = random.nextInt(11)+10;
        y1 = random.nextInt(31)+30;
        body1.set_coord(x1,y1);
        snakebodies.add(body1);
        body2.set_coord(x1, y1+1);
        snakebodies.add(body2);
        body3.set_coord(x1, y1+2);
        snakebodies.add(body3);
    }

    public void snake_move(){
        snakebody tempbody = new snakebody();
        tempbody.x = snakebodies.get(0).x;
        tempbody.y = snakebodies.get(0).y-1;
        snakebodies.remove(snakebodies.size()-1);
        snakebodies.add(0,tempbody);
    }

}
