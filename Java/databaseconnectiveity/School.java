package com.company;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.Scanner;

class School {
    private Connection con;

    {
        con = null;
    }

    int exitCode=0;
    private static Scanner in;

    static {
        in = new Scanner(System.in);
    }

    private void performOperation(String sql, String action) {
        try {
            DriverManager.registerDriver(new oracle.jdbc.OracleDriver());
            con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:orcl","kevin_admin","admin");
            Statement st = con.createStatement();
            if(action.equals("display")) {
                ResultSet rs=st.executeQuery(sql);
                System.out.println("RollNo      Name        GPA");
                while(rs.next()) {
                    System.out.println(rs.getInt("rollno")+"        "+rs.getString("student_name")+"        "+rs.getString("gpa"));
                }
            } else {
                int m = st.executeUpdate(sql);
                if (m == 1)
                    System.out.println(action+" successfully : "+sql);
                else
                    System.out.println(action+" failed");
            }
            con.close();
        } catch(Exception ex) {
            System.err.println(ex);
        }
    }

    void choice() {
        int choice;
        System.out.println("Enter 1 to add a new Student\nEnter 2 to update a student's details\nEnter 3 to remove a student\nEnter 4 to display list of student details\nEnter -1 to exit");
        choice=in.nextInt();
        switch(choice) {
            case 1:
                performOperation(newStudent(),"Insertion");
                break;
            case 2:
                performOperation(updateStudent(),"Updation");
                break;
            case 3:
                performOperation(removeStudent(),"Deletion");
                break;
            case 4:
                performOperation("select * from student","display");
                break;
            case -1:
                this.exitCode=-1;
                break;
            default:
                System.out.println("Try again");
        }
    }

    private String newStudent() {
        System.out.println("Enter details of the student\nEnter rollNo");
        int roll=in.nextInt();
        System.out.println("Enter Name");
        String name=in.next();
        System.out.println("Enter GPA of student");
        String gpa=in.next();
        return "insert into student values("+roll+",'"+name+"','"+gpa+"')";
    }

    private String updateStudent() {
        System.out.println("Enter the roll of student to be updated");
        int roll=in.nextInt();
        System.out.println("What would you like to update of the student gpa,name?");
        String choice=in.next();
        if(choice.equals("name")) choice="student_name";
        System.out.println("Enter the new value of "+choice);
        String newVal=in.next();
        return "update student set "+choice+"='"+newVal+"' where rollno="+roll;
    }

    private String removeStudent() {
        System.out.println("Enter the rollno of student to be removed");
        int roll=in.nextInt();
        return "delete from student where rollno="+roll;
    }
}
