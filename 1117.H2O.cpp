class H2O {

    private Semaphore semaphoreH = new Semaphore(2);
    private Semaphore semaphoreO = new Semaphore(1);

    private CyclicBarrier barrier = new CyclicBarrier(3, new Runnable() {
        @Override
        public void run() {
            semaphoreH.release(2);
            semaphoreO.release();
        }
    });

    public H2O() {
        
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        semaphoreH.acquire();
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();

        try {
            barrier.await();
        } catch (Exception e) {

        }
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        semaphoreO.acquire();

        // releaseOxygen.run() outputs "O". Do not change or remove this line.
		releaseOxygen.run();
        try {
            barrier.await();
        } catch (Exception e) {
            
        }
    }
}