//https://leetcode.com/problems/employee-importance/

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        for (int i = 0; i < employees.size(); i++){
            imp [employees[i] -> id] = employees[i];
        }
        return importance (imp[id]);
    }
    
    int importance (Employee *emp){
        int s = 0;
        for (int i : emp -> subordinates)
            s += importance(imp[i]);
        return emp -> importance + s;
    }
    
    private:
        map <int, Employee*> imp;
};
