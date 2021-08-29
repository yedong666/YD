package JavaPractise.Studnets;

public class universtudents extends students{
    boolean ismarray;
    universtudents(int number, String name, boolean yesorno){
        super(number, name);
        ismarray = yesorno;
        System.out.println("»é·ñ=" + yesorno);
    }
}
