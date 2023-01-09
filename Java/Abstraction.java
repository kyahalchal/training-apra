interface I {
    void a();
    void b();
    void c();
    void d();
}

abstract class A implements I{
    public void c(){
        System.out.println("This is c");
    }
}


class B extends A{
    public void a(){
        System.out.println("This is a");
    }
    public void b(){
        System.out.println("This is b");
    }
    public void d(){
        System.out.println("This is d");
    }   
}


public class Abstraction {
    public static void main(String[] args) {
        I obj = new B();
        obj.a();
        obj.b();
        obj.c();
        obj.d();
    }
}