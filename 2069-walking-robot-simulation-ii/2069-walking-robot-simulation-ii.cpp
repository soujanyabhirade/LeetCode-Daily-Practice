class Robot {
public:
    int w, h;
    long long x = 0, y = 0;
    int dir = 1; // 0=N, 1=E, 2=S, 3=W

    Robot(int width, int height) {
        w = width;
        h = height;
    }

    void step(int num) {
        long long perimeter = 2LL * (w + h - 2);

        // Special case:
        // At the initial position, a complete cycle ends at
        // (0,0) facing South.
        if (x == 0 && y == 0 && dir == 1 && num >= perimeter) {
            num %= perimeter;

            if (num == 0) {
                dir = 2; // South
                return;
            }
        } else {
            num %= perimeter;
        }

        while (num > 0) {

            if (dir == 1) { // East
                long long d = (w - 1) - x;

                if (num <= d) {
                    x += num;
                    num = 0;
                } else {
                    x = w - 1;
                    num -= d;
                    dir = 0; // North
                }
            }

            else if (dir == 0) { // North
                long long d = (h - 1) - y;

                if (num <= d) {
                    y += num;
                    num = 0;
                } else {
                    y = h - 1;
                    num -= d;
                    dir = 3; // West
                }
            }

            else if (dir == 3) { // West
                long long d = x;

                if (num <= d) {
                    x -= num;
                    num = 0;
                } else {
                    x = 0;
                    num -= d;
                    dir = 2; // South
                }
            }

            else { // South
                long long d = y;

                if (num <= d) {
                    y -= num;
                    num = 0;
                } else {
                    y = 0;
                    num -= d;
                    dir = 1; // East
                }
            }
        }
    }

    vector<int> getPos() {
        return {(int)x, (int)y};
    }

    string getDir() {
        if (dir == 0) return "North";
        if (dir == 1) return "East";
        if (dir == 2) return "South";
        return "West";
    }
};