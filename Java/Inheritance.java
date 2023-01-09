// inheritance example

class Animal {
    void eat(){
        System.out.println("Eating");
    }
}

class Dog extends Animal{
    void bark(){
        System.out.println("Barking");
    }    
}

class Cat extends Animal{
    void meow(){
        System.out.println("Meow,',");
    }    
}

class Pug extends Dog{
    void name(){
        String name = "Puggy";
        System.out.println(name);
        bark();
    }    
}


/**
 * Inheritance
 */

public class Inheritance {
    public static void main(String[] args) {
        Dog bunzo = new Dog();
        bunzo.bark();
        bunzo.eat();
        Cat kitty = new Cat();
        kitty.meow();
        kitty.eat();
        Pug puggy = new Pug();
        puggy.name();
        // cat.bark(); ----> will give error
    }
}
