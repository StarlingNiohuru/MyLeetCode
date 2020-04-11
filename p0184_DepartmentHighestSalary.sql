SELECT Department.Name AS Department, Employee.Name AS Employee, Salary
FROM Employee JOIN Department ON Employee.DepartmentId = Department.Id
    JOIN (SELECT DepartmentId, MAX(Salary) AS ms
        FROM Employee
        GROUP BY DepartmentId) m ON Employee.DepartmentId = m.DepartmentId
WHERE Salary=m.ms;