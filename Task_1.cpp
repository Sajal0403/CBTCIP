#include<iostream>
#include<string>
#include<vector>
using namespace std;


class students{
    private:
      int rollno;
      string Name;
      char Section;
      bool isStudentPass;
    public:
      students( int stdRollno, string stdName, char stdSection, bool stdPass){
         rollno = stdRollno;
         Name = stdName;
         Section = stdSection;
         isStudentPass = stdPass;
      }
      void setRollno(int stdRollno){
        rollno = stdRollno;
      }
      int getRollno(){
        return rollno;
      }
      void setName(string stdName){
        Name = stdName;
      }
      string getName(){
        return Name;
      }
      void setSection(char stdSection){
        Section = stdSection;
      }
      char getSection(){
        return Section;
      }
      void setIsStudentPass(bool stdPass){
        isStudentPass = stdPass;
      }
      bool getIsStudentPass(){
        return isStudentPass;
      }
      void displayStudent(){
        cout<<"Roll no : "<<rollno<<endl;
        cout<<"Name : "<<Name<<endl;
        cout<<"Section : "<<Section<<endl;
        cout<<"Is Student Pass? : "<<isStudentPass<<endl;
      }
};

void updateStudent(vector<students> &student){
   string sName;
   bool found = false;
   int choice;

   cout<<"\t\tEnter Name to update Record :";
   cin.ignore();
   getline(cin,sName);
   for(int i=0; i<student.size();i++){
     if(student[i].getName()==sName){
      found = true;
      cout<<"\t\t...Student Found....."<<endl;
      cout<<"t\t....Update Rollno "<<endl;
      cout<<"\t\t...Update Name..."<<endl;
      cout<<"\t\t...Update Section..."<<endl;
      cout<<"\t\t...Update Is student Pass.."<<endl;
      cout<<"\t\tEnter your choice :";
      cin>>choice;
       
       switch(choice){
        case 1:{
          int rno;
          cout<<"\t\tEnter new Rollno :";
          cin>>rno;
          student[i].setRollno(rno);
          break;
        }
        case 2:{
          string nm;
          cout<<"\t\tEnter new Name :";
          cin.ignore();
          getline(cin,nm); 
          student[i].setName(nm);
          break;
        }
        case 3:{
          char s;
          cout<<"t\tEnter new Section :";
          cin>>s;
          student[i].setSection(s);
          break;
        }
        case 4:{
          bool I;
          cout<<"t\tEnter new status :";
          cin>>I;
          student[i].setIsStudentPass(I);
          break;
        }
        default:
        cout<<"t\tInvalid no.";
       }
     }

     if(!found) {
       cout<<"\t\t....Record not found.... "<<endl;
       return;
     }
     
   }
}

void displayAllStudent(vector<students>& student){
   if(student.empty()){
    cout<<"t\t No student found"<<endl;
    return;
   }
   for(int i= 0; i<student.size();i++){
       student[i].displayStudent();
       cout<<endl;
   }
}

void addNewStudent(vector<students> &student){
  int rollno;
  string Name;
  char Section;
  bool isStudentPass;

  for(int i = 0;i<student.size();i++ ){
     if(student[i].getRollno()==rollno){
      cout<<"\t\t Student already registered";
      return; 
     } 
  }
  cout<<"Enter Student rollno: ";
  cin>>rollno;
  cout<<"Enter Name: ";
  cin>>Name;
  cout<<"Enter Section: ";
  cin>>Section;
  cout<<"Is Student Pass? (True/False) ";
  cin>>isStudentPass;

  students newStudent( rollno,Name,Section,isStudentPass);
  student.push_back(newStudent);
  cout<<"\t\t Student added successfully....."<<endl;

}
void searchStudent(vector<students> &student){
  int rollno;
  cout<<"\t\tEnter rollno :";
  cin>>rollno;
  for(int i = 0; i<student.size();i++){
    if(student[i].getRollno()==rollno){
      cout<<"\t\t......Student Found........"<<endl;
      student[i].displayStudent();
      return;
    }
  }
}
void deleteStudent(vector<students> &student){
   string Name;
   cout<<"Enter name to delete :";
   cin.ignore();
   getline(cin,Name);
   for(int i=0;i<student.size();i++){
    if(student[i].getName()==Name){
      student.erase((student.begin()+1));
      cout<<"\t\tStudent removed successfully"<<endl;
    }
   }
}
int main()
{
  vector<students> student;
  student.push_back(students(01,"Anu",'A',"True"));

  char choice;

  do{
  system("cls");  
  int op;
  cout<<"\t\t......................."<<endl;
  cout<<" 1. Add new student"<<endl;
  cout<<" 2. Display All students"<<endl;
  cout<<" 3. Search students"<<endl;
  cout<<" 4. Update student"<<endl;
  cout<<" 5. Delete student"<<endl;
  cout<<" 6. Exit"<<endl;
  cout<< "Enter your Choice"<<endl;
  cin>>op;

  if(op==1){
        addNewStudent(student); 
  }
  else if(op==2){
    displayAllStudent(student);
  }
  else if (op==3)
  {
    searchStudent(student);
  }
  else if (op==4){
    updateStudent(student);
  }
  else if(op==5){
    deleteStudent(student);
  }
  
  else 
  {
     cout<<" \t\tInvalid Number ..... "<<endl; 
  }
   cout<<"\t\tDo you want to continue [ Yes/ N0]  :?";
   cin>>choice;
  

}while(choice=='Y' || choice=='y');


}


