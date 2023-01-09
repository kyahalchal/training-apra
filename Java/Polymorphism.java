class Animal {

    int speed = 60;
    void eat(){
        System.out.println("Animal Eating");
    }
}

class Dog extends Animal{
    int speed = 15;
    void eat(){
        System.out.println("Dog eating");
    }    
}

public class Polymorphism {
    public static void main(String[] args) {
      Animal fox = new Animal();
      fox.eat();
      System.out.println(fox.speed);

      Dog dog = new Dog();
      dog.eat();
      System.out.println(dog.speed);

      Animal foxDog = new Dog();
      foxDog.eat();
      System.out.println(foxDog.speed);
    }    
}
