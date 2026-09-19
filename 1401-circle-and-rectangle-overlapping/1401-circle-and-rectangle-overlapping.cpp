class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // finding closest x and y coordinates of rectangle from the circle
        // basically keep the centre inside the circle
        int x = max(x1, min(xCenter, x2));
        int y = max(y1, min(yCenter, y2));
        // distance from centre of circle
        int dx = xCenter - x;
        int dy = yCenter - y;

        return dx * dx + dy * dy <= radius * radius;
    }
};