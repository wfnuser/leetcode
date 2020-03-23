class DiningPhilosophers {
    private ReentrantLock[] lockList = { new ReentrantLock(), new ReentrantLock(), new ReentrantLock(),
            new ReentrantLock(), new ReentrantLock() };
    final static int PHILOSOPHER_COUNT = 5;
    private Semaphore semaphore = new Semaphore(PHILOSOPHER_COUNT - 2);

    public DiningPhilosophers() {
    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher, Runnable pickLeftFork, Runnable pickRightFork, Runnable eat,
            Runnable putLeftFork, Runnable putRightFork) throws InterruptedException {
        semaphore.acquire(1);

        lockList[philosopher % PHILOSOPHER_COUNT].lock();
        lockList[(philosopher + 1) % PHILOSOPHER_COUNT].lock();

        pickLeftFork.run();
        pickRightFork.run();

        eat.run();

        putLeftFork.run();
        putRightFork.run();

        lockList[(philosopher + 1) % PHILOSOPHER_COUNT].unlock();
        lockList[philosopher % PHILOSOPHER_COUNT].unlock();

        semaphore.release(1);
    }
}