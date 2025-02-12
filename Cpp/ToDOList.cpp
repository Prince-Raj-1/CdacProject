#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

void displayTask()
{
    ifstream file("tasks.txt");
    if(!file){
        cout<<"No tasks found. Start adding tasks!\n";
        return;
    }
string task;
int count =1;
cout<<"\n===== Your TO-Do List =====\n";
while(getline(file, task)) {
    cout << count++ <<"."<<task<<endl;
}
file.close();
}


void addTask() {
    ofstream file("tasks.txt", ios::app);
    string task;

    cout<<"Enter your task: ";
    cin.ignore();
    getline(cin , task);

    file<< task << endl;
    file.close();
    cout<<"Task added successfully\n";
}

void deleteTask() {
    ifstream file("tasks.txt");
    if(!file) {
        cout<<"NO task to delete!\n";
        return ;
    }

    vector<string> tasks;
    string task;
    int taskNumber;

    while(getline(file, task)) {
        tasks.push_back(task);
    }
    file.close();

    if(tasks.empty())
    {
        cout<<"No tasks available.\n";
        return;
    }

    displayTask();

    cout<<"Enter the task number to delete";

    cin>>taskNumber;

    if(taskNumber < 1 || taskNumber > tasks.size()) {
        cout<< "Invalid task number!\n";
        return;
    }

    ofstream outFile("tasks.txt");
    for(int i = 0; i < tasks.size(); i++) {
        if(i + 1 != taskNumber) {
            outFile << tasks[i] << endl;
        }
    }
    outFile.close();

    cout<< "Task deleted successfully!\n";
}


int main(){

    int choice ;
    do{
        cout<<"\n=======TO-Do List======="<<endl;
        cout<<"1. View Tasks "<<endl;
        cout<<"2. Add Task "<<endl;
        cout<<"3. Delete Task"<<endl;
        cout<<"4. Exit "<<endl;
        cout<<" Enter your choice: "<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            displayTask();
            break;
        case 2:
            addTask();
            break;
        case 3:
            deleteTask();
            break;
        case 4:
            cout<<"Exiting program....."<<endl;
            break;
        
        default:
        cout<<"Invalid choice. Try Better one!"<<endl;
            break;
        }
    }while(choice !=4);



    return 0;
}