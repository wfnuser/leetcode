class FooBar {
    private int n;

    public FooBar(int n) {
        this.n = n;
    }

    Semaphore Foo = new Semaphore(1);
    Semaphore Bar = new Semaphore(0);


    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            Foo.acquire();
        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	printFoo.run();
            Bar.release();

        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            Bar.acquire();
            // printBar.run() outputs "bar". Do not change or remove this line.
        	printBar.run();
            Foo.release();
        }
    }
}