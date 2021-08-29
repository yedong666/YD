package work1;

public class work2 {
    static final int SLOW = 1;
    static final int MEDUM = 2;
    static final int FAST = 3;

    public static void main(String[] args){
        Fan fan1 = new Fan();
        Fan fan2 = new Fan(FAST, true, 10.0, "blue");
        System.out.println(fan1.toString());
        System.out.println(fan2.toString());
    }

    static class Fan {
        private int speed;
        private boolean on;
        private double radius;
        private String color;

        Fan() {
            speed = work2.SLOW;
            on = false;
            radius = 5;
            color = "blue";
        }

        Fan(int sp, boolean isOn, double r, String col) {
            speed = sp;
            on = isOn;
            radius = r;
            color = col;
        }

        public String toString() {
            StringBuilder str = new StringBuilder();

            if (on) {
                str.append("speed: ");
                str.append('0' + speed);
                str.append("    ");
            }

            str.append("color: ");
            str.append(color);
            str.append("    ");
            str.append("radius: ");
            str.append(radius);

            if (!on) {
                str.append("    fan is off");
            }

            return str.toString();
        }

        public int getSpeed(){
            return speed;
        }

        public double getRadius(){
            return radius;
        }

        public String getColor(){
            return color;
        }

        public boolean getOn(){
            return on;
        }

        public void setSpeed(int speed){
            this.speed = speed;
        }

        public void setOn(boolean on){
            this.on = on;
        }

        public void setRadius(double radius){
            this.radius = radius;
        }

        public void setColor(String color){
            this.color = color;
        }
    }
}



