class Solution {
public:
    vector<int> dirx = { -1,  0, +1,  0};
    vector<int> diry = {  0, +1,  0, -1};
    unordered_map<int, bool> visited;

    void moveBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    void clean(Robot& robot, int x, int y, int curDir) {
        robot.clean();
        visited[(1000 * x + y)] = true;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dirx[curDir];
            int ny = y + diry[curDir];

            if (visited.count((1000 * nx + ny)) == 0 && robot.move()) {
                clean(robot, nx, ny, curDir);
                moveBack(robot);
            }

            robot.turnRight();
            curDir = (curDir + 1) % 4;
        }
    }

    void cleanRoom(Robot& robot) {
        clean(robot, 0, 0, 0);
    }
};
