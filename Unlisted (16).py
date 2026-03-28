def add_student():
    name=input("Enter student name: ")
    marks=[]
    for i in range(1,4):
        m=input(f"Enter marks for subject (i): ")
        marks.append(m)
        total =sum(marks)
        avg=total/3
        student={"name":name,"marks":marks,"avg":avg}
        return student
 def height_score(students):
        top = student[0]
        for s in students:
            if s["total"]>top["total"]
                top=s
            return top
 def subject_toppers(students):
        topper=[]
        for i in range(3):
            top_student=student[0]
            for s in students:
                if s["marks"[i]>top_student["marks"][i]:]
                    top_student=s
                    toppers.append(top_student)
            return toppers
        students = []
        n =int(input("Enter number of subjects: "))
        for i in range(n):
            students.append(add_student())
        print("\n student records:")
        for s in students:
            print(s)
        top=height_score(students)
        print("\n heighest scorer")
        print(top("name")),with total[].