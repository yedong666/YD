package geometry;

/*
需求:
    用面向对象的思维设计相关类，从而实现直线与直线、直线与圆、直线与矩形的交点，并判
    断给定点是否在矩形或者圆内部（含边界上的点）。
    要求各给出每个案例的至少一个示例的程序。

分析:
    对于编写如直线、圆、矩形等几合类，关键点在于用合适属性表示其关键信息
    对于直线，采用ax + by + c = 0的形式可表示出平面坐标系内的所有直线，只需确定a、b、c三个参数，即可确定唯一一条直线
    对于平面坐标系内的圆，确定其圆心坐标(x,y)半径r即可确定唯一圆
    对于矩形，确定其左上角顶点(a,b)与右下角顶点(c,d)即可确定唯一矩形

    对于计算直线与直线、直线与圆、直线与矩形的交点，并判
    断给定点是否在矩形或者圆内部（含边界上的点），根据相关数学知识，使用几何图形的参数可方便算出

 */

import java.util.ArrayList;
import java.util.List;

/**
 * 几何图形类(作基类）
 */
abstract class Geometry{}

interface IntersectWithLine{
    public List<Coordinate> intersectWithLine(Line line);
}

class Util{
    public static boolean isDoubleEqule(double a, double b){
        return Math.abs(a - b) < 0.00000001;
    }
}

/**
 * 点类
 */
class  Coordinate{
    double x;
    double y;

    public Coordinate(double x, double y){
        this.x = x;
        this.y = y;
    }
}

/**
 * 直线类
 */
class Line extends Geometry implements IntersectWithLine{
    double a;
    double b;
    double c;

    public Line(double a, double b, double c) {
        if (a == 0 && b == 0){
            System.out.println("直线x的系数与y的系数不能同时为0");
            return;
        }
        this.a = a;
        this.b = b;
        this.c = c;
    }

    @Override
    public List<Coordinate> intersectWithLine(Line line) {
        double t = this.a * line.b - this.b * line.a;
        List<Coordinate> coordinates = new ArrayList<>();
        if (Util.isDoubleEqule(t, 0.0)){
            System.out.println("两直线平行，无交点");
        } else{
            double x = ((-this.c) * line.b - (-line.c) * this.b) / t;
            double y = ((-line.c) * this.a - (-this.c) * line.a) / t;
            Coordinate coordinate = new Coordinate(x, y);
            coordinates.add(coordinate);
        }
        return coordinates;
    }
}

/**
 * 圆类
 */
class Circle extends Geometry implements IntersectWithLine{
    Coordinate centerOfCircle;
    double r;
    public Circle(Coordinate centerOfCircle, double r) {
        if (r == 0){
            System.out.println("圆的半径不能为0!");
            return;
        }
        this.centerOfCircle = centerOfCircle;
        this.r = r;
    }

