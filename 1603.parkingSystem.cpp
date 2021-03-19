class ParkingSystem {
public:
    int b;
    int m;
    int s;

    ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium;
        s = small;
    }
    
    bool addCar(int carType) {
        switch (carType) {
            case 1: 
                if (b <= 0) return false;
                b--;
                break;
            case 2: 
                if (m <= 0) return false;
                m--;
                break;
            case 3: 
                if (s <= 0) return false;
                s--;
                break;
        }
        return true;
    }
};