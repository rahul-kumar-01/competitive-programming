











//#include<iostream>
//#include<string>
//using namespace std;
//
//
//
//class student{
//public:
//    string name;
//    string regNo;
//    int age;
//    int attendance;
//
//    student(){
//        string name;
//        string regNo;
//        int age;
//        this->attendance = 0;
//
//        cout<<"enter the name : ";
//        cin>>name;
//        cout<<"enter the regNo : ";
//        cin>>regNo;
//        cout<<"enter the age : ";
//        cin>>age;
//
//        this->name = name;
//        this->age = age;
//        this->regNo = regNo;
//    }
//
//};
//
//
//
//
//int totalStudent = 0;
//student ** arr = new student*[100];
//int totalNumberOfDays = 0;
//int ** modifyArr = new int*[100];
//
//
//
//void addStudent(){
//    student * s1 = new student();
//    arr[totalStudent] = s1;
//
//    ++totalStudent;
//}
//
//void studentData(){
//    for(int i=0;i<totalStudent;++i){
//        student * temp = arr[i];
//        cout<<endl;
//        cout<<"NAME : "<<temp->name<<endl;
//        cout<<"REG NO : "<<temp->regNo<<endl;
//        cout<<"AGE : "<<temp->age<<endl;
//        cout<<endl;
//    }
//    return;
//}
//
//void takeAttendance(){
//    cout<<endl;
//    int day = totalNumberOfDays;
//    cout<<"  DAY : "<<(day+1)<<endl;
//
//    cout<<"  REG NO  "<<"A/P"<<endl;
//    cout<<endl;
//    for(int i=0;i<totalStudent;++i){
//        student * temp = arr[i];
//        char c = '\0';
//        cout<<temp->regNo<<" ";
//        cin>>c;
//
//        if(c=='p' || c=='P'){
//            ++temp->attendance;
//            modifyArr[i][day+1] = 1;
//        }
//
//    }
//    ++totalNumberOfDays;
//}
//
//void viewAttendance(){
//    for(int i=0;i<totalStudent;++i){
//        student * temp = arr[i];
//        double percentage = ((double)(temp->attendance) / totalNumberOfDays) * 100;
//        if(percentage < 0){
//            percentage = 0;
//        }
//        cout<<temp->regNo<<" "<<percentage<<"%"<<endl;
//    }
//    return;
//}
//
//
//void modifyAttendance(){
//    int day;
//    cout<<"enter the day : ";
//    cin>>day;
//    for(int i=0;i<totalStudent;++i){
//        student * temp = arr[i];
//        cout<<i+1<<". "<<temp->regNo<<" "<<modifyArr[i][day]<<endl;
//    }
//    int temp;
//    cout<<"For which student which you want to modify attendance : ";
//    cin>>temp;
//    char temp2;
//    cout<<"Enter the change : ";
//    cin>>temp2;
//
//    if(temp2 == 'p' || temp2=='P'){
//        modifyArr[temp][day] = 1;
//        student * temp3= arr[temp-1];
//        ++temp3->attendance;
//
//    }
//    else if(temp2 =='a' || temp2 =='A'){
//        student * temp3= arr[temp-1];
//
//        if(temp3->attendance != 0){
//            --temp3->attendance;
//        }
//    }
//
//}
//
//int main(){
//
//    for(int i=0;i<100;++i){
//        modifyArr[i] = new int[100];
//        for(int j=0;j<100;++j){
//            modifyArr[i][j] = 0;
//        }
//    }
//
//
//    string userID = "22BCE7182";
//    string password = "rahul";
//
//    string userIdtemp;
//    string passwordtemp;
//
//    while(userID != userIdtemp || password != passwordtemp){
//        cout<<"enter the user ID : ";
//        cin>>userIdtemp;
//        cout<<"enter the passoword : ";
//        cin>>passwordtemp;
//            cout<<endl;
//
//        if(userID != userIdtemp || password != passwordtemp ){
//            cout<<"- - - - - - - - - - - - - - - "<<endl;
//            cout<<endl;
//            cout<<"SORRY YOUR CREDENTIALS IS WRONG"<<endl;
//            cout<<"PLEASE TRY AGAIN"<<endl;
//            cout<<endl;
//            cout<<"- - - - - - - - - - - - - - - "<<endl;
//            cout<<endl;
//        }
//        else{
//            break;
//        }
//
//
//        }
//
//    int action = 0;
//
//    while(action != -1){
//        cout<<endl;
//
//        cout<<" 1. ADD STUDENT DATA"<<endl;
//        cout<<" 2. SEE STUDENT DATA"<<endl;
//        cout<<" 3. TOTAL NUMBER OF STUDENT"<<endl;
//        cout<<" 4. TAKE ATTENDANCE"<<endl;
//        cout<<" 5. ATTENDANCE DETAILS"<<endl;
//        cout<<" 6. MODIFY ATTENDANCE"<<endl;
//
//
//        cout<<endl;
//
//
//        cout<<"Which action you want to perform : ";
//        cin>>action;;
//
//        if(action == -1){
//            break;
//        }
//        else if(action == 1){
//            addStudent();
//        }
//        else if(action ==2){
//            studentData();
//        }
//        else if(action ==3){
//            cout<<"Total no of student registered : "<<totalStudent<<endl;
//        }
//        else if(action ==4){
//            takeAttendance();
//        }
//        else if(action ==5){
//            viewAttendance();
//        }
//        else if(action ==6){
//            modifyAttendance();
////            cout<<"NOT AVAILABLE TILL"<<endl;
////            cout<<"SORRY FOR YOUR INCONVIENCE"<<endl;
//
//        }
//        else{
//            cout<<"enter the correct input"<<endl;
//            continue;
//        }
//        cout<<endl;
//    }
//
//    cout<<"thanks for using"<<endl;
//
//}
//
//// 22BCE7182 rahul
//// rahul 22BCE7182 18
//// garv 22BEC8172 17
//// manas 22BCE8120 17
////
//
//
//
