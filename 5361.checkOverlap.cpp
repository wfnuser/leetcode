class Solution {
public:
    
    
    bool inArea(int x, int y, int x1, int x2, int y1, int y2) {
        if (x >= x1 && x <= x2 && y >= y1 && y <= y2) return true;
        return false;
    }
    
    bool inCircle(int x, int y, int r, int xx, int yy) {
        if ((x-xx)*(x-xx) + (y-yy)*(y-yy) <= r*r) return true;
        return false;
    }
    
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int x = x_center;
        int y = y_center;
        int r = radius;
        
        if (inArea(x, y, x1, x2, y1 - r, y2 + r)) return true;
        if (inArea(x, y, x1 - r, x2 + r, y1, y2)) return true;
        
        if (inCircle(x, y, r, x1, y1) || inCircle(x, y, r, x1, y2) || inCircle(x, y, r, x2, y1) || inCircle(x, y, r, x2, y2)) return true;
        
        return false;
    }
};