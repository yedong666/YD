package JavaPractise.AnimalSimulation;

public class TestMain {
    public static void main(String[] args){
        Simnlation animal_simnlation = new Simnlation();
        animal_simnlation.playSound(new Dog());
        animal_simnlation.playSound(new Cat()); 
    }
}
