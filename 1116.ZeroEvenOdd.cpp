class ZeroEvenOdd {
    private int n;
    private int i = 1;
    
    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    Semaphore Zero = new Semaphore(1);
    Semaphore One = new Semaphore(0);
    Semaphore Two = new Semaphore(0);

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            Zero.acquire();
            printNumber.accept(0);
            if (i % 2 == 1) {
                One.release();
            } else {
                Two.release();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n; i += 2) {
            Two.acquire();
            printNumber.accept(i);
            Zero.release();
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i += 2) {
            One.acquire();
            printNumber.accept(i);
            Zero.release();
        }
    }
}