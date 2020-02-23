class Foo {

    public int lockF = 0;
    public int lockS = 0;

    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        lockF = 1;
    }

    public void second(Runnable printSecond) throws InterruptedException {
        
        // printSecond.run() outputs "second". Do not change or remove this line.
        while(lockF == 0) {
        }
        printSecond.run();
        lockS = 1;
    }

    public void third(Runnable printThird) throws InterruptedException {
        
        // printThird.run() outputs "third". Do not change or remove this line.
        while(lockF == 0) {
        }
        while(lockS == 0) {
        }
        printThird.run();
    }
}