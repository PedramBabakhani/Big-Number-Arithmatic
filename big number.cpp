#include <iostream>
using namespace std;
 
char number1[1000];
char number2[1000];
int number1Digits = 0;
int number2Digits = 0;
char answer[1000000];
int answerDigits = 0;
char operand;

void Add(char[], char[], int, int);
void Sub(char[], char[], int, int);
void Mul(char[], char[], int, int);
void Div(char[], char[]);

int Min(int, int);
int sqr(int);
void Clear(char[], int);

int main(){
    while(true)
    {
    int index = 0;
    char temp[1000];
    Clear(temp, 1000);
    cout << "Enter Number 1 : " ;
    while(true){
                
        cin >> temp[index];
        if(temp[index] == '$'){break;} // Enter '$' at the end of the number
        index++;
    }  
    number1Digits = index-1;
    for(int i=number1Digits; i>=0; i--)
        number1[i] = temp[number1Digits - i];        
    
    
    index = 0;
    Clear(temp, 1000);
    cout << "Enter Number 2 : ";
     while(true){
                
        cin >> temp[index];
        if(temp[index] == '$'){break;} // Enter '$' at the end of the number
        index++;
    }         
    number2Digits = index -1;
    for(int i=number2Digits; i>=0; i--)
        number2[i] = temp[number2Digits - i]; 
    
    cout << "Select an operand : + - * / \n";
    cin >> operand;
    
    switch(operand){
    case '+':
         Add(number1, number2, number1Digits, number2Digits);
         break; 
    case '-':
        Sub(number1, number2 , number1Digits, number2Digits);
         break; 
    case '*':
         Mul(number1, number2 , number1Digits, number2Digits);
         break; 
    case '/':
         
         //Div(number1, number2);
         break; 
    default:
            cout << "Invalid Entry.\n";
            system ("pause");
            return 0;               
    }
    
    cout<<"\tAnswer: ";
    for(int i=0; i<=answerDigits; i++)
    cout <<answer[i];
    cout<<endl;
    system ("pause");
    system("cls");
    }
    return 0;
    
}

void Add(char num1[], char num2[], int num1Digits, int num2Digits){

     int index = 0;
     int carry = 0;
     int temp = 0;
     
     while(index <= Min(num1Digits, num2Digits)){
     
         temp = (int)(num1[index] - '0') + (int)(num2[index] - '0'); 
         temp += carry;
                  
         if(temp/10 > 0){ // agar adad 2 raghami bod           
             
             carry = 1;
             temp = temp % 10;       
         }
         else{
              
              carry = 0;
         }
         
         answer[index] = (char)(temp + '0');
         index++;
     }
     
     if(num1Digits == num2Digits){
                   if(carry == 0){
                            
                        answerDigits = index-1; 
                   }
                   else{
                        answer[index] = '1';
                        answerDigits = index;
                        carry = 0;     
                   }}
     else if (num1Digits == Min(num1Digits, num2Digits)){
        
        int i=index;
        for(; i<=num2Digits; i++){
              
            temp = (int)(num2[i] - '0') + carry;
            if(temp/10 > 0){ // agar adad 2 raghami bod           
             
                carry = 1;
                temp = temp % 10;       
            }
            else{
              
               carry = 0;
            }
         
            answer[i] = (char)(temp + '0');
         }
         answerDigits = i-1; 
     }
     else{
        
       int i=index;
        for(; i<=num1Digits; i++){
              
            temp = (int)(num1[i] - '0') + carry;
            if(temp/10 > 0){ // agar adad 2 raghami bod           
             
                carry = 1;
                temp = temp % 10;       
            }
            else{
              
               carry = 0;
            }
         
            answer[i] = (char)(temp + '0');
         }
         answerDigits = i-1; 
     }
     
     if(carry == 1){
            
         answerDigits++;     
         answer[answerDigits] = '1';
     }
     
     int temp2[10000];
     for(int j=0; j<=answerDigits; j++)
         temp2[j] = answer[j];
     
     for(int j=answerDigits; j>=0; j--)
        answer[j] = temp2[answerDigits - j];
          
}
void Sub(char numb1[], char numb2[], int num1Digits, int num2Digits){

     int index = 0;
     int carry = 0;
     int temp = 0;

     Clear(answer, 1000000);
     
     while(index <= num2Digits){
     
         temp = (int)(numb1[index] - '0') - (int)(numb2[index] - '0'); 
         temp += carry;
                  
         if(temp < 0){        
             
             carry = -1;
             temp = temp + 10;       
         }
         else{
              
              carry = 0;
         }
         answer[index] = (char)(temp + '0');
         index++;
     }
     
        for(int i= index; i<=num1Digits; i++){
              
            temp = (int)(numb1[i] - '0') + carry;
            if(temp< 0){       
             
                carry = -1;
                temp = temp + 10;       
            }
            else{
              
               carry = 0;
            }
         
            answer[i] = (char)(temp + '0');
         }
         answerDigits = index+1;
     
     int temp2[1000];
     
     for(int j=0 ; j<= answerDigits ; j++)
         temp2[j] = answer[j];
     
     for(int j=answerDigits; j>=0; j--)
        answer[j] = temp2[answerDigits - j];

}

void Mul(char numb1[], char numb2[], int num1Digits, int num2Digits){
     int index = 0;
     int carry = 0;
     int temp = 0;
     char temp1[1000];
        
     Clear(answer, 1000000);
     char temp2[1000];
     Clear(temp2,1000);   
     while(index <= num2Digits){
          int t = ((int)(numb2[index] - '0'))* pow(10,index);
          cout<< pow(10,index)<<endl;
          for( int i=0 ; i<t ; i++)
          {
              Add(answer,numb1,answerDigits,num1Digits);
              for(int j=0; j<=answerDigits; j++)
                      temp2[j] = answer[j];
              for(int j=answerDigits; j>=0; j--)
                      answer[j] = temp2[answerDigits-j];
              
          }
          for(int k=answerDigits; k>=0; k--)
                      cout << answer[k];
              cout<<endl;
          Clear(answer, 1000000);
          index++;
     }

      //    if(num2Digits==0)
       //   {
         for(int j=0; j<=answerDigits; j++)
         temp2[j] = answer[j];
     
         for(int j=answerDigits; j>=0; j--)
         answer[j] = temp2[answerDigits - j];
         // }
        // else
         //{
         // Add(answer,numb1,answerDigits,num1Digits);
         //}
          


}
void Div(char[], char[]){
     
}

int Min(int a, int b){
    
    if(a < b)
         return a;
    return b; 
}

void Clear(char array[], int length){
     
     for(int i=0 ; i<length; i++)
        array[i] = '0';    
}