    @Override
    public List<Coordinate> intersectWithLine(Line line) {
        double a;
        double b;
        double c;
        int flag = 0;
        if (Util.isDoubleEqule(line.a, 0.0)){
            a = 1.0;
            b = -2.0 * this.centerOfCircle.x;
            c = (this.centerOfCircle.x) * (this.centerOfCircle.x) - this.r * this.r +
                    (line.c/ line.b + this.centerOfCircle.y) * (line.c/ line.b + this.centerOfCircle.y);
            flag = 1;
        } else if(Util.isDoubleEqule(line.b, 0.0)){
            a = 1.0;
            b = -2.0 * this.centerOfCircle.y;
            c = (this.centerOfCircle.y) * (this.centerOfCircle.y) - this.r * this.r +
                    (line.c/ line.a + this.centerOfCircle.x) * (line.c/ line.a + this.centerOfCircle.x);
            flag = 2;
        } else{
            a = 1.0 + (line.a/ line.b) * (line.a/ line.b);
            b = ((2.0 * line.a * line.c)/(line.b) * line.b) + ((2.0 * line.a * this.centerOfCircle.y)/ line.b) -
                    2.0 * this.centerOfCircle.x;
            c = (this.centerOfCircle.x) * (this.centerOfCircle.x) + (line.c * line.c) / (line.b * line.b) +
                    this.centerOfCircle.y * this.centerOfCircle.y + (2.0 * this.centerOfCircle.y * line.c) /
                    line.b - this.r * this.r;
            flag = 3;
        }

        double t = b * b - 4.0 * a * c;
        if (t < 0.0){
            System.out.println("直线与圆没有交点！");
            return null;
        }
        double ti = Math.sqrt(t);
        List<Coordinate> coordinates = new ArrayList<>();
        if (flag == 1 ||  flag == 3){
            double x1 = ((-b) + ti) / (2.0 * a);
            double x2 = ((-b) - ti) / (2.0 * a);

            if (Util.isDoubleEqule(x1, x2)){
                double y = -((line.c + line.a * x1) / line.b);
                Coordinate coordinate = new Coordinate(x1, y);
                coordinates.add(coordinate);
            }else{
                double y1 = -((line.c + line.a * x1) / line.b);
                double y2 = -((line.c + line.a * x2) / line.b);
                Coordinate coordinate1 = new Coordinate(x1, y1);
                Coordinate coordinate2 = new Coordinate(x2, y2);
                coordinates.add(coordinate1);
                coordinates.add(coordinate2);
            }

        } else{
            double y1 = ((-b) + ti) / (2.0 * a);
            double y2 = ((-b) - ti) / (2.0 * a);
            if (Util.isDoubleEqule(y1, y2)){
                double x = -((line.c + line.b * y1) / line.a);
                Coordinate coordinate = new Coordinate(x, y1);
                coordinates.add(coordinate);
            }else{
                double x1 = -((line.c + line.b * y1) / line.a);
                double x2 = -((line.c + line.b * y2) / line.a);
                Coordinate coordinate1 = new Coordinate(x1, y1);
                Coordinate coordinate2 = new Coordinate(x2, y2);
                coordinates.add(coordinate1);
                coordinates.add(coordinate2);
            }
        }
        return coordinates;
    }

    public boolean isInCircle(Coordinate coordinate){
        double d = Math.sqrt((coordinate.x - this.centerOfCircle.x)*(coordinate.x - this.centerOfCircle.x) +
                    (coordinate.y - this.centerOfCircle.y)*(coordinate.y - this.centerOfCircle.y));
        return Util.isDoubleEqule(d, this.r) || d < this.r;
    }
}

/**
 * 矩形类
 */
class Rectangle extends Geometry implements IntersectWithLine{
    Coordinate upperLeftCoordinate;
    Coordinate lowRightCoordinate;

    public Rectangle(Coordinate upperLeftCoordinate, Coordinate lowRightCoordinate) {
        if (upperLeftCoordinate.x >= lowRightCoordinate.x || upperLeftCoordinate.y <= lowRightCoordinate.y){
            System.out.println("左上顶点与右下顶点坐标有误，无法构成矩形");
            return;
        }
        this.upperLeftCoordinate = upperLeftCoordinate;
        this.lowRightCoordinate = lowRightCoordinate;
    }

    @Override
    public List<Coordinate> intersectWithLine(Line line) {
        List<Coordinate> coordinates = new ArrayList<>();
        if (Util.isDoubleEqule(line.a, 0.0)){
            double y = -(line.c / line.b);
            if (Util.isDoubleEqule(y, this.upperLeftCoordinate.y) || Util.isDoubleEqule(y, this.lowRightCoordinate.y)){
                System.out.println("直线与矩形的一条边重合，有无数交点");
            } else{
                coordinates.add(new Coordinate(this.lowRightCoordinate.x, y));
                coordinates.add(new Coordinate(this.upperLeftCoordinate.x, y));
            }
        } else if(Util.isDoubleEqule(line.b, 0.0)){
            double x = -(line.c / line.a);
            if (Util.isDoubleEqule(x, this.upperLeftCoordinate.x) || Util.isDoubleEqule(x, this.lowRightCoordinate.x)){
                System.out.println("直线与矩形的一条边重合，有无数交点");
            } else{
                coordinates.add(new Coordinate(x, this.lowRightCoordinate.y));
                coordinates.add(new Coordinate(x, this.upperLeftCoordinate.y));
            }
        } else{
            double x1 =  -(line.c + line.b * this.upperLeftCoordinate.y) / line.a;
            double x2 = -(line.c + line.b * this.lowRightCoordinate.y) / line.a;
            double y3 = -(line.c + line.a * this.upperLeftCoordinate.x) / line.b;
            double y4 = -(line.c + line.a * this.lowRightCoordinate.x) / line.b;

            if ((x1 > this.upperLeftCoordinate.x && x1 < this.lowRightCoordinate.x) ||
                Util.isDoubleEqule(x1, this.upperLeftCoordinate.x) || Util.isDoubleEqule(x1, this.lowRightCoordinate.x)){
                coordinates.add(new Coordinate(x1, this.upperLeftCoordinate.y));
            }
            if ((x2 > this.upperLeftCoordinate.x && x2 < this.lowRightCoordinate.x) ||
                    Util.isDoubleEqule(x2, this.upperLeftCoordinate.x) || Util.isDoubleEqule(x2, this.lowRightCoordinate.x)){
                coordinates.add(new Coordinate(x2, this.lowRightCoordinate.y));
            }
            if (y3 < this.upperLeftCoordinate.y && y3 > this.lowRightCoordinate.y){
                coordinates.add(new Coordinate(this.upperLeftCoordinate.x, y3));
            }
            if (y4 < this.upperLeftCoordinate.y && y4 > this.lowRightCoordinate.y) {
                coordinates.add(new Coordinate(this.upperLeftCoordinate.x, y4));
            }
        }
        return coordinates;
    }

