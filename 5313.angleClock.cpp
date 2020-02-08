class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angleH = 0;
        double angleM = 0;
        
        hour = hour % 12;
        angleH = hour * 360 / 12.0;
        angleM = minutes * 360 / 60.0;
        angleH += (360/12)*minutes/60.0;
        
        double d = abs(angleM - angleH);
        
        return min(d, 360-d);
    }
};