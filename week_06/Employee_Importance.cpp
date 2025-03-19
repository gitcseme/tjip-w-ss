class Solution {
private:
    unordered_map<int, Employee*> idToEmpMap;
    int calcImportance(int id) {
        auto emp = idToEmpMap[id];
        int impSum = emp -> importance;

        for (auto subOrdId : emp -> subordinates) {
            impSum += calcImportance(subOrdId);
        }
        return impSum;
    }

public:
    int getImportance(vector<Employee*> employees, int id) {
        idToEmpMap.clear();

        for (auto &emp : employees) {
            idToEmpMap[emp -> id] = emp;
        }

        return calcImportance(id);
    }
};