    public boolean isInRectangle(Coordinate coordinate){
      return (coordinate.x > this.upperLeftCoordinate.x || Util.isDoubleEqule(this.upperLeftCoordinate.x, coordinate.x))&&
              (coordinate.x < this.lowRightCoordinate.x || Util.isDoubleEqule(this.lowRightCoordinate.x, coordinate.x)) &&
                      (coordinate.y < this.upperLeftCoordinate.x || Util.isDoubleEqule(this.upperLeftCoordinate.y, coordinate.y)) &&
                              (coordinate.y > this.lowRightCoordinate.y || Util.isDoubleEqule(this.lowRightCoordinate.y, coordinate.y));
    }

}

public class TestClass {
    public static void main(String[] args) {
        Line testLine = new Line(1.0, -1.0, 0.0);
//        Line line = new Line(1.0, 1.0, -1.0);
//        List<Coordinate> coordinateList = line.intersectWithLine(testLine);
//        if (coordinateList != null){
//            System.out.println("两直线的交点为（" + coordinateList.get(0).x + ", " + coordinateList.get(0).x + ")");
//        }

//        Coordinate coordinate = new Coordinate(0.0, 0.0);
//        Circle circle = new Circle(coordinate, 1.0);
//        List<Coordinate> coordinateList = circle.intersectWithLine(testLine);
//        if (coordinateList != null){
//            System.out.println("测试直线与此圆有" + coordinateList.size() + "个交点:");
//            for(Coordinate c : coordinateList){
//                System.out.println("(" + c.x + ", " + c.y + ")");
//            }
//        }

//        Coordinate c1 = new Coordinate(-1.0, 1.0);
//        Coordinate c2 = new Coordinate(1.0, -1.0);
//        Rectangle rectangle = new Rectangle(c1, c2);
//        List<Coordinate> coordinateList = rectangle.intersectWithLine(testLine);
//        if (coordinateList != null){
//            System.out.println("测试直线与此矩形有" + coordinateList.size() + "个交点:");
//            for(Coordinate c : coordinateList){
//                System.out.println("(" + c.x + ", " + c.y + ")");
//            }
//        }

//        Coordinate coordinate = new Coordinate(0, 0);
//        Circle circle = new Circle(coordinate, 1.0);
//        if (circle.isInCircle(coordinate)){
//            System.out.println("点（" + coordinate.x + ", " + ")在圆内");
//        }else{
//            System.out.println("点（" + coordinate.x + ", " + ")在圆外");
//        }

        Coordinate coordinate = new Coordinate(0, 0);
        Rectangle rectangle = new Rectangle(new Coordinate(0.0, 2.0), new Coordinate(1.0, 1.0));
        if (rectangle.isInRectangle(coordinate)){
            System.out.println("点（" + coordinate.x + ", " + ")在矩形内");
        } else{
            System.out.println("点（" + coordinate.x + ", " + ")在矩形外");
        }

    }

}
