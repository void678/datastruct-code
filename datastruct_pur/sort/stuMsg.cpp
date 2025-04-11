#include<iostream>
#include<string>
#include<vector>
using namespace std; 


const int LIMS = 100;
const int LINC = 10;


typedef struct student{

    int id;
    string name;
    int score;
}STUDENT;


typedef struct{

    STUDENT *stu;
    
    int length;
    int listsize;
    int incrementsize;

}List;



//构造一个空的线性表L
void InitList(List &L){

    L.stu=new STUDENT[LIMS];
    L.length=0;
    L.listsize=LIMS;
    L.incrementsize=LINC;

}


//在L的第i个元素之前插入新的元素e，L的长度增1
bool ListInsert(List &L,int i,STUDENT stu){

    if(i<1||i>L.length+1||L.length>=L.listsize){                 //xy
        return false;
    }
    for(int k=L.length;k>=i;k--){
        L.stu[k]=L.stu[k-1];
    }
    L.stu[i-1]=stu;
    L.length++;
    return true;

}

void readStuMsg(List &L,int n){

    cout << "请输入学生数量: ";
    cin>>n;
    for(int i=0;i<n;i++){
        STUDENT stu;
        cout << "请输入第 " << (i + 1) << " 个学生的学号: ";
        cin >> stu.id;
        cout << "请输入第 " << (i + 1) << " 个学生的姓名: ";
        cin >> stu.name;
        cout << "请输入第 " << (i + 1) << " 个学生的成绩: ";
        cin >> stu.score;
        ListInsert(L,i+1,stu);
    }

}



void countingSortByDigit(STUDENT *stu,int n,int exp){

    STUDENT arr[n];
    int count[10]={0};

    for(int i=0;i<n;i++){
        count[(stu[i].score/exp)%10]++;
    }

    for(int i=8;i>=0;i--){
        count[i]+=count[i+1];
    }

    for(int i=n-1;i>=0;i--){
        arr[count[(stu[i].score/exp)%10]-1]=stu[i];
        count[(stu[i].score/exp)%10]--;
    }
    
    for(int i=0;i<n;i++)
        stu[i]=arr[i];

    
}


void countingSortByDigitSub(STUDENT *stu,int n,int exp){

    STUDENT arr[n];
    int count[10]={0};

    for(int i=0;i<n;i++){
        count[(stu[i].score/exp)%10]++;
    }

    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }

    for(int i=n-1;i>=0;i--){
        arr[count[(stu[i].score/exp)%10]-1]=stu[i];
        count[(stu[i].score/exp)%10]--;
    }
    
    for(int i=0;i<n;i++)
        stu[i]=arr[i];

    
}


void radixSort(STUDENT *a,int n){

    int maxScore=a[0].score;
    for(int i=1;i<n;i++){
        if(a[i].score>maxScore) 
            maxScore=a[i].score;
    }
    
    for(int exp=1;maxScore/exp>0;exp*=10){
        countingSortByDigit(a,n,exp);
        //countingSortByDigitSub(a,n,exp);

    }
    
}


int main(){


    List STU;
    InitList(STU);
    int stusnum;
   
    readStuMsg(STU,stusnum);

    radixSort(STU.stu,STU.length);
    

    cout << "\n所有学生记录:\n";
    printf("名次    学号     姓名  成绩\n");

    for (int i = 0; i < STU.length; ++i) {
        cout << i+1 <<"     "
             << STU.stu[i].id <<"      "
             << STU.stu[i].name <<"  "
             << STU.stu[i].score << endl;
    }

}